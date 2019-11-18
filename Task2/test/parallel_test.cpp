#include "test/test_help_file.h"
#include "parallel_algorithm/parallel_algorithm.h"
#pragma once



TEST_F(TestTemplate, Parallel_Return_value) {
int count = find_zero_count_parallel(comment, size);
ASSERT_EQ(count, TrueResult);
}

TEST_F(TestTemplate, Parallel_Empty_array) {
ASSERT_EQ(find_zero_count_parallel(NULL, -10), 0);
}
