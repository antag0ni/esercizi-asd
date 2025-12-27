#ifndef __DSTACK_H__
#define __DSTACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "array.h"

// #ifndef TInfo
// #define TInfo int
// #endif

struct DStack
{
    TArray array;
};

typedef struct DStack TDStack;

TDStack dstack_create(void);

void dstack_destroy(TDStack *stack);

/* Inserisce un elemento in testa
 * PRE: Lo stack non è pieno
 */
void dstack_push(TDStack *stack, const TInfo elem);

/* Elimina e restituisce l'elemento in testa
 * PRE: Lo stack non è vuoto
 */
TInfo dstack_pop(TDStack *stack);

/* restituisce l'elemento in testa
 * PRE: Lo stack non è vuoto
 */
TInfo dstack_top(const TDStack *stack);

/* controlla se lo stack e' vuoto*/
bool dstack_is_empty(const TDStack *stack);

#endif //__DSTACK_H__