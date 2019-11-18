#include <malloc.h>
#include <time.h>
#include <dlfcn.h>
//#include "parallel_algorithm/parallel_algorithm.h"
#include "struct.h"
#include <random>


int main()
{
  int size = 0;
  Comment * comment = NULL;
  FILE* fptr = fopen("../test/test_data/input2.txt", "r");
  if (fptr) {
    if (fscanf(fptr, "%d", &size) != 1) {
      fclose(fptr);
      return -1;
    }
    comment = (Comment *) malloc(sizeof(Comment) * (size));
    for (int i = 0; i < size; ++i) {
      if (fscanf(fptr, "%u %u %lu\n", &comment[i].id, &comment[i].count,
                 &comment[i].mark.status) != 3)
        return -1;
    }
    fclose(fptr);

    char* dlpath = "libparallel_algorithm_lib.so";
    void* library = dlopen(dlpath, RTLD_LAZY);
    char* lError = dlerror();
    if (lError) {
      printf(lError);
      return 1;
    }
    typedef int (*find_zero) (const Comment*, int);

    char* func_name = "find_zero_count_parallel";
    find_zero find = (find_zero) dlsym(library, func_name);
    // Do some error checking
    lError = dlerror();
    if (lError)
    {
      // This error ~does~ get hit
      printf("Error: %s\n", lError);
      free(comment);
      dlclose(library);
      return 1;
    }
    int start_t = clock();
    int count = find(comment, size);
    int df_time = clock() - start_t;
    printf("Parallel algorithm\n Result = %d\nExecution_time = %d",count,df_time);
    free(comment);
    dlclose(library);
    return 0;
  }
  return 1;
}
