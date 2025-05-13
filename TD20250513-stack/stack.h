#pragma once

#include "elem.h"
#include "error.h"
#include "list.h"

typedef list stack;

error_code init_stack(stack *q);
error_code push(stack *q, const elem e);
error_code pop(stack *q, elem *e);