#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

error_code init_list(list *l)
{
    if (NULL == l)
        return BAD_LIST;

    l->first = NULL;
    l->last = NULL;
    l->count = 0;
    return NO_ERROR;
}

void display_list(const list l)
{
    printf("count=%lu\n", l.count);

    // display_elem(l.first->e);
    // node *n = l.first;
    // display_elem(n->e);
    // n = n->next;
    // display_elem(n->e);
    // n = n->next;
    // display_elem(n->e);

    node *n = l.first;
    size_t index = 0;
    for (index = 0; index < l.count; index++)
    {
        display_elem(n->e);
        n = n->next;
    }
}

error_code insert_list(list *l, elem e, size_t pos)
{
    if (NULL == l)
        return BAD_LIST;

    node *n = (node *)malloc(sizeof(node));
    printf("alloc: %p\n",n);
    if (NULL == n)
        return ERROR_ALLOC;
    memcpy(&(n->e), &e, sizeof(elem));
    n->prev = NULL;
    n->next = NULL;

    if (0 == l->count)
    { // insert first elem in empty list
        l->first = n;
        l->last = n;
        l->count++;
        return NO_ERROR;
    }
    // here, list is not empty...
    if (0 == pos)
    { // insert at pos=0,
        l->first->prev = n;
        n->next = l->first;
        l->first = n;
        l->count++;
        return NO_ERROR;
    }
    // insert at pos=l->count
    if (l->count == pos)
    { // insert at pos=end,
        l->last->next = n;
        n->prev = l->last;
        l->last = n;
        l->count++;
        return NO_ERROR;
    }

    node *before = l->first;
    node *after;
    for (size_t index = 0; index < pos - 1; index++)
    {
        before = before->next;
    }
    after = before->next;
    n->prev = before;
    n->next = after;
    before->next = n;
    after->prev = n;
    l->count++;

    return NO_ERROR;
}

error_code free_list(list *l)
{
    if (NULL == l)
        return BAD_LIST;

    node *n=l->first;
    for(size_t index=0;index<l->count-1;index++) {
        n=n->next;
        printf("free:  %p\n",n->prev);
        free(n->prev);
    }
    printf("free:  %p\n",n);
    free(n);

    init_list(l);
    return NO_ERROR;
}