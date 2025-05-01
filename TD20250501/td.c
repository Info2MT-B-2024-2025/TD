#include <stdio.h>
#include "list.h"
int main(int argc, const char *argv[])
{
	list l;
	error_code err;
	init_list(&l);
	display_list(l);

	elem e={.x=1, .y=1.};
	err=insert_list(&l, e, 0);
	if(err) printf("error=%d\n",err);
	display_list(l);

	e.x=2.;
	e.y=2.;
	err=insert_list(&l, e, 4);
	if(err) printf("error=%d\n",err);

	display_list(l);
	return 0;
}

