#ifndef binary_tree_H
#define binary_tree_H

#include "tinfo.h"
#include <stdbool.h>

struct SBTNode
{
    TInfo info;
    int visitato;
    struct SBTNode *left;
    struct SBTNode *right;
};

typedef struct SBTNode TBTNode;
typedef TBTNode *TBinaryTree;
/*
 *  Crea ed alloca un nodo
 *  PRE: nessuna
 */
TBTNode *TBT_node_create(TInfo);

/*
 * Distrugge e dealloca un nodo
 * PRE: nessuna
 */
void TBT_node_destroy(TBTNode *);

/*
 * Crea e restituisce un albero binario vuoto
 * PRE: nessuna
 */
TBinaryTree binarytree_create();

/*
 * Distrugge l'albero binario, deallocandone tutti gli elementi
 * PRE: nessuna
 * NOTA: consuma il parametro bt
 */
TBinaryTree binarytree_destroy(TBinaryTree);

/*
 * Visita l'albero binario in ordine
 * PRE: nessuna
 */
void binarytree_visit(TBinaryTree);

/*
 * Cerca l'elemento di valore info nell'albero binario. Ritorna il
 * riferimento all'elemento se e' presente, altrimenti ritorna NULL.
 * PRE: bt e' ordinato
 */
TBTNode *binarytree_search(TBinaryTree, TInfo);

/*
 * Inserisce l'elemento di valore info nell'albero binario ,
 * preservando l'ordinamento ; restituisce l'albero binario risultante .
 * PRE: bt e' ordinato
 * NOTA: consuma il parametro bt; inoltre se l'elemento da
 * inserire e' gia' presente, esso viene duplicato .
 */
TBinaryTree binarytree_insert(TBinaryTree, TInfo);

/*
 * Cancella l'elemento di valore info nell'albero binario, preservando
 * l'ordinamento ; restituisce l'albero binario risultante .
 * PRE: bt e' ordinato
 * NOTA: consuma il parametro bt; se l'elemento da cancellare
 * non e' presente, l'albero binario resta inalterato .
 */
TBinaryTree binarytree_delete(TBinaryTree, TInfo);

/*
 *  Ritorna il valore true se l'albero binario non contiene elementi
 * PRE: nessuna
 */
bool binarytree_is_empty(TBinaryTree bt);

/*
 * Cerca il minimo nell'albero binario. Ne ritorna il riferimento
 * se presente, altrimenti ritorna NULL.
 * PRE: binarytree e' ordinato
 */
TBTNode *binarytree_search_min(TBinaryTree);

/*
 * Cerca il massimo nell'albero binario. Ne ritorna il riferimento
 * se presente, altrimenti ritorna NULL.
 * PRE: binarytree e' ordinato
 */
TBTNode *binarytree_search_max(TBinaryTree);

/*
 * Visita l'albero binario in pre -ordine
 * PRE: nessuna
 */
void binarytree_visit_pre_order(TBinaryTree);

/*
 * Visita l'albero binario in post -ordine
 * PRE: nessuna
 */
void binarytree_visit_post_order(TBinaryTree);

/*
 * Restituisce il numero dei nodi di un albero,
 * zero se l'albero e' vuoto.
 * PRE: nessuna
 */
int binarytree_count_nodes(TBinaryTree);

/*
 * Restituisce il numero delle foglie di un albero,
 * zero se l'albero e' vuoto.
 * PRE: nessuna
 */
int binarytree_count_leaves(TBinaryTree);

/*
 * Restituisce l'altezza di un albero.
 *
 * PRE: l'albero non e' vuoto
 */
int binarytree_depth(TBinaryTree);

/*
 * Funzione di utilita' per visualizzare la struttura di un albero binario
 * di con TInfo di tipo int o char.
 * La corretta visualizzazione non e' garantita per altre strutture dati.
 *
 * PRE: l'albero non e' vuoto
 */
void binarytree_print_structure(TBinaryTree);

#endif