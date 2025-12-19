/*
 * TStack: implementazione di uno stack attraverso un array dinamico
 */

#ifndef TSTACK_H
#define TSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "tinfo.h"
#include "TArray.h"

typedef struct {
    TArray array;
} TStack;

/* Crea uno stack
 */
TStack stack_create(void);

/* Distrugge uno stack
 */
void stack_destroy(TStack *);

/* Inserisce un elemento in testa
 * PRE:
 * lo stack non e’ pieno
 */
void stack_push(TStack *, const TInfo);

/* Elimina e restituisce l'elemento in testa
 * PRE: Lo stack non è vuoto
 */
TInfo stack_pop(TStack *);

/* Elemento in cima
 * PRE:
 * lo stack non e’ vuoto
 */
TInfo stack_top(const TStack *);

/* Verifica se lo stack e’ vuoto
 */
bool stack_is_empty(const TStack *);

#endif