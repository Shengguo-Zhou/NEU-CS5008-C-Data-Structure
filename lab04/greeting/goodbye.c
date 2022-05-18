#include <stdio.h>
#include "user.h"

void InformalGoodbye(User *user)
{
    printf("See you, %s!\n", user->firstName);
}

void FormalGoodbye(User *user)
{
    printf("Goodbye, Name: %s, %s\n", user->lastName, user->firstName);
}