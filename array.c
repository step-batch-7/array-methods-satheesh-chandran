#include <stdlib.h>
#include "array.h"

Array_ptr copy_array(int numbers[], int length)
{
  Array_ptr array_copy = malloc(sizeof(Array));
  array_copy->array = malloc(length * sizeof(int));
  for (int index = 0; index < length; index++)
  {
    array_copy->array[index] = numbers[index];
  }
  array_copy->length = length;
  return array_copy;
}

Array_ptr map(Array_ptr src, Mapper mapper)
{
  int numbers[src->length], length = 0;
  for (int index = 0; index < src->length; index++)
  {
    numbers[index] = (*mapper)(src->array[index]);
    length++;
  }
  return copy_array(numbers, length);
}

Array_ptr filter(Array_ptr src, Predicate predicate)
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

int reduce(Array_ptr src, int init, Reducer reducer)
{
  int reduce_result = init;
  for (int index = 0; index < src->length; index++)
  {
    reduce_result = (*reducer)(reduce_result, src->array[index]);
  }
  return reduce_result;
}

void free_array(Array_ptr src)
{
  free(src->array);
  free(src);
}