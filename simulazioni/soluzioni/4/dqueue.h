#ifndef __DQUEUE_H__
#define __DQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "array2.h"

// #ifndef TInfo
// #define TInfo int
// #endif

struct DQueue
{
    unsigned int n;
    unsigned int front;
    unsigned int back;
    unsigned int capacity;
    TArray2 a;
};

typedef struct DQueue TDQueue;

/*Crea la Coda
 * PRE: capacity > 0
 */

TDQueue dqueue_create(const unsigned int capacity);

void dqueue_destroy(TDQueue *q);

void dqueue_add(TDQueue *q, const TInfo2 elem);

TInfo2 dqueue_remove(TDQueue *q);

TInfo2 dqueue_front(TDQueue *q);

bool dqueue_is_empty(TDQueue *q);

#endif //__SQUEUE_H__