//
// Created by anton on 07.10.2019.
//

#include "MyTask.h"
#include <assert.h>

bool is_less(const struct Airplane *l, const struct Airplane *r) {
  if (!strcmp(l->brand, r->brand))
    return l->range < r->range;
  else if (strcmp(l->brand, r->brand) < 0)
    return true;
  else
    return false;
}

void merge_sort(struct Airplane *array, size_t size,
                bool(isLess)(const struct Airplane *,
                             const struct Airplane *)) {
  assert(array && (size > 0));
  int mid = size / 2;
  if (size % 2 == 1)
    mid++;
  int h = 1;
  struct Airplane *c =
      (struct Airplane *)malloc(size * sizeof(struct Airplane));
  while (h < size) {
    int step = h;
    int i = 0;
    int j = mid;
    int k = 0;
    while (step <= mid) {
      while ((i < step) && (j < size) && (j < (mid + step))) {
        if (isLess(&array[i], &array[j])) {
          c[k] = array[i];
          i++;
          k++;
        } else {
          c[k] = array[j];
          j++;
          k++;
        }
      }
      while (i < step) {
        c[k] = array[i];
        i++;
        k++;
      }
      while ((j < (mid + step)) && (j < size)) {
        c[k] = array[j];
        j++;
        k++;
      }
      step = step + h;
    }
    h = h * 2;

    memcpy(array, c, size * sizeof(struct Airplane));
    // for (i = 0; i < size; i++)
    // array[i] = c[i];
  }
  free(c);
}


