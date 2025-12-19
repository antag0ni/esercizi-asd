/*
 * TInfo: tipo elementare
 */

#ifndef TINFO_H
#define TINFO_H

#include <stdbool.h>
#include <string.h>

#define BNAME_SIZ 256

typedef int TKey;
typedef struct
{
    char nomeCorso[30];
    int iscritti;
} TValue;

struct SInfo
{
    TKey key;     /**< Gusto */
    TValue value; /**< Id/ Numero di scelte  */
};
typedef struct SInfo TInfo;

/* Operazioni su TInfo */

bool info_corsi_equal(TInfo, TInfo);
bool info_corsi_greater(TInfo, TInfo);
bool info_corsi_less(TInfo, TInfo);
void info_corsi_print(TInfo);

unsigned int key_hash(const TKey);

#ifdef __cplusplus

#endif

#endif /* INFO_H */
