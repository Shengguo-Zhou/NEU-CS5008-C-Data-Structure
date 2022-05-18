#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "a2.h"

// YOUR CODE GOES HERE

// Print the string <first> <middle> <last>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben Ivan Bitdiddle".
//
//  If the middle name is NULL, then print:
//  "Ben Bitdiddle"
//
//  name: a pointer to a Name
void Big(Name *name)
{
    if (name->middle == NULL)
        printf("%s %s", name->first, name->last);
    else
        printf("%s %s %s", name->first, name->middle, name->last);
}

// Print the string <last>, <first>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Bitdiddle, Ben".
//
// name: a pointer to a Name
void Last(Name *name)
{
    printf("%s %s", name->last, name->first);
}

// Print the string <first> <last>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben Bitdiddle".
//
// name: a pointer to a Name
void Reg(Name *name)
{
    printf("%s %s", name->first, name->last);
}

// Print the string <first> <middle-initial>. <last>
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben I. Bitdiddle".
//
// If middle name is NULL, print:
// "Ben Bitdiddle"
//
// name: a pointer to a Name
void Mid(Name *name)
{
    if (name->middle == NULL)
        printf("%s %s", name->first, name->last);
    else
    {
        char char_middle_initial = name->middle[0];
        printf("%s %c. %s", name->first, char_middle_initial, name->last);
    }
}

// Print the first name only.
//  e.g. if first = "Ben", middle = "Ivan",
//  and last = "Bitdiddle, then print:
//  "Ben".
//
// name: a pointer to a Name
void Small(Name *name)
{
    printf("%s.", name->first);
}

// Given a format char, print the given
// name in the format specified by char.
// The mapping is shown below:
// B -> 'big' format
// L -> 'last' format
// R -> 'reg' format
// M -> 'mid' format
// S -> 'small' format
//
// name: a pointer to a Name
// format: a char indicating the format to use (case doesn't matter)
void FormatName(Name *name, char format)
{
    if (format == 'B' || format == 'b')
        Big(name);
    if (format == 'L' || format == 'l')
        Last(name);
    if (format == 'R' || format == 'r')
        Reg(name);
    if (format == 'M' || format == 'm')
        Mid(name);
    if (format == 'S' || format == 's')
        Small(name);
}

// Given a name, a format and a destination array,
// put the properly formatted name in the destination
// array, not printing anything on the screen.
//
// The mapping is shown below:
// B -> 'big' format
// L -> 'last' format
// R -> 'reg' format
// M -> 'mid' format
// S -> 'small' format
//
// name: a pointer to a Name
// format: a char indicating the format to use (case doesn't matter)
// dest: a pointer to an array that is guaranteed to be big enough
// to hold the formatted name
void FillName(Name *name, char format, char *dest)
{
    char *str1 = name->first;
    char *str2 = name->middle;
    char *str3 = name->last;
    int BUFFER_SIZE = 100;
    if (format == 'B' || format == 'b')
        if (str2 != NULL)
            snprintf(dest, BUFFER_SIZE, "%s %s %s", str1, str2, str3);
        else
            snprintf(dest, BUFFER_SIZE, "%s %s", str1, str3);

    else if (format == 'L' || format == 'l')
        snprintf(dest, BUFFER_SIZE, "%s %s", str3, str1);

    else if (format == 'R' || format == 'r')
        snprintf(dest, BUFFER_SIZE, "%s %s", str1, str3);

    else if (format == 'M' || format == 'm')
        if (str2 == NULL)
            snprintf(dest, BUFFER_SIZE, "%s %s", str1, str3);
        else
        {
            char char_middle_initial = str2[0];
            snprintf(dest, BUFFER_SIZE, "%s %c. %s", str1, char_middle_initial, str3);
        }

    else if (format == 'S' || format == 's')
        snprintf(dest, BUFFER_SIZE, "%s", str1);
}
