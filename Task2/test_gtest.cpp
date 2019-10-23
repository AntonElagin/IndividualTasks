#include <locale.h>
#include <gtest/gtest.h>
#include <stdio.h>
#include <unistd.h>
#include "parallel_algorithm.h"
#include "naive_algorithm.h"

int get_comment_array(Comment ** return_ptr, int * return_size,const char* file_name) {
  if (*return_ptr)
    return -1;
  FILE * fptr = fopen(file_name, "r");
  if (fptr) {
    fscanf(fptr, "%d", return_size);
    if (!(*return_ptr = (Comment*) malloc(sizeof(Comment) * (*return_size))))
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
  FILE * fptr = fopen(file_name, "w");
  if (fptr) {
    int SIZE = size;
    srand(time(0));
    Comment * ptr =  (Comment*) malloc(sizeof(Comment)* SIZE);
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

TEST(Naive, Empty_array) {
  ASSERT_EQ(find_zero_count_naive(NULL,-10), 0);
}

TEST(Naive,Return_value) {

  Comment * ptr = NULL;
  int size;
  if (!get_comment_array(&ptr, &size, "../Test/input2.txt")) {
    int count = find_zero_count_naive(ptr, size);
    ASSERT_EQ(count, 1796);
    free(ptr);
  }
}

TEST(Parallel,Return_value) {
  Comment * ptr = NULL;
  int size;
  if (!get_comment_array(&ptr, &size, "../Test/input2.txt")) {
    int count = find_zero_count_parallel(ptr, size);
    ASSERT_EQ(count, 1796);
    free(ptr);
  }
}

TEST(Parrallel, Empty_array) {
  ASSERT_EQ(find_zero_count_parallel(NULL,-10), 0);
}

TEST(Naive_and_Parallel,test) {
  Comment * ptr = NULL;
  int size;
  if (!get_comment_array(&ptr, &size, "../Test/input2.txt")) {
    int parallel = find_zero_count_parallel(ptr, size);
    int naive = find_zero_count_parallel(ptr, size);
    ASSERT_EQ(parallel, naive);
    free(ptr);
  }
}

int main(int argc, char *argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
