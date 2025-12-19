/*
 * TInfo: tipo elementare
 */

#include <stdio.h>
#include <string.h>
#include "tinfo_corsi.h"

bool info_corsi_equal(TInfo info1, TInfo info2)
{
    return info1.key == info2.key;
}

bool info_corsi_greater(TInfo info1, TInfo info2)
{
    return info1.key > info2.key;
}

bool info_corsi_less(TInfo info1, TInfo info2)
{
    return info1.key < info2.key;
}

void info_corsi_print(TInfo info)
{
    printf("%d: %s (iscritti: %d)", info.key, info.value.nomeCorso,
           info.value.iscritti);
}

unsigned int key_hash(TKey key)
{
    return key;
}
