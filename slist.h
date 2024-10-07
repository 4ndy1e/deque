#ifndef slist_h
#define slist_h

#include <stdio.h>

struct node {
  int data;
  struct node* next;
};

struct singlyLinkedList {
  struct node* head;
  struct node* tail;
};

typedef struct singlyLinkedList SList;

void insertHead(SList* list, char* data);
char* removeHead(SList* list);
void insertTail(SList* list, char* data);
char* removeTail(SList* list);

#endif