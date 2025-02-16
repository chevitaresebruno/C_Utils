#ifndef STACK_H
#define STACK_H 1


#include "./Collections.h"

typedef struct stack* Stack;

Stack stackBuild();
void stackFree(Stack s);
void stackFreeF(Stack s, DeallocFunction function);
bool stackAdd(Stack* s, void* data);
void* stackPop(Stack* s);

#endif