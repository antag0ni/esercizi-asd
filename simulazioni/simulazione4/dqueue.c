#include "dqueue.h"

TDQueue dqueue_create(const unsigned int capacity)
{
    assert(capacity > 0);
    TDQueue q;
    q.n = q.front = q.back = 0;
    q.a = array_create_2(capacity);
    return q;
}

void dqueue_destroy(TDQueue *q)
{
    assert(q != NULL);
    q->n = 0;
    array_destroy_2(&q->a);
}

void dqueue_add(TDQueue *q, const TInfo2 elem)
{
    assert(q != NULL);
    if (q->n == q->a.size)
    {
        int i, j, old_size = q->a.size;
        enum growing_mode_2 GM = LINEAR_2;
        array_resize_2(&q->a, old_size * 2 + 1, GM);
        if (q->n > 0 && q->front >= q->back)
        {
            j = q->a.size - 1;
            for (i = old_size - 1; i >= q->front; i--)
                q->a.item[j--] = q->a.item[i];
            q->front = j + 1;
        }
    }
    q->a.item[q->back] = elem;
    q->back = (q->back + 1) % q->a.size;
    q->n++;
}

TInfo2 dqueue_remove(TDQueue *q)
{
    assert(q != NULL);
    TInfo2 e = q->a.item[q->front];
    q->front = (q->front + 1) % q->a.size;
    q->n--;
    return e;
}

TInfo2 dqueue_front(TDQueue *q)
{
    assert(q != NULL);
    return q->a.item[q->front];
}

bool dqueue_is_empty(TDQueue *q)
{
    return q->n == 0;
}
