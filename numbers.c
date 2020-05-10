#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "array_void.h"

int main(void)
{
  int numbers[] = { 2, 6, 3, 6, 1, 9, 4, 12, 11, 3 };
  int size = sizeof(numbers) / sizeof(int);
  int initial = 0;

  // Array elements = {numbers, size};
  // Array *squares = map(&elements, &square);
  // Array* even_numbers = filter(&elements, &is_even);
  // print_array(squares);
  // free_array(squares);
  // print_array(even_numbers);
  // printf("%d\n", reduce(&elements, 0, &add));
  // free_array(even_numbers);
  // run_test();

  ArrayVoid input_array = {(Object)numbers, size};

  ArrayVoid_ptr odd_numbers = filter_void(&input_array, &is_odd);
  print_void_array(odd_numbers);
  free_void_array(odd_numbers);
  ArrayVoid_ptr cubes = map_void(&input_array, &cube);
  print_void_array(cubes);
  free_void_array(cubes);
  int *total_sum = (int_ptr)reduce_void(&input_array, &initial, &addition);
  printf("%d\n", *total_sum);
  free(total_sum);

  return 0;
}