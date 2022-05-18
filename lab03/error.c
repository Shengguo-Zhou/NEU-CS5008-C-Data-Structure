#include <stdio.h>
#include <stdlib.h>
int main()
{
    int stringLength = 7;
    char *stringOnHeap = (char *)malloc((*stringOnHeap * stringLength) + 1);
    stringOnHeap[0] = 'e';
    stringOnHeap[1] = 'x';
    stringOnHeap[2] = 'a';
    stringOnHeap[3] = 'm';
    stringOnHeap[4] = 'p';
    stringOnHeap[5] = 'l';
    stringOnHeap[6] = 'e';
    stringOnHeap[7] = '\0';
    printf("%s\n", stringOnHeap);
    return 0;
}