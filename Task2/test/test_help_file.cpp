#include "test_help_file.h"

void TestTemplate::SetUp() {
  TrueResult = generate_comment_array(10000,"../test/test_data/input2.txt");
  FILE* fptr = fopen("../test/test_data/input2.txt", "r");
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

void TestTemplate::TearDown() {
  remove("../test/test_data/input2.txt");
  delete [] comment;
}

int TestTemplate::generate_comment_array(int size, const char* file_name) {
  FILE* fptr = fopen(file_name, "w");
  if (fptr) {
    int counter = 0;
    int SIZE = size;
    srand(time(0));
    Comment* ptr = (Comment*)malloc(sizeof(Comment) * SIZE);
    if (!ptr) {
      fclose(fptr);
      return -1;
    }
    fprintf(fptr, "%d\n", SIZE);
    for (int i = 0; i < SIZE; ++i) {
      ptr[i].id = i;
      ptr[i].count = rand() % 1000000000;
      if ((i * rand()) % 50 > 30) {
        ptr[i].mark.status = 0;
        ++counter;
      } else
        ptr[i].mark.status = 4607182418800017408 + (rand() % 50);
      if (fprintf(fptr, "%u %u %lu\n", ptr[i].id, ptr[i].count,
                  ptr[i].mark.status) < 1){
        free(ptr);
        fclose(fptr);
        return -1;
      }

    }
    free(ptr);
    fclose(fptr);
    return counter;
  }
  return -1;
}