#include <gtest/gtest.h>

#include "MyTask.h"
#include <stdio.h>

TEST(task, sort) {

  ASSERT_EQ(6, 6);
}

TEST(test_case_name, test_name)
{
  ASSERT_EQ(1, 1) << "1 is not equal 0";
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}