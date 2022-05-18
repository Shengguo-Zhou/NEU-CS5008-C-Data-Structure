#include <stdio.h>
#include "greeting.c"
#include "goodbye.c"
#include "user.h"

int main()
{

  User user = {"Big", "Lebowski", 42};
  StandardGreeting(&user);
  FormalGreeting(&user);
  InformalGoodbye(&user);
  FormalGoodbye(&user);

  return 0;
}
