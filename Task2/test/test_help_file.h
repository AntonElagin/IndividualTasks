#ifndef INDIVIDUALTASK2_TEST_HELP_FILE_H
#define INDIVIDUALTASK2_TEST_HELP_FILE_H

#include <gtest/gtest.h>
#include "struct.h"

class TestTemplate : public  ::testing::Test
{
private:
  int generate_comment_array(int size, const char* file_name);
protected:
  Comment * comment;
  int size;
  int TrueResult;
  void SetUp() override;
  void  TearDown() override;
};

#endif //INDIVIDUALTASK2_TEST_HELP_FILE_H
