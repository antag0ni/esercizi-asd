/*
 * TInfo: tipo elementare
 */

#include <stdio.h>
#include "TInfo.h"

int info_equal(TInfo info1, TInfo info2) {
    return info1 == info2;
}

int info_greater(TInfo info1, TInfo info2) {
    return info1 > info2;
}

int info_less(TInfo info1, TInfo info2) {
    return info1 < info2;
}

void info_print(TInfo info) {
    printf("%d ", info);
}

TInfo info_add(TInfo info1, TInfo info2) {
    return info1 + info2;
}
