#include <gtest/gtest.h>
#include "Test/test_help_file.cpp"
#include "naive_algorithm/naive_algorithm.h"
#include "parallel_algorithm/parallel_algorithm.h"

TEST_F(TestTemplate, Naive_Empty_array) {
  ASSERT_EQ(find_zero_count_naive(NULL, -10), 0);
}

TEST_F(TestTemplate, Naive_Return_value) {
  int count = find_zero_count_naive(comment, size);
    ASSERT_EQ(count, 1796);
}

TEST_F(TestTemplate, test) {
  int parallel = find_zero_count_parallel(comment, size);
  int naive = find_zero_count_parallel(comment, size);
  ASSERT_EQ(parallel, naive);
}