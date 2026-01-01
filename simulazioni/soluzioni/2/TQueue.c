/*
 * TQueue: implementazione di una coda attraverso un array dinamico
 */
#include "TQueue.h"
#include <assert.h>
#include <stdlib.h>

/* Crea una coda
*  PRE:
*     initial_capacity >=0
*/
TQueue queue_create(const unsigned int initial_capacity) {
    assert(initial_capacity >0);
    TQueue q;
    q.n = q.front = q.back = 0;
    q.a = array_create(initial_capacity);
    return q;
}

/* Distrugge una coda
*/
void queue_destroy(TQueue *q) {
    assert(q!=NULL);
    q->n = q->front = q->back = 0;
    array_destroy(&q->a);
}

/*  Accoda un elemento
*/
void queue_add(TQueue *q, const TInfo elem) {
    assert(q!=NULL);
    if (q->n == q->a.size) { 
        int i, j, old_size = q->a.size;
        enum growing_mode GM = LINEAR;
        array_resize(&q->a, old_size * 2 + 1, GM);
        if (q->n > 0 && q->front >= q->back) { 
            j=q->a.size-1;
            for (i=old_size-1; i>=q->front; i--)
                q->a.items[j--] = q->a.items[i];
            q->front=j+1;
        }
    }
    q->a.items[q->back] = elem;
    q->back = (q->back + 1) % q->a.size;
    q->n++;
}

/* Preleva un elemento
*  PRE:
*    la coda non è vuota
*/
TInfo queue_remove(TQueue *q) {
    assert (q!=NULL);
    TInfo e = q->a.items[q->front];
    q->front = (q->front + 1) % q->a.size;
    q->n--;
    return e;
}

/* Primo elemento della coda
*  PRE:
*     la coda non è vuota
*/
TInfo queue_front(TQueue *q) {
    assert (q!=NULL);
    return q->a.items[q->front];
}

/* Verifica se la coda è vuota
*/
bool queue_is_empty(TQueue *q) {
    assert (q!=NULL);
    return q->n == 0;
}