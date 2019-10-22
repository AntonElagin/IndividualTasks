//
// Created by anton on 20.10.2019.
//

#ifndef INDIVIDUALTASK2_NAIVE_ALGORITHM_H
#define INDIVIDUALTASK2_NAIVE_ALGORITHM_H

#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"


int find_zero_count_naive(const Comment* , int );
int get_comment_array(Comment** , int*,const char *);
int generate_comment_array(int size,const char * file_name);

#endif //INDIVIDUALTASK2_NAIVE_ALGORITHM_H
