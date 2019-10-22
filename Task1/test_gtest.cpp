#include <gtest/gtest.h>

#include "MyTask.h"
#include <stdio.h>

#include <limits.h>
#include <stdio.h>
#include <unistd.h>

bool operator==(const struct Airplane a, const struct Airplane b) {
  return (!strcmp(a.brand, b.brand) && !strcmp(a.appointment, b.appointment) &&
          !strcmp(a.model, b.model) && (a.crew_number == b.crew_number) &&
          (a.range == b.range));
}

bool is_equally(const struct Airplane *a, const struct Airplane *b, int size) {
  if (size) {
    for (int i = 0; i < size; ++i) {
      if (!(a[i] == b[i]))
        return false;
    }
    return true;
  }
  return false;
}

TEST(task, is_less) {
  struct Airplane a = {"abc", "cd", "qwerty", 1, 2};
  struct Airplane b = {"abc", "cd", "qwerty", 1, 3};
  ASSERT_TRUE(is_less(&a, &b));
}

TEST(task, sort) {
  FILE *input_file;
  char name[] = "../tests/mytestinput.txt";
  char buffer[255];

  getcwd(buffer, sizeof(buffer));

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
  } else
    ASSERT_TRUE(false) << "first file error";


  FILE *output_file;
  char name2[] = "../tests/output.txt";
  struct Airplane *output_array =
      (struct Airplane *)malloc(size * sizeof(struct Airplane));
  if ((output_file = fopen(name2, "r")) != NULL) {

    for (int i = 0; i < size; ++i) {
      fscanf(input_file, "%20s %20s %20s %d %d", output_array[i].brand,
             output_array[i].model, output_array[i].appointment,
             &output_array[i].crew_number, &output_array[i].range);
    }
    fclose(output_file);
  } else
    ASSERT_TRUE(false) << "first file error";


  ASSERT_TRUE(is_equally(input_array, output_array, size)) << "sort error";
  if (input_array)
    free(input_array);
  if (output_array)
  free(output_array);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}