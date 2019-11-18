#include "naive_algorithm/naive_algorithm.h"
#include "parallel_algorithm/parallel_algorithm.h"
#include "test/test_help_file.h"

TEST_F(TestTemplate, Naive_Empty_array) {
  ASSERT_EQ(find_zero_count_naive(NULL, -10), 0);
}

TEST_F(TestTemplate, Naive_Return_value) {
  ASSERT_EQ(find_zero_count_naive(comment, size), TrueResult);
}

TEST_F(TestTemplate, test) {
  int parallel = find_zero_count_parallel(comment, size);
  int naive = find_zero_count_parallel(comment, size);
  ASSERT_EQ(parallel, naive);
}

TEST_F(TestTemplate, naive_alg) {
  find_zero_count_naive(comment, size);
  ASSERT_EQ(1, 1);
}