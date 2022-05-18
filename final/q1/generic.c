#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "generic.h"

// START_NO_CHANGE
const char ALLOWED[] = "abcdefghijklmnopqrstuvwxyz1234567890";
const int nbAllowed = sizeof(ALLOWED) - 1;

char* generateRandomStr() {
    int size = rand() % 30;
    char* str = (char*)malloc((sizeof(char) * size) + 1);
    int i, c;
    for (i = 0;i < size;i++) {
        c = rand() % nbAllowed;
        str[i] = ALLOWED[c];
    }
    str[size] = '\0';
    return str;
}

Strings* generateRandomStrings() {
    int size = rand() % 50;
    printf("creating string list of size %d\n", size);

    char** strs = (char**)malloc(sizeof(char*) * size);
    int i;
    for (i = 0; i < size; i++) {
        char* s = generateRandomStr();
        printf("inserting str %s\n", s);

        strs[i] = s;
    }
    Strings* result = (Strings*)malloc(sizeof(Strings));
    result->data = strs;
    result->size = size;

    return result;
}

void printStrings(Strings* strs) {
    int i;
    for (i = 0; i < strs->size; i++) {
        printf("string in strs is %s\n", strs->data[i]);
    }
}



int countChars(Strings strings) {
    int i = 0;
    int count = 0;
    for (i = 0; i < strings.size; i++) {
        count += strlen(strings.data[i]);
    }
    return count;
}


int countStrings(Strings strings) {
    return strings.size;
}




int main() {
    srand(time(NULL));
    Strings* strs = generateRandomStrings();
    printStrings(strs);

    printf("String size is %d\n", countStrings(*strs));
    printf("Total string size is %d\n", countChars(*strs));
}


