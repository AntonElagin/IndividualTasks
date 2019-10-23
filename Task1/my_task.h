#ifndef TASK1_MY_TASK_H
#define TASK1_MY_TASK_H

#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <cstring>
#include <string>

typedef struct Airplane Airplane;
struct Airplane {
  char brand[20];
  char model[20];
  char appointment[20];
  int crew_number;
  int range;
};

bool is_less(const Airplane *l, const Airplane *r);

void merge_sort(Airplane *array, size_t size,
                bool(isLess)(const Airplane *, const Airplane *));

#endif  // TASK1_MY_TASK_H
