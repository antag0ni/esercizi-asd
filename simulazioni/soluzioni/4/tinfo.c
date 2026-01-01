/*
 * TInfo: tipo elementare
 */

#include <stdio.h>
#include <string.h>
#include "tinfo.h"

int info_equal(TInfo info1, TInfo info2)
{
    return (info1.key == info2.key);
}

int info_greater(TInfo info1, TInfo info2)
{
    return (info1.key > info2.key);
}

int info_less(TInfo info1, TInfo info2)
{
    return (info1.key < info2.key);
}

void info_print(TInfo info)
{
    printf("(%d: %s %s)", info.key, info.value.nome, info.value.cognome);
}

unsigned int key_hash(TKey key)
{
    return key;
}
