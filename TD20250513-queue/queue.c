#include <stdio.h>
#include "queue.h"

error_code init_queue(queue *q)
{
    if (NULL == q)
        return BAD_QUEUE;
    return init_list(q);
}
error_code enqueue(queue *q, const elem e)
{
    return insert_list(q, e, q->count);
}
error_code dequeue(queue *q, elem *e)
{
    error_code err = get_elem(*q, 0, e);
    if(err)
        return err;

    return delete_elem(q,0);
}

