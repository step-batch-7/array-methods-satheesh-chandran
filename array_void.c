#include <stdlib.h>
#include "array_void.h"

ArrayVoid_ptr create_array_void(int length)
{
  ArrayVoid_ptr array_void = malloc(sizeof(ArrayVoid));
  array_void->length = 0;
  array_void->array = malloc(sizeof(Object) * length);
  return array_void;
}

void insert_number_to_void_array(ArrayVoid_ptr src, Object numbers, int length)
{
  for (int index = 0; index < length; index++)
  {
    src->array[index] = (Object)(*((long int *)numbers + index));
    src->length++;
  }
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr map_result = create_array_void(src->length);
  for (int index = 0; index < src->length; index++)
  {
    map_result->array[index] = mapper(src->array[index]);
    map_result->length++;
  }
  return map_result;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  Object temp[src->length];
  int count = 0;
  for (int index = 0; index < src->length; index++)
  {
    Object current_element = src->array[index];
    if (predicate(current_element))
    {
      temp[count] = current_element;
      count++;
    }
  }
  ArrayVoid_ptr filter_result = create_array_void(count);
  for (int index = 0; index < count; index++)
  {
    filter_result->array[index] = temp[index];
    filter_result->length++;
  }
  return filter_result;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  for (int index = 0; index < src->length; index++)
  {
    init = reducer(init, src->array[index]);
  }
  return init;
}

void free_void_array(ArrayVoid_ptr src)
{
  free(src->array);
  free(src);
}
