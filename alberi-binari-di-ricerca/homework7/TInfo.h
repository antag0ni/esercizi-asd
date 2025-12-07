/*
 * TInfo: tipo elementare
 */

#ifndef TINFO_H
#define TINFO_H

typedef int TInfo;

int info_equal(TInfo, TInfo);
int info_greater(TInfo, TInfo);
int info_less(TInfo, TInfo);
void info_print(TInfo);
TInfo info_add(TInfo info1, TInfo info2);

#endif

