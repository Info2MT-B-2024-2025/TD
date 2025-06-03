#include "list.h"
int main(int argc, const char *argv[])
{
	list l;
	init_list(&l);
	display_list(l);

	elem e = {.x = 1., .y = 2};
	insert_list(&l, e, 0);
	display_list(l);

	e.x = -1.;
	e.y = 0.;
	insert_list(&l, e, 0);
	display_list(l);

	e.x = 3.;
	e.y = 4.;
	insert_list(&l, e, 2);
	display_list(l);

	e.x = 5.;
	e.y = 6.;
	insert_list(&l, e, 3);
	display_list(l);

	e.x = 7.;
	e.y = 8.;
	insert_list(&l, e, 4);
	display_list(l);

	e.x = 4.1;
	e.y = 4.2;
	insert_list(&l, e, 3);
	display_list(l);

	// free des nodes 😎
	free_list(&l);
	display_list(l);
}