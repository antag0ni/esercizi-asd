/*
* TInfo: tipo elementare
 */

#include <stdio.h>
#include "tinfo.h"

int info_equal (TInfo info1, TInfo info2) {
    return info1.key == info2.key;
}

int info_greater (TInfo info1, TInfo info2) {
    return  info1.key > info2.key;
}

int info_less (TInfo info1, TInfo info2) {
    return  info1.key < info2.key;
}

void info_print (TInfo info) {
    printf ("(%d: %s) ", info.key, info.value.titolo);

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