#include <stdlib.h>
#include "array_void.h"

ArrayVoid_ptr create_ArrayVoid(int length)
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
    src->array[index] = (Object)(*((int *)numbers + index));
    src->length++;
  }
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr mapped_array = create_ArrayVoid(src->length);
  for (int index = 0; index < src->length; index++)
  {
    mapped_array->array[index] = mapper(src->array[index]);
    mapped_array->length++;
  }
  return mapped_array;
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
  ArrayVoid_ptr filtered_array = create_ArrayVoid(count);
  for (int index = 0; index < count; index++)
  {
    filtered_array->array[index] = temp[index];
    filtered_array->length++;
  }
  return filtered_array;
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
