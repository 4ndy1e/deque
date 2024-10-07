#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

// struct Deque {

// }

// void push_back(Deque* q, char* data) {
  
// }

// void push_front(Deque* q, char* data) {
  
// }

// char* pop_back(Deque* q) {
  
// }

// char* pop_front(Deque* q) {
  
// }

int main() {
  SList list = {NULL, NULL};

  insertHead( &list, "Andy");
  insertHead( &list, "Kelly");

  // print list
  struct node* tmp = list.head;

  while(tmp != NULL) {
    printf("%s->", tmp->data);
    tmp = tmp->next;
  }
  printf("NULL\n");


  return 0;
}

// read names from a text file and push names onto the back of a deque

// 'f' to move forward
// 'b' to move backwards
// 'q' to quit

// 'f' - display the name currently at front of queue by popping it and pushing it on the back of queue

// 'b' - similiar but in other direction

