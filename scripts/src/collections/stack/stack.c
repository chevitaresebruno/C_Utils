#ifndef STACK_C
#define STACK_C 1

#include "./../nodes/sln.c"


typedef struct stack
{
    SimpleLinkedNode* top;    
    unsigned int size;
} Stack;


Stack* stackBuild()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    
    if(s == NULL)
        return NULL;

    s->top = NULL;
    s->size = 0;

    return s;
}

void stackFree(Stack* s)
{
    if(s == NULL)
        return;
    
    slnFreeSq(s->top);
    free(s);
}

void stackFreeF(Stack* s, void(*func)(void*))
{
    if(s == NULL || func == NULL)
        return;

    slnFreeSqF(s->top, func);
    free(s);
}

bool stackAdd(Stack* s, void* data)
{
    if(s == NULL || data == NULL)
        return false;

    SimpleLinkedNode* n = (SimpleLinkedNode*)malloc(sizeof(SimpleLinkedNode));
    if(n == NULL)
        return false;

    n->data = data;
    if(s->size == 0)
        { s->top = n; }
    else
    {
        n->next = s->top;
        s->top = n;
    }

    s->size++;
}

void* stackPop(Stack* s)
{
    SimpleLinkedNode* n;
    void* data;
    if(s == NULL)
        return NULL;

    n = s->top;
    data = n->data;
    s->top = n->next;
    s->size--;
    free(n);

    return data;
}


#endif