#include <stdio.h>
#include <stdlib.h>
#include "array.h"

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

Array* copy_array(int numbers[], int length)
{
  Array* array_copy = malloc(sizeof(Array));
  array_copy->array = malloc(length * sizeof(int));
  for (int index = 0; index < length; index++)
  {
    array_copy->array[index] = numbers[index];
  }
  array_copy->length = length;
  return array_copy;
}

Array* map(Array* src, Mapper mapper)
{
  int numbers[src->length], length = 0;
  for (int index = 0; index < src->length; index++)
  {
    numbers[index] = (*mapper)(src->array[index]);
    length++;
  }
  return copy_array(numbers, length);
}

Array* filter(Array* src, Predicate predicate)
{
  int numbers[src->length], length = 0;
  for (int index = 0; index < src->length; index++)
  {
    if ((*predicate)(src->array[index]))
    {
      numbers[length] = src->array[index];
      length++;
    }
  }
  return copy_array(numbers, length);
}

int reduce(Array* src, int init, Reducer reducer)
{
  int reduce_result = init;
  for (int index = 0; index < src->length; index++)
  {
    reduce_result = (*reducer)(reduce_result, src->array[index]);
  }
  return reduce_result;
}

void print_array(Array* src)
{
  for (int index = 0; index < src->length; index++)
  {
    printf("%d ", src->array[index]);
  }
  printf("\n");
}

void free_array(Array* src)
{
  free(src->array);
  free(src);
}