#ifndef __ARRAY_H
#define __ARRAY_H

typedef enum
{
  False,
  True
} Bool;

typedef int (*Mapper)(int);
typedef Bool (*Predicate)(int);
typedef int (*Reducer)(int, int);

typedef struct
{
  int *array;
  int length;
} Array;

typedef Array *Array_ptr;
typedef int *int_ptr;

Array_ptr map(Array_ptr src, Mapper mapper);
Array_ptr filter(Array_ptr src, Predicate predicate);
int reduce(Array_ptr src, int init, Reducer reducer);

int square(int number);
Bool is_even(int number);
int add(int num1, int num2);
void print_array(Array_ptr elements);
Array_ptr copy_array(int numbers[], int length);
void free_array(Array_ptr src);

void run_test(void);

#endif
