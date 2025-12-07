#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashtable.h"

void hashtable_increase(THashTable* ht, TKey key);

void hashtable_decrease(THashTable* ht, TKey key);

TList hashtable_extractList(THashTable* ht, TKey min, TKey max);

void hashtable_insertList(THashTable* ht, TList list);

bool subsetWithHashTable(int* set_T, int* set_S, int sizeT, int sizeS);

bool hashtable_verificaSomma(THashTable* ht, TValue pair_sum);

void hashtable_changeKey(THashTable *ht, TKey key, TKey newKey);

int main(int argc, char** argv) {

    THashTable* ht = hashtable_create (10);


    hashtable_increase(ht, 1000);
    hashtable_increase(ht, 1111);
    hashtable_increase(ht, 1111);
    hashtable_increase(ht, 1871);
    hashtable_increase(ht, 1171);
    printf("Hash Table dopo gli increase: ");
    hashtable_print(ht);

    hashtable_decrease(ht, 1111);
    hashtable_decrease(ht, 1000);
    printf("Hash Table dopo i decrease: ");
    hashtable_print(ht);

    TList list = hashtable_extractList(ht, 1000, 1500);
    printf("\n\nLista degli elementi con chiave tra 1000 e 1500: ");
    list_print(list);

    list_destroy(list);
    list = list_create();
    list = list_insert(list, (TInfo) {2020, 5.22});
    list = list_insert(list, (TInfo) {1870, 6.22});
    list = list_insert(list, (TInfo) {1171, 5.99});
    list = list_insert(list, (TInfo) {1386, 8.17});
    list = list_insert(list, (TInfo) {1001, 2.99});
    printf("Lista degli elementi da inserire: ");
    list_print(list);

    hashtable_insertList(ht, list);
    printf("Hash Table dopo l'inserimento: ");
    hashtable_print(ht);
    printf("\nStruttura Hash Table:\n");
    hashtable_print(ht);


    int set_T[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int set_S[5] = {0, 2, 3, 9, 7};
    int set_R[4] = {1, 2, 3, 10};

    int sizeT = sizeof (set_T) / sizeof (set_T[0]);
    int sizeS = sizeof (set_S) / sizeof (set_S[0]);
    int sizeR = sizeof (set_R) / sizeof (set_R[0]);

    if (subsetWithHashTable(set_T, set_S, sizeT, sizeS))
        printf("S è un sottoinsieme di T");
    else
        printf("S non è un sottoinsieme di T");
    printf("\n");

    if (subsetWithHashTable(set_T, set_R, sizeT, sizeR))
        printf("R è un sottoinsieme di T.\n");
    else
        printf("R non è un sottoinsieme di T.\n");
    printf("\n");

    int ht_elems[10] = {1, 2, 4, 3, 5, 9, 7, 8, 10, 6};

    int num_elems = sizeof (ht_elems) / sizeof (ht_elems[0]);
    TValue sum = {16};

    THashTable* ht_sum = hashtable_create(num_elems);
    for (int i = 0; i < num_elems; i++) {
        hashtable_insert(ht, i, ht_elems[i]);
    }

    if (hashtable_verificaSomma(ht, sum))
        printf("Somma verificata.\n");
    else
        printf("Somma non verificata.\n");

    hashtable_changeKey (ht, 1000, 1001);
    hashtable_changeKey (ht, 1111, 1871);
    printf("\nHash Table dopo i changeKey:\n");
    hashtable_print(ht);

    hashtable_destroy(ht);
    hashtable_destroy(ht_sum);
    list_destroy(list);


    return (EXIT_SUCCESS);
    
}

/* ESERCIZIO 1 */

void hashtable_increase(THashTable* ht, TKey key) {
    // Completare il corpo della funzione
    
}

/* ESERCIZIO 2 */
void hashtable_decrease(THashTable* ht, TKey key) {
    // Completare il corpo della funzione
    
}

/* ESERCIZIO 3 */
TList hashtable_extractList(THashTable* ht, TKey min, TKey max) {
    // Completare il corpo della funzione
    
}

/* ESERCIZIO 4 */

void hashtable_insertList(THashTable* ht, TList list) {
    // Completare il corpo della funzione
    
}

/* ESERCIZIO 5 */
bool subsetWithHashTable(int* set_T, int* set_S, int sizeT, int sizeS) {
    // Completare il corpo della funzione
    
}

/* ESERCIZIO 6 */
bool hashtable_verificaSomma(THashTable* ht, TValue pair_sum) {
    // Completare il corpo della funzione
    
}

/* ESERCIZIO 7 */
void hashtable_changeKey(THashTable *ht, TKey key, TKey newKey) {
    // Completare il corpo della funzione
    
}

