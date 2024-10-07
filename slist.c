#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

void insertHead(SList* list, char* data) {
  // create new node and allocate memory on heap
  struct node* newNode;
  newNode = malloc(sizeof(struct node));

  // insert new node at head with other nodes behind it
  newNode->data = data;
  newNode->next = list->head;
  list->head = newNode;

  // set tail as newNode if NULL (for first insert)
  if(list->tail == NULL) {
    list->tail = newNode;
  }
}

char* removeHead(SList* list) {
  // check to see if head is empty
  if(list->head == NULL) {
    return NULL;
  }

  // store data of current head and remove
  struct node* currentHead = list->head;
  list->head = list->head->next;

  // free memory of removed head
  free(currentHead);

  // if new head is null, update tail to be null
  if(list->head == NULL) {
    list->tail = NULL;
  }

  return currentHead->data;
}

void insertTail(SList* list, char* data) {
  // create new node and allocate memory
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = data;

  newNode->next = NULL;

  // check if list is empty
  if(list->head == NULL) {
    list->head = newNode;
    list->tail = newNode;
    return;
  }

  // if not empty, insert node at tail
  list->tail->next = newNode;
  list->tail = newNode;
}

char* removeTail(SList* list) {
  // check if list is empty
  if(list->tail == NULL) {
    return NULL;
  }

  // store old tail to return later
  struct node* currentTail = list->tail;

  // check if list only had one node
  if(list->head == list->tail) {
    list->head = NULL;
    list->tail = NULL;
    free(currentTail);
    return currentTail->data;
  }

  // find the second to last node
  struct node* currentNode = list->head;
  while(currentNode->next->next != NULL) {
    currentNode = currentNode->next;
  }

  // remove old tail by setting second to last node as new tail
  currentNode->next = NULL;
  list->tail = currentNode;
  free(currentTail);

  return currentTail->data;
}
