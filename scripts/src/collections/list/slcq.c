#ifndef SLQ_c
#define SLQ_C 1

#include "./sll.c"


void slcqFree(SimpleLinkedList* l)
{
    SimpleLinkedNode* n;
    SimpleLinkedNode* a;
    register unsigned int i;

    if(l == NULL)
        return;

    n = l->first;
    for(i = 0; i < l->size; i++)
    {
        a = n->next;
        if(n->data != NULL)
            free(n->data);

        free(n);
        n = a->next;
    }

    free(l);
}

void slcqFreeF(SimpleLinkedList* l, void(*func)(void*))
{
    SimpleLinkedNode* n;
    SimpleLinkedNode* a;
    register unsigned int i;

    if(l == NULL)
        return;

    n = l->first;
    for(i = 0; i < l->size; i++)
    {
        a = n->next;
        if(n->data != NULL)
            func(n->data);

        free(n);
        n = a->next;
    }

    free(l);
}

bool slcqAdd(SimpleLinkedList* l, void* data)
{
    SimpleLinkedNode* n;

    if(l == NULL || data == NULL)
        return false;

    n = (SimpleLinkedNode*)malloc(sizeof(SimpleLinkedNode));
    if(n == NULL)
        return false;

    n->data = data;
    switch (l->size)
    {
        case 0:
            l->first = n;
            l->last = n;
            break;
        case 1:
            l->last->next = n;
            n->next = l->first;
            break;
        default:
            l->last->next->next = n;
            l->last = l->last->next;
            break;
    }

    n->next = l->first;
    l->size++;
    return true;
}

void* slcqPop(SimpleLinkedList* l)
{
    SimpleLinkedNode* n;
    void* data;

    if(l == NULL || l->size == 0)
        return NULL;

    n = l->first;
    data = n->data;
    switch (l->size)
    {
    case 1:
        l->first = NULL;
        l->last = NULL;
        break;
    case 2:
        l->first = l->last;
        l->first->next = l->first;
    default:
        l->last->next = n->next;
        l->first = n->next;
        break;
    }

    l->size--;
    free(n);
    return data;
}

void* slcqSecLast(SimpleLinkedList* l)
{
    if(l == NULL)
        return NULL;

    return l->last;
}


#endif