#include<stdio.h>

void PrintRectangle(int width, int height, char symbol) {
        int i = 0, j = 0;
        // fist line of dash
        for(i = 0; i < width; i++){
        	printf("%c", symbol);  
        }
        printf("\n");
        // the second line to height - 1 line
        for(i = 0; i < height - 2; i++){
	        printf("%c", symbol);
		for(j = 0; j < width - 2;j++){
			printf(" ");
		}
		printf("%c", symbol);
		printf("\n");
		}
	// the last line
	for(i = 0; i < width; i++){
                printf("%c", symbol);
        }
        printf("\n");
}

void PrintFancyRectangle(int width, int height, char symbol, int fill) {
        if(fill == 0){
                PrintRectangle(width, height, symbol);
        }
        else{
                int i = 0, j = 0;
                for(j = 0; j < height; j++){
                        for(i = 0; i < width; i++)
                                printf("%c", symbol);
                        printf("\n");
                }
        }
}

int main(){
	PrintFancyRectangle(5, 4, '+', 0);
	printf("\n");
	PrintFancyRectangle(5, 4,'*', 1);
	return 0;
}
