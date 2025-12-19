/*
 * TArray: array dinamico
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "TArray.h"

TArray array_create(int initial_length){
    TArray a;
    a.items = (TInfo*) malloc(initial_length * sizeof (TInfo));
    assert(initial_length == 0 || a.items != NULL);
    a.length = initial_length;
    a.size = initial_length;
    return a;
}

void array_destroy(TArray *a) {
    free(a->items);
    a->items = NULL;
    a->length = 0;
    a->size = 0;
}

/* Ridimensiona un array dinamico con Ridimensionamento Lineare
 * PRE :
 * new_length >=0
 */
void array_resize_l(TArray* a, int new_length) {
    if (new_length > a->size ||
            new_length < a->size - SHRINKING_DELTA) {
        int new_size = new_length + GROWING_DELTA;
        a->items = realloc(a->items, new_size * sizeof (TInfo));
        assert(new_size == 0 || a->items != NULL);
        a->size = new_size;
    }
    a->length = new_length;
}

/* Ridimensiona un array dinamico con Ridimensionamento Geometrico
 * PRE :
 * new_length >=0
 */
void array_resize_g(TArray* a, int new_length) {
    if (new_length > a->size ||
            new_length < a->size / SHRINKING_FACTOR) {
        int new_size = new_length * GROWING_FACTOR;
        a->items = realloc(a->items, new_size * sizeof (TInfo));
        assert(new_size == 0 || a->items != NULL);
        a->size = new_size;
    }
    a->length = new_length;
}

void array_resize (TArray* a, const unsigned int new_length,
                const enum growing_mode GM){
    unsigned int new_size= 0;
         switch (GM){
            case LINEAR:
                 array_resize_l(a, new_length);
                 break;
            case GEOMETRIC:
                 array_resize_g(a, new_length);
            default:
        }
}


/* Funzioni di utilità*/

void array_print(const TArray* a) {
    if (a==NULL)
        return;
    if (a->size <=0 || a->length <=0)
        return;
    printf("TArray[%d/%d]:  [",a->length,a->size);
    for (int i = 0; i < a->length; ++i)
        info_print(a->items[i]);
    printf("]\n");
}

//Restituisce la lunghezza (riempimento) dell'array dinamico
int array_length (const TArray* a){
	return a->length;
}
