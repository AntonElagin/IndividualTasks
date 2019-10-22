//
// Created by anton on 20.10.2019.
//

#include "parallel_algorithm.h"



int find_zero_count_parallel(const Comment* array, int arr_size, int process_count) {
  pid_t child;
  int return_counter = 0;
  for (int i = 0; i < process_count; ++i) {
    int fd[2];
    int delta = arr_size / process_count;
    pipe(fd);
    if ((child = fork()) < 0)
      return -1;
    else if (child == 0) {
      int counter = find_zero_count(array, i * delta , (i + 1 ) * delta);
      close(fd[0]);
      write(fd[1], &counter, sizeof(int));
      exit(EXIT_SUCCESS);
    } else {
      int count = 0;
      close(fd[1]);
      read(fd[0], &count , sizeof(int));
      return_counter += count;
    }
  }

  return return_counter;
}



int find_zero_count(const Comment * array, int low, int high) {
    int zero_counter = 0;
    for (int j = low; j < high; ++j) {
      if (array[j].mark.status == 0)
        ++zero_counter;
    }
    return zero_counter;
}

size_t find_core_num(){
  size_t core_num = system("cat /proc/cpuinfo|grep processor|wc -l");
  assert(core_num < MAX_CORES);
  return core_num;
}
