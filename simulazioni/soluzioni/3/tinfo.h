/*
* TInfo: tipo elementare
 */

#ifndef TINFO_H
#define TINFO_H

typedef int TKey; //codice a barre - numerico

typedef struct {
    char nome[20];
    char cognome[20];
} TValue;

typedef struct {
    TKey key;
    TValue value;
} TInfo;

int info_equal (TInfo, TInfo);
int info_greater (TInfo, TInfo);
int info_less (TInfo, TInfo);
void info_print (TInfo);
unsigned int hash (TKey);

int info_isEven(TInfo);

#endif