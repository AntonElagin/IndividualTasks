#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "parallel_algorithm.h"
#include "naive_algorithm.h"





int main() {

  //generate_comment_array(100000000,"struct_file.txt");
  int SIZE = 0;
  Comment *ptr = NULL;
  int counter;
  get_comment_array(&ptr, &SIZE, "struct_file.txt");
  if (ptr) {
    time_t t1,t2, t3;
    t1 = clock();
    printf("naive %d\n", find_zero_count_naive(ptr, SIZE));
    t2 = clock();
    printf("parallel %d\n", find_zero_count_parallel(ptr, SIZE, 4));
    t3 = clock();
    printf("time1 = %ld\ntime2 = %ld", t2-t1,t3-t2);
  }
  free(ptr);
  return 0;
}

