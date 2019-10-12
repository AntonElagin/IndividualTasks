#include "my_task.h"
#include <stdexcept>

bool is_less(const Airplane *l, const Airplane *r) {
  if (!strcmp(l->brand, r->brand))
    return l->range < r->range;
  else if (strcmp(l->brand, r->brand) < 0)
    return true;
  else
    return false;
}

void merge_sort(Airplane *array, size_t size,
                bool(isLess)(const Airplane *, const Airplane *)) {
  if (!array || (size <= 0))
    return;
  int mid = size / 2;
  if (size % 2 == 1) mid++;
  int h = 1;
  Airplane *c = (Airplane *)malloc(size * sizeof(Airplane));
  if (!c) throw std::bad_alloc();
  while (h < size) {
    int step = h;
    int i = 0;
    int j = mid;
    int k = 0;
    while (step <= mid) {
      while ((i < step) && (j < size) && (j < (mid + step))) {
        if (isLess(&array[i], &array[j])) {
          c[k++] = array[i++];
        } else {
          c[k++] = array[j++];
        }
      }
      while (i < step) {
        c[k++] = array[i++];
      }
      while ((j < (mid + step)) && (j < size)) {
        c[k++] = array[j++];
      }
      step = step + h;
    }
    h = h * 2;
    memcpy(array, c, size * sizeof(Airplane));
  }
  free(c);
}
