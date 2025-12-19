/*
* TInfo: tipo elementare
 */

#ifndef TINFO_H
#define TINFO_H

typedef int TKey;

typedef struct
{
    char titolo[50];
} TValue;

typedef struct
{
    TKey key;
    TValue value;
} TInfo;

int info_equal (TInfo, TInfo);
int info_greater (TInfo, TInfo);
int info_less (TInfo, TInfo);
void info_print (TInfo);
unsigned int hash (const TKey key);

#endif