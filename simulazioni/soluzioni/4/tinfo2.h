/*
 * TInfo: tipo elementare
 */

#ifndef TINFO2_H
#define TINFO2_H

typedef struct
{
    int key;
    int codice_esame;
} TInfo2;

int info_equal_2(TInfo2, TInfo2);
int info_greater_2(TInfo2, TInfo2);
int info_less_2(TInfo2, TInfo2);
void info_print_2(TInfo2);

#endif
