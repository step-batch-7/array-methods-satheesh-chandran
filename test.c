#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int assertEqual(int expected, int actual, const char discription[]);

void run_reduce_tests(void)
{
  int failed_tests = 0;
  printf("  Running tests of reduce...\n");
  int test1_numbers[] = {1, 2, 3};
  ARRAY array_1 = {test1_numbers, 3};

  failed_tests += assertEqual(6, reduce(&array_1, 0, &add), "Should add all numbers together");

  int test2_numbers[] = {};
  ARRAY array_2 = {test2_numbers, 0};
  failed_tests += assertEqual(0, reduce(&array_2, 0, &add), "should return the initial value if the array is empty");

  printf("  Reduce tests completed...\n  %d tests failed\n", failed_tests);
}

int assertEqual (int expected, int actual, const char discription[])
{
  if (actual != expected)
  {
    printf("  ✗ %s \n   -> expected : %d \n   -> actual   : %d\n", discription, expected, actual);
    return 1;
  }
  printf("  ✓ %s \n", discription);
  return 0;
}

void run_test(void)
{
  printf("Running test cases...\n");
  run_reduce_tests();
  printf("Test completed...\n");
}