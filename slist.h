#ifndef SLIST_H
#define SLIST_H

typedef struct node {
    char* data;
    struct node* next;
} Node;

struct singlyLinkedList {
    Node* head;
    Node* tail;
};

typedef struct singlyLinkedList SList;
typedef struct singlyLinkedList Deque;
typedef enum { false, true } Bool;

void insertHead(SList* list, char* data);
char* removeHead(SList* list);
void insertTail(SList* list, char* data);
char* removeTail(SList* list);

#endif