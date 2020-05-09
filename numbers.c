#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(void)
{
  int numbers[] = { 2, 6, 3, 6, 1, 9, 4, 12, 11, 3 };
  Array elements = { numbers, sizeof(numbers) / sizeof(int) };
  Array* squares = map(&elements, &square);
  Array* even_numbers = filter(&elements, &is_even);
  print_array(squares);
  print_array(even_numbers);
  printf("%d\n", reduce(&elements, 0, &add));
  run_test();
  free_array(squares);
  free_array(even_numbers);
  return 0;
}