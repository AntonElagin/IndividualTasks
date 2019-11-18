#ifndef INDIVIDUALTASK2_STRUCT_H
#define INDIVIDUALTASK2_STRUCT_H

union avg_mark {
  long unsigned int status;
  double mark;
};

typedef struct Comment Comment;
struct Comment {
  unsigned int id;
  unsigned int count;
  union avg_mark mark;
};

#endif  // INDIVIDUALTASK2_STRUCT_H
