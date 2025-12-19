/*
 * TInfo_studenti: tipo elementare
 */

#ifndef TInfo_studenti_H
#define TInfo_studenti_H

#include <stdbool.h>
#include <string.h>

#define BNAME_SIZ 256

typedef struct
{
    int matricola;
    char nome[30];
    int codiceCorso;
} TInfo_studenti;

/* Operazioni su TInfo_studenti */

bool info_equal(TInfo_studenti, TInfo_studenti);
bool info_greater(TInfo_studenti, TInfo_studenti);
bool info_less(TInfo_studenti, TInfo_studenti);
void info_print(TInfo_studenti);

#ifdef __cplusplus

#endif

#endif /* INFO_H */
