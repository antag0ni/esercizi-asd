//
// Created by Leonardo Rundo on 20/11/25.
//

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "TInfo.h"
#include <stdbool.h>

struct SBTNode
{
    TInfo info;
    struct SBTNode *left;
    struct SBTNode *right;
};

typedef struct SBTNode TBTNode;
typedef TBTNode *TBinaryTree;
/*
 *  Crea ed alloca un nodo
 *  PRE: nessuna
 */
TBTNode *node_create(TInfo);

/*
 * Distrugge e dealloca un nodo
 * PRE: nessuna
 */
void node_destroy(TBTNode *);

/*
 * Crea e restituisce un albero binario vuoto
 * PRE: nessuna
 */
TBinaryTree binarytree_create();

/*
 * Distrugge l’albero binario , deallocandone tutti gli elementi
 * PRE: nessuna
 * NOTA: consuma il parametro bt
 */
TBinaryTree binarytree_destroy(TBinaryTree);

/*
 * Visita l ’albero binario in ordine
 * PRE: nessuna
 */
void binarytree_visit(TBinaryTree);

/*
 *  Cerca l’elemento di valore info nell ’albero binario. Ritorna il
 * riferimento all ’elemento se e ’ presente , altrimenti ritorna NULL.
 * PRE: bt e’ ordinato
 */
TBTNode *binarytree_search(TBinaryTree, TInfo);

/*
 * Inserisce l’elemento di valore info nell ’albero binario ,
 * preservando l’ordinamento ; restituisce l’albero binario risultante .
 * PRE: bt e’ ordinato
 * NOTA: consuma il parametro bt; inoltre se l’elemento da
 * inserire e’ gia ’ presente , esso viene duplicato .
 */
TBinaryTree binarytree_insert(TBinaryTree, TInfo);

/*
 * Cancella l ’elemento di valore info nell ’albero binario , preservando
 * l’ordinamento ; restituisce l’albero binario risultante .
 * PRE: bt e’ ordinato
 * NOTA: consuma il parametro bt; se l ’elemento da cancellare
 * non e’ presente , l’albero binario resta inalterato .
 */
TBinaryTree binarytree_delete(TBinaryTree, TInfo);

/*
 *  Ritorna il valore true se l’albero binario non contiene elementi
 * PRE: nessuna
 */
bool binarytree_is_empty(TBinaryTree bt);

/*
 * Cerca il minimo nell ’albero binario. Ne ritorna il riferimento
 * se presente , altrimenti ritorna NULL.
 * PRE: binarytree e’ ordinato
 */
TBTNode *binarytree_search_min(TBinaryTree);

/*
 * Cerca il massimo nell ’albero binario. Ne ritorna il riferimento
 * se presente, altrimenti ritorna NULL.
 * PRE: binarytree e’ ordinato
 */
TBTNode *binarytree_search_max(TBinaryTree);

/*
 * Visita l ’albero binario in pre-ordine
 * PRE: nessuna
 */
void binarytree_visit_pre_order(TBinaryTree);

/*
 * Visita l ’albero binario in post-ordine
 * PRE: nessuna
 */
void binarytree_visit_post_order(TBinaryTree);


#endif //BINARY_TREE_H
