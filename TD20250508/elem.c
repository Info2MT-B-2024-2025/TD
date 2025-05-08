#include <stdio.h>
#include "elem.h"

void display_elem(const elem e)
{
    printf(".x = %lf, .y=%lf\n", e.x, e.y);
}