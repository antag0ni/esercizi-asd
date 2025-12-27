#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "tinfo.h"

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

struct SArray
{
    TInfo *item;         // Il vettore contenitore (da allocare)
    unsigned int length; // il riempimento
    unsigned int size;   // la dimensione massima
};

typedef struct SArray TArray;

enum growing_mode
{
    LINEAR,
    GEOMETRIC
};

// funzioni che operano sull'array Dinamic

/* Crea un Array Dinamico
 * PRE: initial_length >=0
 * IN: initial_length: dimensione_massima iniziale
 * RETURN: TArray: la struttura dati Array Dinamico (call by value)
 */
TArray array_create(const unsigned int initial_length);

/* Dealloca un Array Dinamico
 * VDELTAETURN:
 */
void array_destroy(TArray *a);

/* Crea un Array Dinamico
 * PRE: new_length >=0, a!=NULL
 * IN: new_length: nuova lunghezza del vettore
 * IN: GM, modalità di crescita (geometrica/lineare)
 * RETURN: TArray: la struttura dati Array Dinamico (call by value)
 */
void array_resize(TArray *a, const unsigned int new_length, const enum growing_mode GM);

// inserisce un nuovo elemento IN CODA
void push_back(const TInfo elem, TArray *a);
// elimina IN CODA al vettore e torna l'elemento che prima era IN CODA
TInfo remove_back(TArray *a);

// stampa il vettore a partire dalla struttura contenitore
// passata per riferimento per evitare la copia
void print_TArray(const TArray *a);

// restiuisce vero se il vettore a contiene l'elemento ricercato
bool array_contains(TArray *a, TInfo item);

#endif //__ARRAY_H__