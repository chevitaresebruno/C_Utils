#ifndef COLLECTIONS_H
#define COLLECTIONS_H 1

#include "./../shared.h"


typedef void(*ForeachFunction)(const void*);
typedef void(*DeallocFunction)(void*);

typedef struct sll SimpleLinkedList;
typedef struct SimpleLinkedList* SimpleLinkedQueue;
typedef struct SimpleLinkedList* SimpleLinkedCircularQueue;
typedef struct stack* Stack;


#endif