#include <stdio.h>
#include <stdlib.h>
int main()
{
    int stringLength = 7;
    // since sizeof operates on a TYPE, we are no longer using the stringOnHeap var
    // before/while we initialize it
    char *stringOnHeap = (char *)calloc(sizeof(*stringOnHeap), stringLength + 1);
    // malloc returns NULL on failure, so it's prudent to see if malloc succeeded or
    // failed before continuing
    if (stringOnHeap == NULL)
    {
        printf("malloc failed\n");
        exit(EXIT_FAILURE);
    }
    stringOnHeap[0] = 'e';
    stringOnHeap[1] = 'x';
    stringOnHeap[2] = 'a';
    stringOnHeap[3] = 'm';
    stringOnHeap[4] = 'p';
    stringOnHeap[5] = 'l';
    stringOnHeap[6] = 'e';
    stringOnHeap[7] = '\0';
    printf("%s\n", stringOnHeap);
    // free the block
    free(stringOnHeap);
    return 0;
}