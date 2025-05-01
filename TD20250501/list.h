#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include "elem.h"
#include "error.h"

#define MAX_LIST_SIZE 10

typedef struct {

    elem t[MAX_LIST_SIZE];
    size_t count;
} list;

error_code init_list(list *l);
void display_list(const list l);
error_code insert_list(list *l, const elem e, const size_t pos);
error_code delete_elem(list *l, const size_t pos);
bool search_elem(const list l, const elem e, size_t *pos);
bool is_empty(const list l);
bool is_full(const list l);
size_t get_count(const list l);
error_code get_elem(const list l, const size_t pos, elem *e);
