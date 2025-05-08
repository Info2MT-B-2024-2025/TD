#include <stdio.h>
#include "list.h"
int main(int argc, const char *argv[])
{
	list l;
	error_code err;
	init_list(&l);
	display_list(l);

	elem e;

	for (size_t index = 0; index < 35; index++)
	{

		e.x = e.y = (double)(index + 1);
		err = insert_list(&l, e, index);
		if (err)
			printf("index=%lu, error=%d\n", index, err);
	}
	display_list(l);
	
	return 0;
}
