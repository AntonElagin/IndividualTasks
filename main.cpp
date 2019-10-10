#include "MyTask.h"
#include <assert.h>


void task_console_test() {
  printf("Input size:\n");
  int size;
  assert(scanf("%d", &size) == 1);
  struct Airplane *airplane_array =
      (struct Airplane *)malloc(size * sizeof(struct Airplane));

  for (size_t i = 0; i < size; i++) {
    assert(scanf("%20s %20s %20s %d %d", airplane_array[i].brand,
                 airplane_array[i].model, airplane_array[i].appointment,
                 &airplane_array[i].crew_number,
                 &airplane_array[i].range) == 5);
  }
  // Сортировка
  merge_sort(airplane_array, size, is_less);
  //
  printf("Output data:\n");
  for (size_t i = 0; i < size; i++) {
    printf("%s %s %s %d %d\n", airplane_array[i].brand, airplane_array[i].model,
           airplane_array[i].appointment, airplane_array[i].crew_number,
           airplane_array[i].range);
  }

  //free(airplane_array);
}

int main() {
  task_console_test();
  return 0;
}