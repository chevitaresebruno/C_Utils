#ifndef SLQUEUE_H
#define SLQUEUE_H 1

#include "./Collections.h"


typedef struct sll* SimpleLinkedQueue;

SimpleLinkedQueue sllBuild();

void sllFree(SimpleLinkedQueue queue);

void sllFreeF(SimpleLinkedQueue queue, DeallocFunction function);

void sllForeach(SimpleLinkedQueue queue, ForeachFunction function);

unsigned int sllSize(const SimpleLinkedQueue queue);

bool sllEmpty(const SimpleLinkedQueue queue);

void* sllFirst(SimpleLinkedQueue queue);

void* sllLast(SimpleLinkedQueue queue);

void* sllGetAt(SimpleLinkedQueue queue, const unsigned int index);

void* sllReplace(SimpleLinkedQueue queue, void* data, const unsigned int index);

void sllReplaceS(SimpleLinkedQueue queue, void* data, const unsigned int index, DeallocFunction function);

void* sllPopAt(SimpleLinkedQueue queue, const unsigned int index);

bool slqAdd(SimpleLinkedQueue queue, void* data);

void* slqPop(SimpleLinkedQueue queue);


#endif