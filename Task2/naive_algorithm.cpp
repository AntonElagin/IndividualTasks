//
// Created by anton on 20.10.2019.
//

#include "naive_algorithm.h"

int find_zero_count_naive(const Comment* array, int arr_size) {
  if ((arr_size <= 0) || !array) return 0;
  int zero_counter = 0;
  for (int j = 0; j < arr_size; ++j) {
    if (array[j].mark.status == 0) ++zero_counter;
  }
  return zero_counter;
}
