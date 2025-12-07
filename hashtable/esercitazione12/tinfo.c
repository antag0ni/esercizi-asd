/*
* TInfo: tipo elementare
 */

#include <stdio.h>
#include "tinfo.h"

bool info_equal (TInfo info1, TInfo info2) {
    return info1.key == info2.key;
}

bool info_greater (TInfo info1, TInfo info2) {
    return  info1.key > info2.key;
}

bool info_less (TInfo info1, TInfo info2) {
    return  info1.key < info2.key;
}

void info_print (TInfo info) {
    printf ("(%d: %f) ", info.key, info.value);

    /* con TValue alternativo
    printf ("(%d: %s, %.2f) ", info.key, info.value.name, info.value.price);
    */
}

/* Funzione di hash per interi */
unsigned int hash (const TKey key)
{
    return (unsigned int) key;
}

/* Funzione di hash per stringhe di caratteri */
/*unsigned int hash (const TKey key)
{
    unsigned int h = 0 ;
    for (int i = 0; key[i]!='\0'; i++)
        h = h*33 + (unsigned int)key[i];
    return h;

}*/

bool key_equal (TKey key1, TKey key2) {
    return key1 == key2;
}

bool value_equal (TValue val1, TValue val2) {
    return val1 == val2;
}

TValue value_add (TValue val1, TValue val2) {
    return val1 + val2;
}

void value_print (TValue val) {
    printf ("%f", val);

}