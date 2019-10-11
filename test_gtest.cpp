#include <gtest/gtest.h>
#include <stdio.h>
#include <unistd.h>
#include "my_task.h"

TEST(task, is_less) {
  struct Airplane first = {"abc", "cd", "qwerty", 1, 2};
  struct Airplane second = {"abc", "cd", "qwerty", 1, 3};
  ASSERT_TRUE(is_less(&first, &second));
}

TEST(task, size_0) {
  ASSERT_THROW(merge_sort(NULL, 0, is_less), std::runtime_error);
}

TEST(task, merge_sort) {
  FILE *input_file;
  char name[] = "../tests/mytestinput.txt";

  struct Airplane *input_array = NULL;
  int size = 0;

  if ((input_file = fopen(name, "r")) != NULL) {
    fscanf(input_file, "%d", &size);
    input_array = (struct Airplane *)malloc(size * sizeof(struct Airplane));
    for (int i = 0; i < size; ++i) {
      fscanf(input_file, "%20s %20s %20s %d %d", input_array[i].brand,
             input_array[i].model, input_array[i].appointment,
             &input_array[i].crew_number, &input_array[i].range);
    }
    merge_sort(input_array, size, &is_less);
    fclose(input_file);
  } else {
    printf("Input file error!");
    ASSERT_TRUE(false) << "first file error (file PATH error)";
  }

  FILE *output_file;
  char name2[] = "../tests/output.txt";  //../tests/output.txt
  struct Airplane *output_array = NULL;
  if ((output_file = fopen(name2, "r")) != NULL) {
    output_array = (struct Airplane *)malloc(size * sizeof(struct Airplane));
    for (int i = 0; i < size; ++i) {
      if (fscanf(output_file, "%20s %20s %20s %d %d", output_array[i].brand,
                 output_array[i].model, output_array[i].appointment,
                 &output_array[i].crew_number, &output_array[i].range) == 5) {
        EXPECT_STREQ(input_array[i].brand, output_array[i].brand)
            << i << "-th of " << size << " not Equal brand";
        EXPECT_STREQ(input_array[i].model, output_array[i].model)
            << i << "-th of " << size << " not Equal model";
        EXPECT_STREQ(input_array[i].appointment, output_array[i].appointment)
            << i << "-th of " << size << " not Equal appointment";
        EXPECT_EQ(input_array[i].crew_number, output_array[i].crew_number)
            << i << "-th of " << size << " not Equal crew number";
        EXPECT_EQ(input_array[i].range, output_array[i].range)
            << i << "-th of " << size << " not Equal range";
      } else {
        ASSERT_TRUE(false) << "Second file output error" << i;
      }
    }
    fclose(output_file);
  } else {
    printf("Input file error!");
    ASSERT_TRUE(false) << "Second file error (file PATH error)";
  }

  if (input_array) free(input_array);
  if (output_array) free(output_array);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}