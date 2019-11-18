#ifndef INDIVIDUALTASK2_PARALLEL_ALGORITHM_H
#define INDIVIDUALTASK2_PARALLEL_ALGORITHM_H

#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"

int find_zero_count_parallel(const Comment*, int);

int find_zero_count(const Comment*, int, int);

#endif  // INDIVIDUALTASK2_PARALLEL_ALGORITHM_H
