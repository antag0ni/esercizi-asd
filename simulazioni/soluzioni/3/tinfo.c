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
    printf ("(%d: %s %s)", info.key, info.value.nome, info.value.cognome);
}

unsigned int hash (TKey key) {
    return (unsigned) key;
}

int info_isEven(TInfo num){
    if(num.key % 2 == 0)
        return 1;
    else
        return 0;
}