#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "a2.h"
#include "a2.c"

Name name1;
Name name2;
Name name3;
Name name4;
Name name5;

void Init() {
  srand(time(NULL));

  name1.first = "Alyssa";
  name1.middle = "Mary";
  name1.last = "Antle";
  name1.age = 18;

  name2.first = "BeN";
  name2.middle = "ivan";
  name2.last = "bitDiDdle";
  name2.age = 32;

  name3.first = "Cassie";
  name3.middle = "Maria";
  name3.last = "Charstrup";
  name3.age = 64;

  name4.first = "Daniel";
  name4.last = "Diamond";
  name4.age = 42;

  name5.first = "AnyA";
  name5.last = "DOE";
  name5.age = 18;
}


void StartTest(const char *test) {
  static int count = 1;
  printf("Test #%d: %s\n\n", count++, test);
}

void EndTest() {
  printf("\n--------------------------------\n\n");
}


void TestBig() {
  StartTest("Print Big");

  Big(&name1);
  printf("\n");
  Big(&name2);
  printf("\n");
  Big(&name4);
  printf("\n");

  EndTest();
}

void TestLast() {
  StartTest("Print Last");

  Last(&name2);
  printf("\n");
  Last(&name4);
  printf("\n");

  EndTest();
}

void TestReg() {
  StartTest("Print Reg");

  Reg(&name3);
  printf("\n");
  Reg(&name4);
  printf("\n");

  EndTest();
}

void TestMid() {
  StartTest("Print Mid");

  Mid(&name4);
  printf("\n");
  Mid(&name1);
  printf("\n");

  EndTest();
}

void TestSmall() {
  StartTest("Print Small");

  Small(&name4);
  printf("\n");
  Small(&name2);
  printf("\n");

  EndTest();
}

void TestFormatName() {
  StartTest("Print FormatName");

  FormatName(&name1, 'B');
  printf("\n");
  FormatName(&name1, 'L');
  printf("\n");
  FormatName(&name1, 'r');
  printf("\n");
  FormatName(&name1, 'M');
  printf("\n");
  FormatName(&name1, 'S');
  printf("\n");

  FormatName(&name4, 'B');
  printf("\n");
  FormatName(&name4, 'l');
  printf("\n");
  FormatName(&name4, 'R');
  printf("\n");
  FormatName(&name4, 'm');
  printf("\n");
  FormatName(&name4, 'S');
  printf("\n");

  EndTest();
}

int TestFillName() {
  StartTest("Print FillName");

  char dest[100] = {0};
  FillName(&name1, 'b', dest);
  printf("%s\n", dest);
  
  char dest1[100] = {0};
  FillName(&name1, 'l', dest1);
  printf("%s\n", dest1);

  char dest2[100] = {0};
  FillName(&name2, 'm', dest2);
  printf("%s\n", dest2);
 
  char dest3[100] = {0};
  FillName(&name5, 's', dest3);
  printf("%s\n", dest3);

  char dest4[100] = {0};
  FillName(&name5, 'w', dest4);
  printf("%s\n", dest4);
 
  EndTest();
  return 0;
}


int main(void) {
  Init();

  TestBig();
  TestLast();
  TestReg();
  TestMid();
  TestSmall();
  TestFormatName();
  TestFillName();
  
  printf("feel free to add your own!\n");

  return EXIT_SUCCESS;
}

