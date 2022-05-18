#include <stdio.h>
#include "user.h"

void StandardGreeting(User *user)
{
    printf("Hello, %s!\n", user->firstName);
}

void FormalGreeting(User *user)
{
    printf("Name: %s, %s\n", user->lastName, user->firstName);
}