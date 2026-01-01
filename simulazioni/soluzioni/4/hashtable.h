#ifndef __CHAINED_HASHTABLE_H__
#define __CHAINED_HASHTABLE_H__

#include "list.h"

typedef struct SHashTable
{
    int bucket_number;
    TList *bucket;
} THashTable;

THashTable *hashtable_create(const unsigned int buckets);

void hashtable_destroy(THashTable *ht);

void hashtable_insert(THashTable *ht, const TKey key, const TValue value);

void hashtable_delete(THashTable *ht, const TKey key);

TValue *hashtable_search(const THashTable *ht, const TKey key);

void hashtable_print(const THashTable *ht);

#endif