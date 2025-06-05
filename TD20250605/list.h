#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "elem.h"
#include "error.h"

typedef struct node {

    struct node *prev; // address of previous node in the list
    struct node *next; // address of next node in the list
    elem e; // the element itself

} node;

typedef struct {

    node *first; // address of first node in the list
    node *last;  // address of last node in the list
    size_t count;// number of nodes in the list

} list;

error_code init_list(list *l);
void display_list(const list l);
error_code insert_elem(list* l, elem e, size_t pos);
error_code free_list(list *l);

error_code get_elem(const list l, elem *e, size_t pos);
bool is_list_empty(const list l);

error_code remove_elem(list *l, const size_t pos);

