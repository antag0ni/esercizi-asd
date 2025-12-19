#include "list.h"
#include <stdio.h>
#include <stdlib.h>

TNode *node_create(const TInfo value)
{
    TNode *new = (TNode *)malloc(sizeof(TNode));
    if (new == NULL)
        return NULL;
    new->info = value;
    new->link = NULL;
    return new;
}

void node_destroy(TNode *node)
{
    if (node != NULL)
        free(node);
}

TList list_create()
{
    return NULL;
}

TList list_destroy(TList list)
{
    if (list == NULL)
        return NULL;
    TNode *curr = list, *succ;
    while (curr != NULL)
    {
        succ = curr->link;
        node_destroy(curr);
        curr = succ;
    }
    return NULL;
}

void list_print_ordered(const TList list)
{
    if (list == NULL)
        return;
    TNode *curr = list;
    while (curr != NULL)
    {
        info_corsi_print(curr->info);
        printf(" ");
        curr = curr->link;
    }
}

void list_print_recursive(TList list)
{
    if (list != NULL)
    {
        info_corsi_print(list->info);
        printf("\n");
        list_print_recursive(list->link);
    }
}

void list_print(const TList list)
{
#ifdef ITERATIVE_LISTS
    list_print_ordered(list);
#elif defined(RECURSIVE_LISTS)
    list_print_recursive(list);
#endif
}

TNode *list_search_odered(const TList list, const TInfo info)
{
    if (list == NULL)
        return NULL;
    TNode *curr = list;
    while (curr != NULL && info_corsi_greater(info, curr->info))
        curr = curr->link;
    if (curr != NULL && info_corsi_equal(curr->info, info))
        return curr;
    else
        return NULL;
}

TNode *list_search_unordered(const TList list, const TInfo info)
{
    if (list == NULL)
        return NULL;
    TNode *curr = list;
    while (curr != NULL && !info_corsi_equal(info, curr->info))
        curr = curr->link;
    return curr;
}

TNode *list_search_recursive(const TList list, const TInfo info)
{
    if (list == NULL || info_corsi_greater(list->info, info))
        return NULL;
    else
    {
        if (info_corsi_equal(list->info, info))
            return list;
        else
            return list_search_recursive(list->link, info);
    }
}

TNode *list_search(const TList list, const TInfo info)
{
#ifdef ITERATIVE_LISTS
    return list_search_odered(list, info);
#elif defined(RECURSIVE_LISTS)
    return list_search_recursive(list, info);

#endif
}

TList list_insert_head(TList list, const TInfo info)
{
    TNode *new = node_create(info);
    if (new == NULL)
        return list;
    new->link = list;
    return new;
}

TList list_insert_ordered(TList list, const TInfo info)
{
    TNode *prec = NULL, *succ = list, *new = NULL;

    /* Cerca la posizione di inserimento*/
    while ((succ != NULL) && info_corsi_greater(info, succ->info))
    {
        prec = succ;
        succ = succ->link;
    }
    /* alloca un nuovo nodo*/
    new = node_create(info);
    if (new == NULL)
    {
        printf("ERROR: Allocazione Fallita");
        return list;
    }
    /* aggiorna i collegamenti*/
    if (prec == NULL)
    {
        // inserimento in testa
        new->link = list;
        return new;
    }
    else
    {
        new->link = succ;
        prec->link = new;
        return list;
    }
}

TList list_insert_recursive(TList list, const TInfo info)
{
    if (list == NULL || info_corsi_greater(list->info, info))
    {
        TNode *newnode = node_create(info);
        if (newnode == NULL)
        {
            printf("Errore Allocazione newnode\n");
            return list;
        }
        newnode->link = list;
        return newnode;
    }
    else
    {
        TList l2 = list_insert_recursive(list->link, info);
        list->link = l2;
        return list;
    }
}

TList list_insert(TList list, const TInfo info)
{
#ifdef ITERATIVE_LISTS
    return list_insert_ordered TList list_insert_head(TList list, const TInfo
                                                                      info);
    (list, info);
#elif defined(RECURSIVE_LISTS)
    return list_insert_recursive(list, info);
#endif
}

TList list_delete_unordered(TList list, const TInfo info)
{
    if (list == NULL)
        return list;
    TNode *prec = NULL, *curr = list, *alias = NULL;
    while ((curr != NULL) && !info_corsi_equal(info, curr->info))
    {
        prec = curr;
        curr = curr->link;
    }
    if (curr == NULL) // non trovato
        return list;
    else
    {
        if (prec == NULL)
        {
            // cancella in testa
            list = curr->link;
        }
        else
        {
            // cancella in posizione intermedia
            alias = curr->link;
            prec->link = alias;
        }
        node_destroy(curr);
        return list;
    }
}

TList list_delete_ordered(TList list, const TInfo info)
{

    TNode *prec = NULL, *curr = list, *alias = NULL;

    /* Cerca la posizione di cancellamento*/
    while ((curr != NULL) && info_corsi_greater(info, curr->info))
    {
        prec = curr;
        curr = curr->link;
    }
    if (curr != NULL && info_corsi_equal(curr->info, info))
    { // trovato
        if (prec == NULL)
        {
            // cancella in testa
            list = curr->link;
        }
        else
        {
            // cancella in posizione intermedia
            alias = curr->link;
            prec->link = alias;
        }
        node_destroy(curr);
        return list;
    }
    return list;
}

TList list_delete_recursive(TList list, const TInfo info)
{
    if (list == NULL || info_corsi_greater(list->info, info))
        return NULL;
    else
    {
        if (info_corsi_equal(list->info, info))
        {
            // cancellazione in testa
            TNode *alias = list->link;
            node_destroy(list);
            return alias;
        }
        else
        {
            TList l2 = list_delete_recursive(list->link, info);
            list->link = l2;
            return list;
        }
    }
}

TList list_delete(TList list, const TInfo info)
{
#ifdef ITERATIVE_LISTS
    return list_delete_ordered(list, info);
#elif defined(RECURSIVE_LISTS)
    return list_delete_recursive(list, info);
#endif
}

bool list_is_empty(const TList list)
{
    return (list == NULL);
}
