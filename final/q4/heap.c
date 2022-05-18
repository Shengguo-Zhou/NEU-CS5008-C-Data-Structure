#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void heapify(int* arr, int size, int index) {
    int high = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] > arr[high])
        high = left;

    if (right < size && arr[right] > arr[high])
        high = right;
    if (high != index) {
        int temp = arr[index];
        arr[index] = arr[high];
        arr[high] = temp;
        heapify(arr, size, high);
    }
}

void buildHeap(int* arr, int n) {
    int start = (n / 2) - 1;
    int i;
    for (i = start; i >= 0; i--) {
        heapify(arr, n, i);
    }
}



void print(int* arr, int size) {
    int i;
    printf("[");
    for (i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
    printf("]\n");
}

void peek(int* heap) {
    printf("PEEK: %d\n", heap[0]);
}

bool isValidHeap(int* arr) {
    return true;
}

bool isValidMaxHeap(int* arr, int size) {
    int end = (size / 2) - 1;
    int i = 0;
    for (i = 0; i <= end; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size && arr[left] >= arr[i]) return false;
        if (right < size && arr[right] >= arr[i]) return false;
    }
    return true;

}

int main() {
    int arr[5] = { 11,3,5,2,5 };
    int* p = arr;
    buildHeap(arr, 5);

    print(arr, 5);
    printf("isValid: %d\n", isValidMaxHeap(arr, 5));
    return 1;
}
