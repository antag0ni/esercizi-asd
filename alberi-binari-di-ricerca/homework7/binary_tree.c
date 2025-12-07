//
// Created by Leonardo Rundo on 20/11/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "binary_tree.h"

/* operazioni sui nodi */

TBTNode *node_create(TInfo info)
{
    TBTNode *node = malloc(sizeof(TBTNode));
    assert(node != NULL);
    node->info = info;
    node->left = node->right = NULL;
    return node;
}

void node_destroy(TBTNode *node)
{
    free(node);
}

/* operazioni sugli alberi - versione ricorsiva */

TBinaryTree binarytree_create()
{
    return NULL;
}

/* Distrugge l'albero binario, deallocandone tutti gli elementi
 * PRE: nessuna
 * NOTA: consuma il parametro bt
 */
TBinaryTree binarytree_destroy(TBinaryTree bt)
{
    /* Caso base: Albero vuoto oppure con un solo elemento */
    if (bt == NULL)
        return NULL;
    else if ((bt->left == NULL) && (bt->right == NULL))
    {
        free(bt);
        return NULL;
    }
    else
    {
        /* Fase di divide at impera */
        bt->left = binarytree_destroy(bt->left);
        /* Fase di divide at impera */
        bt->right = binarytree_destroy(bt->right);
        /* Fase di combina */
        node_destroy(bt);
        return NULL;
    }
}

TBinaryTree binarytree_search(TBinaryTree bt, TInfo info)
{
    /* Caso base: Albero vuoto oppure la root e' l'elemento cercato */
    if ((bt == NULL) || info_equal(bt->info, info))
        return bt;
    else
    {
        if (info_greater(info, bt->info))
            /* Fase di divide at impera */
            return binarytree_search(bt->right, info);
        else
            /* Fase di divide at impera */
            return binarytree_search(bt->left, info);
    }
}

TBTNode *binarytree_search_min(TBinaryTree bt)
{
    /* Caso base: Albero vuoto */
    if (bt == NULL)
        return NULL;
    else if (bt->left == NULL)
        return bt;
    else
    {
        /* Fase di divide at impera */
        TBinaryTree min = binarytree_search_min(bt->left);
        /* Fase di combina */
        return min;
    }
}

TBTNode *binarytree_search_max(TBinaryTree bt)
{
    /* Caso base: Albero vuoto */
    if (bt == NULL)
        return NULL;
    else if (bt->right == NULL)
        return bt;
    else
    {
        /* Fase di divide at impera */
        TBinaryTree max = binarytree_search_min(bt->right);
        /* Fase di combina */
        return max;
    }
}

TBinaryTree binarytree_insert(TBinaryTree bt, TInfo info)
{
    /* Caso base: Albero vuoto */
    if (bt == NULL)
    {
        TBTNode *new;
        new = node_create(info);
        if (new == NULL)
        {
            printf("Errore di allocazione della memoria\n");
            exit(1);
        }
        return new;
    }
    else if (!info_greater(info, bt->info))
    {
        /* Fase di divide at impera */
        bt->left = binarytree_insert(bt->left, info);
        /* Fase di combina */
        return bt;
    }
    else
    {
        /* Fase di divide at impera */
        bt->right = binarytree_insert(bt->right, info);
        /* Fase di combina */
        return bt;
    }
}

TBinaryTree binarytree_delete(TBinaryTree bt, TInfo info)
{
    /* Caso base: Albero vuoto */
    if (bt == NULL)
        return NULL;
    else if (info_greater(bt->info, info))
    {
        /* Fase di divide at impera */
        bt->left = binarytree_delete(bt->left, info);
        return bt;
    }
    else if (info_greater(info, bt->info))
    {
        /* Fase di divide at impera */
        bt->right = binarytree_delete(bt->right, info);
        return bt;
    } /* Fase di combina */
    else
    { // bt->info == info
        TBinaryTree min_right;
        if ((bt->right == NULL) && (bt->left == NULL))
        {
            node_destroy(bt); // Cancellazione di una foglia
            return NULL;
        }
        if (bt->right == NULL)
        { // Cancellazione di un nodo con
            // il solo figlio sinistro
            TBinaryTree alias;
            alias = bt->left;
            node_destroy(bt);
            return alias;
        }

        if (bt->left == NULL)
        { // Cancellazione di un nodo con
            // il solo figlio destro
            TBinaryTree alias;
            alias = bt->right;
            node_destroy(bt);
            return alias;
        }
        // Cancellazione di un nodo con entrambi i figli
        min_right = binarytree_search_min(bt->right);
        // Ricerca del minimo del
        // sottoalbero destro
        bt->info = min_right->info; // Copia del minimo
        // nel campo info
        // del nodo da eliminare
        // Eliminazione del nodo da cui `e stato copiato il minimo
        bt->right = binarytree_delete(bt->right, min_right->info);
        return bt;
    }
}

void binarytree_visit(TBinaryTree tree)
{
    if (tree != NULL)
    {
        binarytree_visit(tree->left);
        info_print(tree->info);
        binarytree_visit(tree->right);
    }
}

/* Visita l'albero binario in post-ordine
 * PRE: nessuna
 */
void binarytree_visit_post_order(TBinaryTree bt)
{

    if (bt != NULL)
    {
        binarytree_visit(bt->left);
        binarytree_visit(bt->right);
        info_print(bt->info);
    }
}

/* Visita l'albero binario in pre-ordine
 * PRE: nessuna
 */
void binarytree_visit_pre_order(TBinaryTree bt)
{
    if (bt != NULL)
    {
        info_print(bt->info);
        binarytree_visit(bt->left);
        binarytree_visit(bt->right);
    }
}

