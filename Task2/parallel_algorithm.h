//
// Created by anton on 20.10.2019.
//

#ifndef INDIVIDUALTASK2_PARALLEL_ALGORITHM_H
#define INDIVIDUALTASK2_PARALLEL_ALGORITHM_H

#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include "struct.h"


#define MAX_CORES 50


int find_zero_count_parallel(const Comment* , int ,int);
int find_zero_count(const Comment* , int, int);

#endif //INDIVIDUALTASK2_PARALLEL_ALGORITHM_H
