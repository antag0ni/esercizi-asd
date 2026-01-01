/*
* TList: lista ordinata
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

/* operazioni sui nodi */

TNode *node_create(TInfo info) {
    TNode *new = malloc(sizeof (TNode));
    if (new != NULL) {
        new->info = info;
        new->link = NULL;
    }
    return new;
}

void node_destroy(TNode *node) {
    free(node);
}

/* operazioni sulle liste */

TList list_create() {
    return NULL;
}

TList list_destroy(TList list) {
    TNode *node;
    while (list != NULL) {
        node = list;
        list = list->link;
        node_destroy(node);
    }
    return list;
}

void list_print(TList list) {
    if (list != NULL) {
        info_print(list->info);
        list_print(list->link);
    }
}

TNode *list_search(TList list, TInfo info) {
    if (list == NULL || info_greater(list->info, info))
        return NULL;
    if (info_equal(list->info, info))
        return list;
    return list_search(list->link, info);
}

TList list_insert(TList list, TInfo info) {
    if (list == NULL || info_greater(list->info, info)) {
        TNode *newnode = node_create(info);
        assert(newnode != NULL);
        newnode->link = list;
        return newnode;
    }
    list->link = list_insert(list->link, info);
    return list;
}

TList list_delete(TList list, TInfo info) {
    if (list == NULL || info_greater(list->info, info))
        return list;
    if (info_equal(list->info, info)) {
        TList m = list->link;
        node_destroy(list);
        return m;
    }
    list->link = list_delete(list->link, info);
    return list;
}


// Operazioni su liste NON ordinate

TNode * list_search_unordered (const TList list, const TInfo info)
{
    if (list == NULL)
        return NULL;
    TNode * curr = list;
    while (curr!=NULL && !info_equal(info, curr->info))
        curr= curr->link;
    return curr;
}

TList list_append(TList l, TInfo info) {
    if (l == NULL) {
        TNode *node = node_create(info);
        assert (node != NULL);
        return node;
    }
    l->link = list_append(l->link, info);
    return l;
}

TList list_insert_head (TList list, const TInfo info)
{
    TNode * new = node_create(info);
    if (new == NULL)
        return list;
    new->link = list;
    return new;
}

TList list_delete_unordered (TList list, const TInfo info)
{
    if (list == NULL)
        return list;
    TNode *prec = NULL, *curr=list, *alias=NULL;
    while ( (curr!=NULL) && !info_equal(info,curr->info) )
    {
        prec=curr;
        curr=curr->link;
    }
    if (curr == NULL)//non trovato
        return list;
    else
    {
        if (prec == NULL)
        {
            //cancella in testa
            list = curr->link;

        }
        else{
            //cancella in posizione intermedia
            alias = curr->link;
            prec->link = alias;

        }
        node_destroy(curr);
        return list;
    }


}



