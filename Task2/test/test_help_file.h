#ifndef INDIVIDUALTASK2_TEST_HELP_FILE_H
#define INDIVIDUALTASK2_TEST_HELP_FILE_H

#include <gtest/gtest.h>
#include "struct.h"

class TestTemplate : public ::testing::Test {
 private:
  static int generate_comment_array(int size, const char* file_name);

 protected:
 public:
  TestTemplate(Comment* comment);

  TestTemplate();

 protected:
  static void SetUpTestCase();
  static void TearDownTestCase();

  static Comment* comment;
  static int size;
  static int TrueResult;
};

#endif  // INDIVIDUALTASK2_TEST_HELP_FILE_H
