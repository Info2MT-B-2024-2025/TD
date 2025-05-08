#include <stdio.h>
#include "list.h"
int main(int argc, const char *argv[])
{
	list l;
	error_code err;
	init_list(&l);
	display_list(l);

	elem e={.x=1, .y=2.};
	err=insert_list(&l, e, 0);
	if(err) printf("error=%d\n",err);
	display_list(l);

	e.x=5.;
	e.y=6.;
	err=insert_list(&l, e, 1);
	if(err) printf("error=%d\n",err);
	display_list(l);

	e.x=3.;
	e.y=4.;
	err=insert_list(&l, e, 1);
	if(err) printf("error=%d\n",err);
	display_list(l);

	err=delete_elem(&l, 0);
	if(err) printf("error=%d\n",err);
	display_list(l);

	return 0;
}

