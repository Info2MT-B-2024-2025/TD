#include <stdio.h>
#include "list.h"

error_code init_list(list *l)
{
    if (NULL == l)
        return BAD_LIST;
    l->t = NULL;
    l->size = 0;
    l->count = 0;
    return NO_ERROR;
}

void display_list(const list l)
{
    printf("size =%lu element(s)\n", l.size);
    printf("count=%lu element(s)\n", l.count);
    for (size_t index = 0; index < l.count; index++)
    {
        elem e = l.t[index];
        display_elem(e);
    }
}
error_code insert_list(list *l, const elem e, const size_t pos)
{
    if (NULL == l)
        return BAD_LIST;
    if (pos > l->count)
        return BAD_POS;
    if (is_full(*l))
    {
        elem *tmp = (elem *)realloc(l->t, (EXTEND_LIST_SIZE + l->size) * sizeof(elem));
        if (NULL == tmp)
        {
            return LIST_FULL;
        }
        l->t = tmp;
        l->size += EXTEND_LIST_SIZE;
    }
    for (size_t index = l->count; index > pos; index--)
        l->t[index] = l->t[index - 1];
    l->t[pos] = e;
    l->count++;
    return NO_ERROR;
}
error_code delete_elem(list *l, const size_t pos)
{
    if (NULL == l)
        return BAD_LIST;
    if (is_empty(*l))
        return LIST_EMPTY;
    if (pos >= l->count)
        return BAD_POS;
    if (l->count > 1)
        for (size_t index = pos; index <= l->count - 2; index++)
            l->t[index] = l->t[index + 1];

    l->count--;

    if ((l->size - l->count) > THRESHOLD_FOR_DEL)
    {
        // realloc to remove extra roon in l->t
        elem *tmp = (elem *)realloc(l->t, (l->size - THRESHOLD_FOR_DEL) * sizeof(elem));
        if (NULL == tmp)
        {
            return ERROR_DESALLOC;
        }
        l->t = tmp;
        l->size -= THRESHOLD_FOR_DEL;
    }

    return NO_ERROR;
}
bool search_elem(const list l, const elem e, size_t *pos)
{
    return false;
}
bool is_empty(const list l)
{
    return l.count == 0;
}
bool is_full(const list l)
{
    return l.count == l.size;
}
size_t get_count(const list l)
{
    return l.count;
}
error_code get_elem(const list l, const size_t pos, elem *e)
{
    if (pos > l.count)
        return BAD_POS;

    *e = l.t[pos];
    return NO_ERROR;
}
