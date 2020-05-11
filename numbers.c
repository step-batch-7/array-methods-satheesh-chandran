#include <stdio.h>
#include "array.h"
#include "array_void.h"

int square(int number)
{
  return number * number;
}

int add(int num1, int num2)
{
  return num1 + num2;
}

Bool is_even(int number)
{
  return number % 2 == 0 ? True : False;
}

void print_array(Array* src)
{
  for (int index = 0; index < src->length; index++)
  {
    printf("%d ", src->array[index]);
  }
  printf("\n");
}

/////////////////////////////////////////////////

Object cube(Object data)
{
  long int number = (long int)data;
  return (Object)(square(number) * number);
}

Object increment(Object data)
{
  long int number = (int)data;
  return (Object)(number + 1);
}

Object addition(Object data1, Object data2)
{
  long int total = (long int)data1 + (long int)data2;
  return (Object)total;
}

Bool is_odd(Object data)
{
  return (int)data % 2;
}

void display_number_array(ArrayVoid_ptr array)
{
  for (int index = 0; index < array->length; index++)
  {
    printf("%d  ", (int)array->array[index]);
  }
  printf("\n");
}

/////////////////////////////////////////////////

int main(void)
{
  int numbers[] = { 2, 6, 3, 6, 1, 9, 4, 12, 11, 3 };
  int size = sizeof(numbers) / sizeof(int);
  int initial = 0;

  Array elements = {numbers, size};
  Array *squares = map(&elements, &square);
  Array* even_numbers = filter(&elements, &is_even);
  print_array(squares);
  free_array(squares);
  print_array(even_numbers);
  printf("%d\n", reduce(&elements, 0, &add));
  free_array(even_numbers);
  run_test();

  long int nums[] = {2, 6, 3, 6, 1, 9, 4, 12, 11, 3};
  size = sizeof(nums) / sizeof(long int);
  ArrayVoid_ptr array_void = create_ArrayVoid(size);
  insert_number_to_void_array(array_void, nums, size);
  display_number_array(array_void);
  ArrayVoid_ptr cubes = map_void(array_void, &cube);
  display_number_array(cubes);
  free_void_array(cubes);
  ArrayVoid_ptr odd_numbers = filter_void(array_void, &is_odd);
  display_number_array(odd_numbers);
  free_void_array(odd_numbers);
  printf("%d\n", (int)reduce_void(array_void, 0, &addition));

  return 0;
}