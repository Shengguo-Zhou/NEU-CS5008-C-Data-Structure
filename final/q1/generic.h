#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef GENERIC_H
#define GENERIC_H

typedef struct Strings{
    char** data;
    int size;
}Strings;

/*
 * Given a list of strings, counts the number of characters in the strings.
 *
 * Example:
 *
 * countChars(["foo", "bar"]) => 6
 */
int countChars(Strings strings);

/*
 * Given a list of strings, counts the number of strings in the list..
 *
 * Example:
 *
 * countChars(["foo", "bar"]) => 2
 */
int countStrings(Strings strings);

#endif
