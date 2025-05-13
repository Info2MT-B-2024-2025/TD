#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include "elem.h"
#include "error.h"

#define EXTEND_LIST_SIZE 10
#define THRESHOLD_FOR_DEL 8
typedef struct {

    elem *t; // dynamic size arrray
    size_t size; // total number of elem in t
    size_t count; // number of elem used in t
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
