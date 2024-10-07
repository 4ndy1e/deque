#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

void push_back(Deque* q, char* data) {
  insertTail(q, data);
}

void push_front(Deque* q, char* data) {
  insertHead(q, data);
}

char* pop_back(Deque* q) {
  return removeTail(q);
}

char* pop_front(Deque* q) {
  return removeHead(q);
}

int main() {
  Deque queue = {NULL, NULL};

  push_front(&queue, "Andy");
  push_front(&queue, "Andy");
  push_front(&queue, "Kelly");

  // print list
  struct node* tmp = queue.head;

  while(tmp != NULL) {
    printf("%s->", tmp->data);
    tmp = tmp->next;
  }
  printf("NULL\n");

  return 0;
}

// to run file
// gcc main.c slist.c -o main
// ./main

// read names from a text file and push names onto the back of a deque

// 'f' to move forward
// 'b' to move backwards
// 'q' to quit

// 'f' - display the name currently at front of queue by popping it and pushing it on the back of queue

// 'b' - similiar but in other direction

