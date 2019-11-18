#include <gtest/gtest.h>
#include "Test/test_help_file.cpp"
#include "parallel_algorithm/parallel_algorithm.h"


TEST_F(TestTemplate, Parallel_Return_value) {
int count = find_zero_count_parallel(comment, size);
ASSERT_EQ(count, 1796);
}

TEST_F(TestTemplate, Parallel_Empty_array) {
ASSERT_EQ(find_zero_count_parallel(NULL, -10), 0);
}
