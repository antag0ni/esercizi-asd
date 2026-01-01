#ifndef __ARRAY2_H__
#define __ARRAY2_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "tinfo2.h"

#ifndef GROWING_DELTA
#define GROWING_DELTA 10
#endif

#ifndef SHRINKING_DELTA
#define SHRINKING_DELTA 20
#endif

#ifndef GROWING_FACTOR
#define GROWING_FACTOR 2
#endif

#ifndef SHRINKING_FACTOR
#define SHRINKING_FACTOR 4
#endif

struct SArray2
{
    TInfo2 *item;         // Il vettore contenitore (da allocare)
    unsigned int length; // il riempimento
    unsigned int size;   // la dimensione massima
};

typedef struct SArray2 TArray2;

enum growing_mode_2
{
    LINEAR_2,
    GEOMETRIC_2
};

// funzioni che operano sull'array Dinamic

/* Crea un Array Dinamico
 * PRE: initial_length >=0
 * IN: initial_length: dimensione_massima iniziale
 * RETURN: TArray: la struttura dati Array Dinamico (call by value)
 */
TArray2 array_create_2(const unsigned int initial_length);

/* Dealloca un Array Dinamico
 * VDELTAETURN:
 */
void array_destroy_2(TArray2 *a);

/* Crea un Array Dinamico
 * PRE: new_length >=0, a!=NULL
 * IN: new_length: nuova lunghezza del vettore
 * IN: GM, modalità di crescita (geometrica/lineare)
 * RETURN: TArray: la struttura dati Array Dinamico (call by value)
 */
void array_resize_2(TArray2 *a, const unsigned int new_length, const enum growing_mode_2 GM);

// inserisce un nuovo elemento IN CODA
void push_back_2(const TInfo2 elem, TArray2 *a);
// elimina IN CODA al vettore e torna l'elemento che prima era IN CODA
TInfo2 remove_back_2(TArray2 *a);

// stampa il vettore a partire dalla struttura contenitore
// passata per riferimento per evitare la copia
void print_TArray_2(const TArray2 *a);

// restiuisce vero se il vettore a contiene l'elemento ricercato
bool array_contains_2(TArray2 *a, TInfo2 item);

#endif //__ARRAY_H__