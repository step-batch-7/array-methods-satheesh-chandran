#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int assert_equal(int expected, int actual, const char discription[]);
int assert_deep_strict_equal(Array_ptr expected, Array_ptr actual, const char discription[]);
int max(int a, int b);

int max(int a, int b)
{
  return a > b ? a : b;
}

int assert_equal (int expected, int actual, const char discription[])
{
  if (actual != expected)
  {
    printf("  ✗ %s \n   -> expected : %d \n   -> actual   : %d\n", discription, expected, actual);
    return 1;
  }
  printf("  ✓ %s \n", discription);
  return 0;
}

int assert_deep_strict_equal(Array_ptr expected, Array_ptr actual, const char discription[])
{
  int status = 1;
  for (int index = 0; index < max(expected->length, actual->length); index++)
  {
    status = status && (expected->array[index] == actual->array[index]);
  }
  if (!status)
  {
    printf("  ✗ %s \n   -> expected : ", discription);
    print_array(expected);
    printf("   -> actual   : ");
    print_array(actual);
    return !status;
  }
  printf("  ✓ %s \n", discription);
  return !status;
}

int run_reduce_tests(void)
{
  int failed_tests = 0;
  printf("\n  Running tests of reduce...\n");
  
  int test1_numbers[] = {1, 2, 3};
  ARRAY array_1 = {test1_numbers, 3};
  failed_tests += assert_equal(6, reduce(&array_1, 0, &add), "Should add all numbers together");


  int test2_numbers[] = {};
  ARRAY array_2 = {test2_numbers, 0};
  failed_tests += assert_equal(0, reduce(&array_2, 0, &add), "should return the initial value if the array is empty");

  printf("  Reduce tests completed...\n");
  return failed_tests;
}

int run_map_test(void)
{
  int failed_test = 0;
  printf("\n  Running tests of map...\n");
  
  int test1_numbers[] = {1, 2, 3, 4};
  ARRAY input1 = {test1_numbers, 4};
  int expected_numbers1[] = {1, 4, 9, 16};
  ARRAY expected_array1 = {expected_numbers1, 4};
  Array_ptr actual1 = map(&input1, &square);
  failed_test += assert_deep_strict_equal(&expected_array1, actual1, "should return squares of the given numbers");
  free_array(actual1);

  int test2_numbers[] = {};
  ARRAY input2 = {test2_numbers, 0};
  int expected_numbers2[] = {};
  ARRAY expected_array2 = {expected_numbers2, 0};
  Array_ptr actual2 = map(&input2, &square);
  failed_test += assert_deep_strict_equal(&expected_array2, actual2, "should return empty array if the input is empty");
  free_array(actual2);

  printf("  Map tests completed...\n");
  return failed_test;
}


int run_filter_test(void)
{
  int failed_test = 0;
  printf("\n  Running tests of filter...\n");
  
  int test1_numbers[] = {1, 2, 3, 4};
  ARRAY input1 = {test1_numbers, 4};
  int expected_numbers1[] = {2, 4};
  ARRAY expected_array1 = {expected_numbers1, 2};
  Array_ptr actual1 = filter(&input1, &is_even);
  failed_test += assert_deep_strict_equal(&expected_array1, actual1, "should return all even numbers from the list");
  free_array(actual1);

  int test2_numbers[] = {};
  ARRAY input2 = {test2_numbers, 0};
  int expected_numbers2[] = {};
  ARRAY expected_array2 = {expected_numbers2, 0};
  Array_ptr actual2 = filter(&input2, &is_even);
  failed_test += assert_deep_strict_equal(&expected_array2, actual2, "should return empty array if the input is empty");
  free_array(actual2);

  int test3_numbers[] = {1, 3, 5, 7};
  ARRAY input3 = {test3_numbers, 4};
  int expected_numbers3[] = {};
  ARRAY expected_array3 = {expected_numbers3, 0};
  Array_ptr actual3 = filter(&input3, &is_even);
  failed_test += assert_deep_strict_equal(&expected_array3, actual3, "should return empty array no even numbers found in the list");
  free_array(actual3);

  printf("  Filter tests completed...\n");
  return failed_test;
}

void run_test(void)
{
  int failed_test = 0;
  printf("Running test cases...\n");
  failed_test += run_reduce_tests();
  failed_test += run_map_test();
  failed_test += run_filter_test();
  printf("%d tests failed\n", failed_test);
  printf("Test completed...\n");
}