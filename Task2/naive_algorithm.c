//
// Created by anton on 20.10.2019.
//

#include "naive_algorithm.h"

int find_zero_count_naive(const Comment* array, int arr_size) {
  int zero_counter = 0;
  for (int j = 0; j < arr_size; ++j) {
    if (array[j].mark.status == 0)
      ++zero_counter;
  }
  return zero_counter;
}

int get_comment_array(Comment ** return_ptr, int * return_size,const char* file_name) {
  if (*return_ptr)
    return -1;
  FILE * fptr = fopen(file_name, "r");
  if (fptr) {
    fscanf(fptr, "%d", return_size);
    if (!(*return_ptr = malloc(sizeof(Comment) * (*return_size))))
      return -1;
    for (int i = 0; i < *return_size; ++i) {
      fscanf(fptr,"%u %u %lu\n", &return_ptr[0][i].id, &return_ptr[0][i].count, &return_ptr[0][i].mark.status);
    }
    fclose(fptr);
    return 0;
  }
  return -1;
}

int generate_comment_array(int size,const char * file_name) {
  FILE * fptr = fopen("struct_file.txt", "w");
  if (fptr) {
    int SIZE = size;
    srand(time(0));
    Comment * ptr = malloc(sizeof(Comment)* SIZE);
    if (!ptr) return -1;
    fprintf(fptr,"%d\n", SIZE);
    for (int i = 0; i < SIZE; ++i) {
      ptr[i].id = i;
      ptr[i].count = rand() % 1000000000;
      if ((i * rand()) % 50 > 30)
        ptr[i].mark.status = 0;
      else
        ptr[i].mark.status = 4607182418800017408 + (rand() % 50);
        int a;
      if (a = fprintf(fptr,"%u %u %lu\n", ptr[i].id, ptr[i].count,ptr[i].mark.status) < 1)
        return -1;
    }
    fclose(fptr);
    free(ptr);
    return 0;
  }
  return -1;
}