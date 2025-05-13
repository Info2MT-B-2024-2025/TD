#include <stdio.h>
#include "stack.h"

int main(int argc, const char *argv[])
{

	stack s;
	init_stack(&s);

	elem e = 10;
	push(&s, e);
	e = 20;
	push(&s, e);
	e = 30;
	push(&s, e);
	
	pop(&s,&e);
	display_elem(e); // 30
	pop(&s,&e);
	display_elem(e); // 20
	pop(&s,&e);
	display_elem(e); // 10
	return 0;
}
