#ifndef SLN_c
#define SLN_C 1

#include "./../../../inc/shared.h"


typedef struct sln SimpleLinkedNode;

struct sln
{
    void* data;
    SimpleLinkedNode* next;
};


SimpleLinkedNode* slnBuild()
{
    SimpleLinkedNode* n = (SimpleLinkedNode*)malloc(sizeof(SimpleLinkedNode));

    if(n == NULL)
        return NULL;

    n->data = NULL;
    n->next = NULL;

    return n;
}


void slnFree(SimpleLinkedNode* n)
{
    if(n != NULL)
    {
        if(n->data != NULL)
            free(n->data);
        free(n);
    }
}

void slnFreeSq(SimpleLinkedNode* n)
{
    SimpleLinkedNode* a;

    while (n != NULL)
    {
        a = n->next;
        if(n->data != NULL)
            free(n->data);
        free(n);
        n = a;
    }
}

void slnFreeSqF(SimpleLinkedNode* n, void(*func)(void*))
{
    SimpleLinkedNode* a;

    while (n != NULL)
    {
        a = n->next;
        if(n->data != NULL)
            func(n->data);
        free(n);
        n = a;
    }
}


#endif