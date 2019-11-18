#include <malloc.h>
#include <time.h>
#include "naive_algorithm/naive_algorithm.h"

int main() {
  int size = 0;
  Comment * comment = NULL;
  FILE* fptr = fopen("../test/test_data/input2.txt", "r");
  if (fptr) {
    if (fscanf(fptr, "%d", &size) != 1)
    {
      fclose(fptr);
      return 1;
    }
    comment = (Comment *) malloc(sizeof(Comment) * (size));
    for (int i = 0; i < size; ++i) {
      if (fscanf(fptr, "%u %u %lu\n", &comment[i].id, &comment[i].count,
                 &comment[i].mark.status) != 3)
      {
        fclose(fptr);
        return 1;
      }
    }
    fclose(fptr);
  }
    int start_t = clock();
    int count = find_zero_count_naive(comment, size);
    int df_time = clock() - start_t;
    printf("Naive algorithm\nResult = %d\nExecution_time = %d",count,df_time);
    free(comment);
    return 0;
}

