/*
* TInfo: tipo elementare
 */

#ifndef TINFO_H
#define TINFO_H

#include <stdbool.h>

typedef int TKey;
typedef float TValue;

/* TValue alternativo
typedef struct {
    char name[20];
    float price;
} TValue;
*/

typedef struct {
    TKey key;
    TValue value;
} TInfo;

bool info_equal (TInfo, TInfo);
bool info_greater (TInfo, TInfo);
bool info_less (TInfo, TInfo);
void info_print (TInfo);
unsigned int hash (const TKey);

bool key_equal (TKey, TKey);
bool value_equal (TValue, TValue);
TValue value_add (TValue, TValue);
void value_print (TValue);

#endif