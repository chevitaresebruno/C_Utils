#ifndef SLQ_c
#define SLQ_C 1

#include "./sll.c"


bool slqAdd(SimpleLinkedList* l, void* data)
{
    SimpleLinkedNode* n;

    if(l == NULL || data == NULL)
        return false;

    n = (SimpleLinkedNode*)malloc(sizeof(SimpleLinkedNode));
    if(n == NULL)
        return false;

    n->data = data;
    n->next = NULL;

    if(l->size == 0)
    {
        l->first = n;
        l->last = n;
    }
    else
    {
        l->last->next = n;
        l->last = n;
    }
    l->size++;

    return true;
}

void* slqPop(SimpleLinkedList* l)
{
    SimpleLinkedNode* n;
    void* data;

    if(l == NULL || l->size == 0)
        return NULL;

    n = l->first;

    if(l->size == 1)
    {
        l->first = NULL;
        l->last = NULL;
    }
    else
    {
        l->first = n->next;
    }
    l->size--;

    data = n->data;
    free(n);

    return data;
}


#endif