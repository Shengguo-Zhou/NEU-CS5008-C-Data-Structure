#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>

#define MAX_LEN 256
#define LENGTH 1200
#define MAX_NUM_RESULTS 100

int next_value_to_print = 0; 
// Array of indices of target number 
int results[MAX_NUM_RESULTS]; 
// Number of results we have so far
int num_results = 0; 
int mIndex = 0; // result index

int inputArray[LENGTH];
int arrayindex = 0;
char *filename;
int target;// Number to be found
int thread_number;

pthread_mutex_t lock;
sem_t semaphore;
pthread_t* threads; 


void* DoSearch(int index, int length) {
	int n;
	printf("StartIndex: %d, EndIndex : %d\n", index * length, index * length + length);
	for(n = index * length; n < index * length + length; n++){
		if(inputArray[n] == target){
			results[mIndex++] = target;
		}
	}
	printf("Do Search Function Round %d\n", index + 1);
	return NULL;
}

// read the file. 
void ReadFile(FILE* fp) {
	fp = fopen(filename, "r");
    if (fp == NULL) {
      perror("Failed: ");
      return;
    }

    char buffer[MAX_LEN];
	int index = 0;
	int temp = 0;
    while (fgets(buffer, MAX_LEN, fp)){
        // Remove trailing newline
        // buffer[strcspn(buffer, "\n")] = 0;
		
		for(index = 0; buffer[index] != '\0'; index++){
			if(buffer[index] == '\n'){
				inputArray[arrayindex] = temp;
				arrayindex++;
				temp = 0;
			}
			else{
				temp = temp * 10 + buffer[index] - 48;
			}
		}
    }
    fclose(fp);
    return;
}

void PrintResults() {
	int i;
	if(mIndex == 0) printf("We didn't find the number\n");
	else 
		for(i = 0; i < mIndex; i++)
			printf("The result we found is %d\n", results[i]);
}

void *exThreadFunctionWithSem(void *arg)
{
  int indent = *(int *)arg;
  char* message = malloc(128);
  if (message == NULL) {
    printf("ERROR: could not malloc\n");
    return NULL;
  }

  while(1) {
    sleep(1); // try to yield to other threads
    sem_wait(&semaphore); // wait for the semaphore
    // If it's this threads turn, then print it's ID
    if (next_value_to_print == indent) {
      break;
    }
    // If it's not our time, release the semaphore and keep waiting
    sem_post(&semaphore);
  }

  DoSearch(indent, arrayindex / thread_number);
  // printf("indent %d\n", indent);
  sprintf(message, "Thread No.%d", indent);
  printf("%*s\n", indent + strlen(message), message);

  next_value_to_print++;
  sem_post(&semaphore);
  free(message);

  return NULL;
}

void run_8_threads_with_sem() {
  pthread_t thread_id[thread_number];
  int args[thread_number];

  printf("About to spawn threads\n");
  int i = 0;
  for(i = 0; i < thread_number; i++) {
    printf("Starting thread %d\n", i);
    args[i] = i;
    pthread_create(&thread_id[i], NULL, exThreadFunctionWithSem, &args[i]);
  }
  i = 0;
  for(i = 0; i < thread_number; i++) {
    pthread_join(thread_id[i], NULL);
  }
  printf("Threads have joined\n");
}

int getNumber(char* args){

	char buffer[MAX_LEN];
	int index = 0;
	int temp = 0;

	for(index = 0; args[index] != '\0'; index++){
		temp = temp * 10 + args[index] - 48;
	}
	
	return temp;
}


int main(int num_args, char* args[]) {
	filename = args[1];
	target = getNumber(args[2]);
	printf("target is %d\n", target);
	thread_number = getNumber(args[3]);
	printf("thread_number is %d\n", thread_number);
	// int num_line = (int) args[3];
	// filename = "inputs/nums10000.txt";
	// target = 6666; // can not find
	// target = 18; // can be found
	// thread_number = 7;
	
	FILE* fp;
	ReadFile(fp);
	
	int count = 0;
	for(count = 0; count < arrayindex; count++){
		printf("input array is %d\n", inputArray[count]);
	}
	sem_init(&semaphore, 0, 1);

	run_8_threads_with_sem();

	sem_destroy(&semaphore);	

	PrintResults();
	
	exit(0);

}
