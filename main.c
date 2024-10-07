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

  // open file and add names to deque
  char filename[] = "names.txt";
  FILE* fp = NULL;
  fp = fopen(filename, "r");
  Bool done = false;

  if (fp == NULL) {
    fprintf(stderr, "Cannot open names.txt\n");
    exit(1);
  }

  while(!done) {
    char* name = malloc(20);
    if (fscanf(fp, "%s", name) == 1) {
      push_back(&queue, name);
    }
    else {
      done = true;
    }
  }

  // start of program
  printf("To scroll throughg the names type\n");
  printf("f: forwards, b:backwards, q: quit\n");

  char choice;

  while(choice != 'q') {
    scanf("%c", &choice);

    if(choice == 'f') {
      printf("%s\n", queue.head->data);
      push_back(&queue, pop_front(&queue));
    }

    if(choice == 'b') {
      printf("%s\n", queue.tail->data);
      push_front(&queue, pop_back(&queue));
    }
  }

  printf("Bye !");

  return 0;
}


