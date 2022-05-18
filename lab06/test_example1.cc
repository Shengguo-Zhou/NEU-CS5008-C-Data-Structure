/**
 *  CS 5008: Spr 2021
 *  Northeastern University, Seattle
 *  Lab 6: Testing with Google
 *
 *  Author: Adrienne H. Slaughter (02/25/2021)
 */


#include "gtest/gtest.h"

extern "C" {
#include "example1.h"
}

const char* first = "first";
const char* second = "second";
const char* third = "third";
const char* fourth = "fourth";


// STEP 0: Run 'make' and ''./test_suite' with the 
// starter code and make note of the information 
// printed to your console. 
// How are the parameters inside the TEST(param1, param2) represented?
// Param1: File we're test, or suite of tests
// Param2: Function we're testing, or a specific test desc
TEST(Foobar, SomeFunction) {
  int num = 4;
  int res = SquareNumber(num);
  // Non "fatal"
  EXPECT_EQ(res, 16);
  // Fatal (Test stops running)
  //  ASSERT_EQ(res, 16);
  //  EXPECT_EQ(SquareNumber(0), 0);
}

TEST(Example1, SumTwoNumbers) {
  int num_one = 4;
  int num_two = 5;
  int res = SumTwoNumbers(num_one, num_two);
  EXPECT_EQ(res, 9);
  // STEP 1: Change num_one and/or num_two. 
  // Run 'make' and the 'test_suite' again. What happens? 
  // How can you use this for debugging?
}


TEST(Example1, MultiplyTwoNumbers) {
  int num_one = 4;
  int num_two = 5;
  int res = MultiplyTwoNumbers(num_one, num_two);
  // [actual value] [expected]
  EXPECT_EQ(res, 20);
  // STEP 2: Change the expected value to something 
  // NOT 20. Run 'make' and './test_suite' again and 
  // observe how the Google test suite reflects this error.
}


/*
STEP 5: Add tests for the additional method(s) that you defined.
*/
TEST(Example1, JustReturnOne) {
  int num_one = 4;
  int res = JustReturnOne(num_one);
  // [actual value] [expected]
  EXPECT_EQ(res, 1);
}


TEST(NEW_FUNCTION, STRING_PREFIX) {
  EXPECT_TRUE(StringStartsWith("foo", "foobar"));
  EXPECT_FALSE(StringStartsWith("bar", "foobar"));
  ASSERT_FALSE(StringStartsWith("bar", "foobar"));
  EXPECT_TRUE(StringStartsWith("foo2", "foo2bar"));
  printf("got to this point\n");
  ////  EXPECT_TRUE(StringStartsWith("foo", NULL));
  //EXPECT_TRUE(StringStartsWith(NULL, NULL));
  // EXPECT_TRUE(StringStartsWith("foobar", "foo"));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
