/*
 * TInfo: tipo elementare
 */

#include <stdio.h>
#include <string.h>
#include "tinfo2.h"

int info_equal_2(TInfo2 info1, TInfo2 info2)
{
    return info1.key == info2.key;
}

int info_greater_2(TInfo2 info1, TInfo2 info2)
{
    return info1.key > info2.key;
}

int info_less_2(TInfo2 info1, TInfo2 info2)
{
    return info1.key < info2.key;
}

void info_print_2(TInfo2 info)
{
    printf("matricola: %d, codice_esame: %d", info.key, info.codice_esame);
}
