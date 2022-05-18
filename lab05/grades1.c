#include<stdio.h>
#define STUDENT 100  // CONSTANT

int main() {
  float marks[STUDENT], sum = 0;
  int i;

  for (i = 0; i < STUDENT; i++) {
    printf("Enter marks for %d student: ", i+1);
    scanf("%f", &marks[i]);
  }

  // calculate sum

  for (i = 0; i < STUDENT; i++) {
    sum += marks[i];
  }

  printf("\nAverage marks = %.2f\n", sum/STUDENT);

  // signal to operating system everything works fine
  return 0;
}
