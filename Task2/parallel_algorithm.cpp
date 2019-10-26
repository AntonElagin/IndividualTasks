//
// Created by anton on 20.10.2019.
//

#include <wait.h>
#include "parallel_algorithm.h"

int find_zero_count_parallel(const Comment* array, int arr_size) {
  size_t process_count = 4;
  pid_t * child = (pid_t*) malloc(4 * sizeof(pid_t));
  //pid_t child[4];
  int return_counter = 0;
  int fd[2], status;
  pipe(fd);
  for (int i = 0; i < process_count; ++i) {
    int delta = arr_size / process_count;
    if ((child[i] = fork()) < 0) {
      free(child);
      return -1;
    }
    else if (child[i] == 0) {
      int counter = find_zero_count(array, i * delta, (i + 1) * delta);
      close(fd[0]);
      write(fd[1], &counter, sizeof(int));
      exit(EXIT_SUCCESS);
    }
  }

  for (int j = 0; j < process_count; ++j) {
    int count = 0;
    close(fd[1]);
    read(fd[0], &count, sizeof(int));
    return_counter += count;
    waitpid(child[j],&status,WNOHANG);
  }

  free(child);
  return return_counter;
}

int find_zero_count(const Comment* array, int low, int high) {
  int zero_counter = 0;
  for (int j = low; j < high; ++j) {
    if (array[j].mark.status == 0) ++zero_counter;
  }
  return zero_counter;
}
