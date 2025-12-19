
#include "hashtable.h"
#include <stdlib.h>
#include <stdio.h>


/* PRE: buckets >0*/
THashTable* hashtable_create (const unsigned int buckets)
{
    if (buckets == 0)
        return NULL;
    THashTable * p = (THashTable * )malloc (sizeof(THashTable));
    if (p==NULL)
        return NULL;
    p->bucket_number = buckets;
    p->bucket = (TList*) malloc (sizeof (TList)* buckets);
    if (p->bucket == NULL)
    {
        free (p);
        return NULL;
    }
    for (int i = 0; i < buckets; i++)
    {
        p->bucket[i] = list_create();
    }

    return p;
}

void hashtable_destroy (THashTable* ht)
{
    if (ht == NULL)
        return;
    for (int i=0; i< ht->bucket_number; ++i)
        ht->bucket[i]=list_destroy(ht->bucket[i]);
    free (ht->bucket);
    ht->bucket_number = 0;
    free (ht);
}


void hashtable_insert (THashTable* ht, const TKey key, const TValue value)
{
    if (ht == NULL)
        return;
    TInfo info;
    info.key = key;
    info.value = value;
    unsigned int h = hash (key) % ht->bucket_number;

    TNode * node = list_search_unordered(ht->bucket[h], info);
    if (node == NULL)
        ht->bucket[h] = list_insert_head(ht->bucket[h], info);
    else 
        node->info = info;

}

void hashtable_delete (THashTable* ht, const TKey key)
{
    if (ht == NULL)
        return;
    TInfo info;
    info.key = key;
    unsigned int h = hash(key) % ht->bucket_number;
    ht->bucket[h] = list_delete_unordered(ht->bucket[h], info);
}

TValue * hashtable_search (const THashTable * ht, const TKey key)
{
    unsigned int h = hash (key) % ht->bucket_number;
    TInfo info;
    info.key = key;
    TNode * node = list_search_unordered(ht->bucket[h],info);
    if (node == NULL)
        return NULL;
    else 
        return (&node->info.value);
}

void hashtable_print (const THashTable* ht)
{
    if (ht==NULL)
        return;
    for (int i = 0; i< ht->bucket_number; i++)
    {
        for (TNode *n = ht->bucket[i]; n!= NULL; n=n->link){
            info_print(n->info);
            printf (" ---> ");
        }
        printf("\n");
    }
}

