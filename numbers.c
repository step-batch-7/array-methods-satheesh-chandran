#include <stdio.h>
#include <stdlib.h>
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

Object square_void(Object data)
{
  int number = *(int_ptr)data;
  int_ptr square_of_number = malloc(sizeof(int));
  *square_of_number = number * number;
  return (Object)square_of_number;
}

Bool is_odd(Object data)
{
  int number = *(int_ptr)data;
  return number % 2 == 1 ? True : False;
}

Object add_void(Object data1, Object data2)
{
  int *sum = malloc(sizeof(int));
  *sum = *(int_ptr)data1 + *(int_ptr)data2;
  return (Object)sum;
}

void print_array_void(ArrayVoid_ptr src)
{
  for (int index = 0; index < src->length;index++)
  {
    printf("%d ", *(int_ptr) src->array[index]);
  }
  printf("\n");
}

/////////////////////////////////////////////////

int main(void)
{
  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof(numbers) / sizeof(int);
  int initial = 0;

  printf("______________________________________________________\n");

  Array elements = {numbers, size};
  Array *squares = map(&elements, &square);
  Array* even_numbers = filter(&elements, &is_even);

  printf("\nSquares of numbers is -->  ");
  print_array(squares);
  printf("\nEven numbers is       -->  ");
  print_array(even_numbers);
  printf("\nSum of numbers is     -->  %d\n", reduce(&elements, 0, &add));

  free_array(squares);
  free_array(even_numbers);
  // run_test();

  printf("______________________________________________________\n");

  ArrayVoid_ptr input_array = create_array_void(size);
  insert_number_to_array_void(input_array, numbers, size);

  ArrayVoid_ptr odd_voids = filter_void(input_array, &is_odd);
  ArrayVoid_ptr squares_void = map_void(input_array, &square_void);
  Object sum_of_numbers = reduce_void(input_array, &initial, &add_void);

  printf("\nSquares of numbers is -->  ");
  print_array_void(squares_void);
  printf("\nOdd numbers is        -->  ");
  print_array_void(odd_voids);
  printf("\nSum of numbers is     -->  %d\n", *(int_ptr)sum_of_numbers);

  free_array_void(squares_void);
  free_array_void(odd_voids);
  free_array_void(input_array);
  free(sum_of_numbers);

  printf("______________________________________________________\n");
  return 0;
}