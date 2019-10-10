//
// Created by anton on 07.10.2019.
//

#ifndef TASK1_MYTASK_H
#define TASK1_MYTASK_H
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <cstring>
#include <string>

struct Airplane {
  char brand[20];
  char model[20];
  char appointment[20];
  int  crew_number;
  int  range;
};

bool is_less(const struct Airplane *l, const struct Airplane *r);

void merge_sort(struct Airplane *array, size_t size,
                bool(isLess)(const struct Airplane *, const struct Airplane *));

void task_function();
#endif  // TASK1_MYTASK_H
