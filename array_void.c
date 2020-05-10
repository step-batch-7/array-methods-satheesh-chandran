#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"
#include "array.h"

Object cube(Object data)
{
  int number = *(int_ptr)data;
  int * cube_of_number = malloc(sizeof(int));
  *cube_of_number = square(number) * number;
  return (Object) cube_of_number;
}

Object increment(Object data)
{
  int_ptr result = malloc(sizeof(int));
  *result = *(int_ptr)data + 1;
  return (Object)result;
}

Object addition(Object data1, Object data2)
{
  int_ptr result = malloc(sizeof(int));
  *result = *(int_ptr)data1 + *(int_ptr)data2;
  return (Object)result;
}

Bool is_odd(Object data)
{
  return *(int_ptr)data % 2;
}

ArrayVoid_ptr create_array_void(int *numbers, int size)
{
  ArrayVoid_ptr array = malloc(sizeof(ArrayVoid));
  array->array = malloc(sizeof(size));
  array->length = 0;
  for (int index = 0; index < size; index++)
  {
    int_ptr number = malloc(sizeof(int));
    *number = numbers[index];
    *(array->array + index) = (Object) number;
    array->length++;
  }
  return array;
}

void print_void_array(ArrayVoid_ptr src)
{
  for (int index = 0; index < src->length; index++)
  {
    printf("%d ", *(int *)(src->array[index]));
  }
  printf("\n");
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  int_ptr result = malloc(sizeof(int));
  *result = *(int_ptr)init;
  for (int index = 0; index < src->length; index++)
  {
    Object current_result = reducer(result, ((int *)src->array + index));
    *result = *(int_ptr)current_result;
    free(current_result);
  }
  return (Object)result;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr map_result = malloc(sizeof(ArrayVoid));
  map_result->array = malloc(src->length);
  map_result->length = 0;
  for (int index = 0; index < src->length; index++)
  {
    Object result = mapper(((int_ptr)src->array + index));
    map_result->array[index] = result;
    map_result->length++;
  }
  return map_result;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  ArrayVoid_ptr filter_result = malloc(sizeof(ArrayVoid));
  filter_result->array = malloc(src->length);
  filter_result->length = 0;
  for (int index = 0; index < src->length; index++)
  {
    if (predicate((int *)src->array + index) == True)
    {
      int *number = malloc(sizeof(int));
      *number = *(int_ptr)((int *)src->array + index);
      filter_result->array[filter_result->length] = (Object)number;
      filter_result->length++;
    }
  }
  return filter_result;
}

void free_void_array(ArrayVoid_ptr src)
{
  for (int index = 0; index < src->length; index++)
  {
    free((int *)*(src->array + index));
  }
  free(src->array);
  free(src);
}
