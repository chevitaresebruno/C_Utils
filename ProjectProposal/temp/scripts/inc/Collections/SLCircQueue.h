#ifndef SLCIRCQUEUE_H
#define SLCIRCQUEUE_H 1

#include "./Collections.h"


SimpleLinkedCircularQueue sllBuild();

void slcqFree(SimpleLinkedCircularQueue* l);

void slcqFreeF(SimpleLinkedCircularQueue queue, DeallocFunction function);

void sllForeach(SimpleLinkedCircularQueue queue, ForeachFunction function);

unsigned int sllSize(const SimpleLinkedCircularQueue queue);

bool sllEmpty(const SimpleLinkedCircularQueue queue);

void* sllFirst(SimpleLinkedCircularQueue queue);

void* slcqSecLast(SimpleLinkedCircularQueue queue);

void* sllGetAt(SimpleLinkedCircularQueue queue, const unsigned int index);

void* sllReplace(SimpleLinkedCircularQueue queue, void* data, const unsigned int index);

void* sllPopAt(SimpleLinkedCircularQueue queue, const unsigned int index);

bool slcqAdd(SimpleLinkedCircularQueue queue, void* data);

void* slcqPop(SimpleLinkedCircularQueue queue);


#endif