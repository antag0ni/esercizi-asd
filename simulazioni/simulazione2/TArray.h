/*
 * TArray: array dinamico
 */

#ifndef TARRAY_H
#define TARRAY_H

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

struct SArray {
    TInfo* items; /* elementi dell'array */
    int length; /* riempimento */
    int size; /* dimensione allocata */
};
typedef struct SArray TArray;

enum growing_mode {
    LINEAR,
    GEOMETRIC
};

/* Crea un Array Dinamico
* PRE: initial_length >=0
* IN: initial_length: dimensione_massima iniziale
* RETURN: TArray: la struttura dati Array Dinamico
*/
TArray array_create(int initial_length);

/* Dealloca un Array Dinamico
*/
void array_destroy(TArray* a);

/* Ridimensiona un Array Dinamico - LINEARE
* PRE: new_length >=0, a!=NULL
* IN: new_length: nuova lunghezza del vettore
* RETURN: TArray: la struttura dati Array Dinamico
*/
void array_resize_l(TArray* a, int length);

/* Ridimensiona un Array Dinamico - GEOMETRICO
* PRE: new_length >=0, a!=NULL
* IN: new_length: nuova lunghezza del vettore
* RETURN: TArray: la struttura dati Array Dinamico
*/
void array_resize_g(TArray* a, int length);

/* Ridimensiona un Array Dinamico
* PRE: new_length >=0, a!=NULL
* IN: new_length: nuova lunghezza del vettore
* IN: GM, modalità di crescita (geometrica/lineare)
* RETURN: TArray: la struttura dati Array Dinamico
*/
void array_resize (TArray* a, const unsigned int new_length,
                const enum growing_mode GM);

//Elimina e restituisce l'elemento in coda all'array
TInfo array_remove(TArray* a);

/* Funzioni di utilità */

// stampa il vettore a partire dalla struttura contenitore
// passata per riferimento per evitare la copia
//* IN: *a: puntatore alla struttura dati Array Dinamico da stampare
void array_print(const TArray* a);

//Restituisce la lunghezza (riempimento) dell'array dinamico
int array_length (const TArray* a);


#endif //TARRAY_H