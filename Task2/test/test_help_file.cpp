#include <gtest/gtest.h>
#include "struct.h"


class TestTemplate : public  ::testing::Test
{
protected:
  static Comment * comment;
  static int size;

  void SetUp() override {
    FILE* fptr = fopen("../Test/test_data/input2.txt", "r");
    if (fptr) {
      fscanf(fptr, "%d", &size);
      comment = new Comment [size]; //(Comment*) malloc(sizeof(Comment) * (size));
      for (int i = 0; i < size; ++i) {
        fscanf(fptr, "%u %u %lu\n", &comment[i].id, &comment[i].count,
               &comment[i].mark.status);
      }
      fclose(fptr);
    }
  }

  void  TearDown() override
  {
    delete [] comment;
  }
};