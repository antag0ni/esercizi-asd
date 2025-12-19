/*
 * TInfo_studenti: tipo elementare
 */

#include <stdio.h>
#include <string.h>
#include "tinfo_studenti.h"

bool info_equal(TInfo_studenti info1, TInfo_studenti info2)
{
    return info1.matricola == info2.matricola;
}

bool info_greater(TInfo_studenti info1, TInfo_studenti info2)
{
    return info1.matricola > info2.matricola;
}

bool info_less(TInfo_studenti info1, TInfo_studenti info2)
{
    return info1.matricola < info2.matricola;
}

void info_print(TInfo_studenti info)
{
    printf("%d: %s (corso: %d)", info.matricola, info.nome, info.codiceCorso);
}