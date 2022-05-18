/* strtok example */
#include <stdio.h>
#include <string.h>

int main()
{
    printf("Please input something.\n");

    char str[100];
    char* pch;
    scanf("%[^\n]s", str);
    //printf("%s", str);


    pch = strtok(str, " ");
    while (pch != NULL)
    {
        printf("%s\n", pch);
        pch = strtok(NULL, " ");
    }
    return 0;
}