#include <stdio.h>
#include "list.h"
int main(int argc, const char *argv[])
{
	list l;
	error_code err;
	init_list(&l);
	display_list(l);

	return 0;
}

