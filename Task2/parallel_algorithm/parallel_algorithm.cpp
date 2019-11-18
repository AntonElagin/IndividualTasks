#include "parallel_algorithm.h"
#include <sys/sysinfo.h>
#include <wait.h>

int find_zero_count(const Comment* array, int low, int high) {
  int zero_counter = 0;
  for (int j = low; j < high; ++j) {
    if (array[j].mark.status == 0) ++zero_counter;
  }
  return zero_counter;
}

int find_zero_count_parallel(const Comment* array, int arr_size) {
  if (!array && arr_size <= 0) return 0;
  const size_t process_count = get_nprocs_conf();
  if (process_count == 0) return -1;
  pid_t* child = (pid_t*)malloc(process_count * sizeof(pid_t));
  if (!child) return -1;
  int return_counter = 0;
  int fd[2], status;
  if (pipe(fd) == -1) {
    free(child);
    return -1;
  }
  for (int i = 0; i < process_count; ++i) {
    int delta = arr_size / process_count;
    int residue = arr_size % process_count;
    if ((child[i] = fork()) < 0) {
      free(child);
      return -1;
    } else if (child[i] == 0) {
      int counter;
      if (i == process_count - 1)
        counter = find_zero_count(array, i * delta, arr_size);
      else
        counter = find_zero_count(array, i * delta, (i + 1) * delta);
      close(fd[0]);
      write(fd[1], &counter, sizeof(int));
      exit(EXIT_SUCCESS);
    }
  }

  close(fd[1]);
  for (int j = 0; j < process_count; ++j) {
    int count = 0;
    read(fd[0], &count, sizeof(int));
    return_counter += count;
    waitpid(child[j], &status, WNOHANG);
  }

  free(child);
  return return_counter;
}
