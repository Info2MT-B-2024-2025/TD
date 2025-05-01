#include <stdio.h>
#include "list.h"

error_code init_list(list *l)
{
    if (NULL == l)
        return BAD_LIST;
    l->count = 0;
    return NO_ERROR;
}

void display_list(const list l)
{
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

    return NO_ERROR;
}
error_code delete_elem(list *l, const size_t pos)
{
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
    return l.count >= MAX_LIST_SIZE;
}
size_t get_count(const list l)
{
    return l.count;
}
error_code get_elem(const list l, const size_t pos, elem *e)
{
    return NO_ERROR;
}
