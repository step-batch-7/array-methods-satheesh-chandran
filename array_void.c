#include <stdlib.h>
#include "array_void.h"

ArrayVoid_ptr create_array_void(int length)
{
  ArrayVoid_ptr array_void = malloc(sizeof(ArrayVoid));

  array_void->array = malloc(sizeof(Object) * length);
  array_void->length = length;
  return array_void;
}

void insert_number_to_array_void(ArrayVoid_ptr src, int * numbers, int size)
{
  for (int index = 0; index < size; index++)
  {
    int * ptr = malloc(sizeof(int));
    *ptr = numbers[index];
    src->array[index] = (Object)ptr;
  }
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr map_array = create_array_void(src->length);
  for (int index = 0; index < src->length; index++)
  {
    map_array->array[index] = (*mapper)(src->array[index]);
  }
  return map_array;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  int temp[src->length];
  int count = 0;
  for (int index = 0; index < src->length; index++)
  {
    if ((*predicate)(src->array[index]) == True)
    {
      int number = *(int *)src->array[index];
      temp[count] = number;
      count++;
    }
  }
  ArrayVoid_ptr filter_array = create_array_void(count);
  insert_number_to_array_void(filter_array, temp, count);
  return filter_array;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  int * final_reduce_result = malloc(sizeof(int));
  *final_reduce_result = *(int *)init;
  for (int index = 0; index < src->length; index++)
  {
    Object reducer_result = (*reducer)(final_reduce_result, src->array[index]);
    free(final_reduce_result);
    final_reduce_result = reducer_result;
  }
  return (Object)final_reduce_result;
}

void free_array_void(ArrayVoid_ptr src)
{
  for (int index = 0; index < src->length; index++)
  {
    free(src->array[index]);
  }
  free(src->array);
  free(src);
}
