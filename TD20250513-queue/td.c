#include <stdio.h>
#include "queue.h"

int main(int argc, const char *argv[])
{

	queue q;
	init_queue(&q);

	elem e = 10;
	enqueue(&q, e);
	e = 20;
	enqueue(&q, e);
	e = 30;
	enqueue(&q, e);
	
	dequeue(&q,&e);
	display_elem(e); // 10
	dequeue(&q,&e);
	display_elem(e); // 20
	dequeue(&q,&e);
	display_elem(e); // 30
	return 0;
}
