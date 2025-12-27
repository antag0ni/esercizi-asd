#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "binary_tree.h"

/* operazioni sui nodi */

TBTNode *TBT_node_create(TInfo info)
{
    TBTNode *node = malloc(sizeof(TBTNode));
    assert(node != NULL);
    node->info = info;
    node->visitato = 0;
    node->left = node->right = NULL;
    return node;
}

void TBT_node_destroy(TBTNode *node)
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
        TBT_node_destroy(bt);
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
        new = TBT_node_create(info);
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
            TBT_node_destroy(bt); // Cancellazione di una foglia
            return NULL;
        }
        if (bt->right == NULL)
        { // Cancellazione di un nodo con
            // il solo figlio sinistro
            TBinaryTree alias;
            alias = bt->left;
            TBT_node_destroy(bt);
            return alias;
        }

        if (bt->left == NULL)
        { // Cancellazione di un nodo con
            // il solo figlio destro
            TBinaryTree alias;
            alias = bt->right;
            TBT_node_destroy(bt);
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
        printf("\n");
        binarytree_visit(tree->right);
    }
}

/* Visita l'albero binario in post -ordine
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

/* Visita l'albero binario in pre -ordine
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

int binarytree_count_leaves(TBinaryTree bt)
{
    int count_left, count_right;
    /* Caso base: Albero vuoto oppure albero con un solo elemento */
    if (bt == NULL)
        return 0;
    else if ((bt->left == NULL) && (bt->right == NULL))
        return 1;
    else
    {
        /* Fase di divide et impera */
        count_left = binarytree_count_leaves(bt->left);
        /* Fase di divide et impera */
        count_right = binarytree_count_leaves(bt->right);
        /* Fase di combina */
        return count_left + count_right;
    }
}

bool binarytree_is_empty(TBinaryTree tree)
{
    return (tree == NULL);
}

/*
 * PRE: l'albero non e' vuoto
 */
int binarytree_depth(TBinaryTree tree)
{
    assert(tree != NULL);
    /* Caso base: foglia */
    if (tree->left == NULL && tree->right == NULL)
        return 0;
    else if (tree->left == NULL) /* Solo sottoalbero destro */
        return 1 + binarytree_depth(tree->right);
    else if (tree->right == NULL) /* Solo sottoalbero sinistro */
        return 1 + binarytree_depth(tree->left);
    else
    { /* Nodo completo */
        /* Fase di divide et impera */
        int depth_left = binarytree_depth(tree->left);
        int depth_right = binarytree_depth(tree->right);
        /* Fase di combina */
        if (depth_left > depth_right)
            return 1 + depth_left;
        else
            return 1 + depth_right;
    }
}

/*
 * binarytree_print_structure(TBinaryTree tree)
 * Funzione utile a visualizzare la struttura di un albero binario di int o char
 * La corretta visualizzazione non e' garantita per altre strutture dati.
 *
 * Richiama la void binarytree_print_structure1(TBinaryTree tree, int o, TInfo *n, int *m)
 */
void binarytree_print_structure1(TBinaryTree tree, int o, TInfo *n, int *m)
{
    if (tree != NULL)
    {
        n[o] = tree->info;
        m[o] = 1;
        binarytree_print_structure1(tree->left, (o + 1) * 2 - 1, n, m);
        binarytree_print_structure1(tree->right, (o + 1) * 2, n, m);
    }
}

void binarytree_print_structure(TBinaryTree tree)
{
    int d = binarytree_depth(tree) + 1, s = pow(2, d) - 1, m[s], i, j, b;
    TInfo *n = (TInfo *)malloc(sizeof(TInfo) * s);
    if (n == NULL)
    {
        printf("Memoria esaurita\n");
        exit(1);
    }
    for (i = 0; i < s; ++i) // annulla elementi
        m[i] = 0;
    binarytree_print_structure1(tree, 0, n, m);
    for (i = 0; i < d; ++i)
    { // stampa albero
        for (j = pow(2, i) - 1; j < pow(2, i + 1) - 1; ++j)
        {
            b = (pow(2, (d - i - 1)) - 1) * 4;
            if (m[j])
                printf("%*d%*s", b / 2 + 4, n[j], b / 2, "");
            else
                printf("%*s", b + 4, "");
        }
        printf("\n");
    }
    free(n);
}