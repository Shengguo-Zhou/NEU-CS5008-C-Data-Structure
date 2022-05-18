#include<stdio.h>

void PrintRectangle(int width, int height) {
	int i = 0, j = 0;

	// fist line of dash
	for(i = 0; i < width; i++){
		printf("-");
	}

	printf("\n");

	// the second line to height - 1 line
	for(i = 0; i < height - 2; i++){
		printf("-");
		for(j = 0; j < width - 2; j++){
			printf(" ");
		}
		printf("-");
                printf("\n");

	}

	// the last line
	for(i = 0; i < width; i++){
                printf("-");
        }
	printf("\n");
}


int main(){
	PrintRectangle(5, 4);
	return 0;	
}

