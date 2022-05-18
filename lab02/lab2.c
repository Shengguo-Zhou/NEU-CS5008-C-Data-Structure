#include<stdio.h>
#include<string.h>

/**
 *  * Write a function that replaces all numbers greater
 *   * than ceiling in arr with ceiling.
 *    *
 *     * Precondition(s):
 *      * - len > 0 (i.e. arrays MUST have at least one element)
 *       *
 *        * Example(s):
 *         * - crop_hi([1, 2, 3, 4], 4, 2) :: [1, 2, 2, 2]
 *          * - crop_hi([-3, 17,  7, -12, 10], 5, 8) :: [-3, 8, 7, -12, 8]
 *           *
 *            * @param arr     array of integers
 *             * @param len     length of arr
 * * @param ceiling upper limit for ints in array
 * */
void crop_hi(int* arr, int len, int ceiling){
	int i = 0;
	for(i = 0; i < len; i++){
		if(arr[i] > ceiling) arr[i] = ceiling;
	}
}

/**
 *  * Swaps the the last int in arr with the middle element in arr.
 *   *
 *    * Precondition(s):
 *     * - len > 0 (i.e. arrays MUST have at least one element)
 *      *
 *       * Example(s):
 *        * - swap_mid_back([1, 2, 3], 3) :: [1, 3, 2]
 *         * - swap_mid_back([-4, 3, 0, 1], 4) :: [-4, 1, 0, 3]
 *          *
 *           * @param arr array of integers
 *            * @param len length of arr
 *             */
void swap_mid_back(int* arr, int len){
	int temp = arr[len / 2];
	arr[len / 2] = arr[len - 1];
	arr[len - 1] = temp;
}


/**
 *  * Replaces all digits in a string with a '*'. 
 *   *
 *    *
 *     * Example(s):
 *      * - redact("The part failed 58% of the time") ::
 *       *          "The part failed **% of the time"
 *        * - redact("There were 13 As in the class") :: "There were ** As in the class"
 *         *
 *          * @param  str      host string for old_char
 *           */
void redact(char* str){
	int i  = 0;	
	for(i = 0; i < strlen(str); i++){
		if(str[i] >= '0' && str[i] <= '9')
		str[i] = '*';
	}
}



int main(){
	int i = 0;
	int arr[4] = {1, 2, 3, 4}; 
	for(i = 0; i < 4; i++){printf("%d ", arr[i]);}
	printf("\n");
	crop_hi(arr, 4, 2);
	for(i = 0; i < 4; i++){printf("%d ", arr[i]);}
	
	printf("\n");
        int arr2[5] = {1, 2, 3, 4, 5};
	for(i = 0; i < 5; i++){printf("%d ", arr2[i]);}
	printf("\n");        
	swap_mid_back(arr2, 5);
        for(i = 0; i < 5; i++){printf("%d ", arr2[i]);}
	
	printf("\n");
	char str[] = "The part failed 58% of the time";
	printf("%s\n", str);
	redact(str);
	printf("%s\n", str);

	return 0;
}







