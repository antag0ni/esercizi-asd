#ifndef __LIST_H__
#define __LIST_H__
#include <stdbool.h>
#include "tinfo_corsi.h"

// #define ITERATIVE_LISTS
#define RECURSIVE_LISTS

typedef struct SNode
{
    TInfo info;
    struct SNode *link;
} TNode;

typedef TNode *TList;

/* Crea ed alloca un nodo
 *  PRE: Nessuna
 *  RETURN: IL nodo creato
 */
TNode *node_create(const TInfo value);

/* Distrugge e dealloca il nodo
 *  PRE: Il nodo deve essere allocato
 */
void node_destroy(TNode *node);

/* Crea e restituisce una lista vuota
 *  PRE: Nessuna
 *  RETURN: La lista creata
 */
TList list_create();

/* Dealloca la lista "list" e tutti i suoi elementi
 *  PRE: list deve esistere
 *  RETURN: la lista deallocata
 */
TList list_destroy(TList list);

/* Visita la lista stampandone gli elementi dalla testa alla coda
 *  PRE: list deve esistere
 */
void list_print(const TList list);

/* Cerca l'elemento info in list
 *  PRE: list deve esistere
 *  RETURN: Il riferimento al nodo che contiene info (se trovato), NULL altrimenti
 */
TNode *list_search(const TList list, const TInfo info);

TNode *list_search_unordered(const TList list, const TInfo info);

/* Inserisce un nuovo elemento "info" in list, se l'elemento esiste, ne viene
 *  aggiunta una copia
 *  PRE: se list esiste, deve essere ordinata
 *  RETURN: la lista risultante
 */
TList list_insert(TList list, const TInfo info);

TList list_insert_head(TList list, const TInfo info);

/* Cancella se esiste  "info" da list, se info non è in list, la lista resta inalterata
 *
 *  RETURN: la lista risultante
 */
TList list_delete(TList list, const TInfo info);

TList list_delete_unordered(TList list, const TInfo info);

/* Controlla se la lista è vuota
 *  PRE: list deve esistere
 *  RETURN: "true" se la lista è vuota, "false" altrimenti
 */
bool list_is_empty(const TList list);

#endif