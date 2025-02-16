#ifndef SLL_c
#define SLL_C 1

#include "./../nodes/sln.c"


struct sll
{
    SimpleLinkedNode* first;
    SimpleLinkedNode* last;
    unsigned int size;
};


SimpleLinkedList* sllBuild()
{
    SimpleLinkedList* l = (SimpleLinkedList*)malloc(sizeof(SimpleLinkedList*));

    if(l == NULL)
        return NULL;

    l->first = NULL;
    l->last = NULL;
    l->size = 0;

    return l;
}

void sllFree(SimpleLinkedList* l)
{
    if(l == NULL)
        return;

    slnFreeSq(l->first);
    free(l);
}

void sllFreeF(SimpleLinkedList* l, void(*func)(void*))
{
    if(l == NULL || func == NULL)
        return;

    slnFreeSqF(l->first, func);
    free(l);
}

void sllForach(SimpleLinkedList* l, void(*func)(void*))
{
    SimpleLinkedNode* n;
    if(l == NULL || func == NULL)
        return;

    for(n = l->first; n != NULL; n = n->next)
    {
        func(n->data);
    }
}

unsigned int sllSize(const SimpleLinkedList* l)
{
    if(l == NULL)
        return 0;

    return l->size;
}

bool sllEmpty(const SimpleLinkedList* l)
{
    if(l == NULL)
        return false;

    return l->size == 0;
}

void* sllFirst(SimpleLinkedList* l)
{
    if(l == NULL)
        return NULL;

    return l->first->data;
}

void* sllLast(SimpleLinkedList* l)
{
    if(l == NULL)
        return NULL;

    return l->last->data;
}

void* sllGetAt(SimpleLinkedList* l, const unsigned int i)
{
    register unsigned int c = i;
    SimpleLinkedNode* n;

    if(l == NULL || l->size < i)
        return NULL;

    for(n = l->first; c > 0; c--)
        { n = n->next; }

    return n->data;
}

void* sllReplace(SimpleLinkedList* l, void* data, const unsigned int i)
{
    register unsigned int c = i;
    SimpleLinkedNode* n;
    void* d;

    if(l == NULL || data == NULL || l->size < i)
        return NULL;

    for(n = l->first; c > 0; c--)
        { n = n->next; }

    d = n->data;
    n->data = data;
    return d;
}

void sllReplaceS(SimpleLinkedList* l, void* data, const unsigned int i, void(*func)(void*))
{
    void* d = sllReplace(l, data, i);
    if(d != NULL)
        func(d);
}

void* sllPopAt(SimpleLinkedList* l, const unsigned int i)
{
    register unsigned int c = i;
    SimpleLinkedNode* n;
    SimpleLinkedNode* a;
    void* data;

    if(l == NULL || l->size < i)
        return NULL;

    for(n = l->first; c > 1; c--)
        { n = n->next; }
    
    l->size--;

    a = n;
    n = n->next;
    a->next = n->next;
    data = n->data;
    free(n);

    return data;
}


#endif