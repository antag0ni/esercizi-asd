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
    printf("\n");

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
    /*Realizzare una funzione che, se esiste un valore associato 
    con una chiave key ne incrementa di 1 il valore, 
    altrimenti inserisce nella tabella hash ht il dato (key, 1.0).*/

    TValue * pvalue = hashtable_search(ht, key);
    if (pvalue != NULL) {
        *pvalue = value_add(*pvalue, 1.0f);
    } else {
        hashtable_insert(ht, key, 1.0f);
    }  
}

/* ESERCIZIO 2 */
void hashtable_decrease(THashTable* ht, TKey key) {
    /*Realizzare una funzione che, se esiste un valore associato con 
    la chiave key ne decrementa di 1 il valore corrispondente. 
    Nel caso in cui il valore diventasse 0, allora il dato viene 
    rimosso dalla hash table.*/
    
    TValue * pvalue = hashtable_search(ht, key);
    if (pvalue != NULL) {
        *pvalue = value_add(*pvalue, -1.0f);
        if (value_equal(*pvalue, 0.0f)) {
            hashtable_delete(ht, key);
        }
    }
}

/* ESERCIZIO 3 */
TList hashtable_extractList(THashTable* ht, TKey min, TKey max) {
    /*Scrivere una funzione che restituisce una lista (ordinata per chiave) 
    che include tutte le coppie (chiave, valore) di una hash table per cui 
    la chiave è compresa tra due valori min e max.*/

    TList list = list_create();
    
    for (int i = 0; i < ht->bucket_number; i++)
    {
        TNode * curr = ht->bucket[i];
        while (curr) {
            if (curr->info.key > min && curr->info.key < max) {
                list = list_insert(list, curr->info);
            }
            curr = curr->link;
        }
    }

    return list;
}

/* ESERCIZIO 4 */

void hashtable_insertList(THashTable* ht, TList list) {
    /*Scrivere una funzione ricorsiva che inserisce in una hash table ht 
    tutte le coppie (chiave, valore) di una lista solo se la chiave non 
    è già presente in ht.*/

    if (list == NULL) {
        return;
    }
    
    TValue * pvalue = hashtable_search(ht, list->info.key);

    if (pvalue == NULL) {
        hashtable_insert(ht, list->info.key, list->info.value);
    }

    hashtable_insertList(ht, list->link);
}

/* ESERCIZIO 5 */
bool subsetWithHashTable(int* set_T, int* set_S, int sizeT, int sizeS) {
    /*Considerati due insiemi di numeri interi, S = {s1, s2, ..., sm} 
    e T = {t1, t2, ..., tn}, m ≤ n. Si progetti e sviluppi la funzione che, 
    utilizzando una hash table opportunamente dimensionata, 
    verifichi se S (set_S) è un sottoinsieme di T (set_T).*/
 

    THashTable * ht = hashtable_create(sizeS);

    for (int i = 0; i < sizeT; i++) {
        hashtable_insert(ht,hash(set_T[i]), set_T[i]);
    }
    
    for (int i = 0; i < sizeS; i++)
    {
        if(hashtable_search(ht, hash(set_S[i])) == NULL) {
            return false;
        }
    }
    
    return true;
}

/* ESERCIZIO 6 */
bool hashtable_verificaSomma(THashTable* ht, TValue pair_sum) {
    /*Scrivere una funzione che determina se sono presenti nella hash table 
    due valori TValue la cui somma è uguale al parametro sum. 
    In caso affermativo, la funzione restituirà true e stamperà a video 
    i due numeri trovati; altrimenti, restituirà false.*/
    bool flag = false;
    TValue sum;

    for (int i = 0; i < ht->bucket_number; i++)
    {
        TNode * curr1 = ht->bucket[i];
        while (curr1 != NULL) {
            for (int j = 0; j < ht->bucket_number; j++) {
                TNode * curr2 = ht->bucket[j];
                while (curr2 != NULL) {
                    sum = value_add(curr1->info.value, curr2->info.value);

                    if (value_equal(sum, pair_sum)) {
                        flag = true;
                        //STAMPA DEI VALORI
                        printf("\n");
                        value_print(curr1->info.value);
                        printf(" + ");
                        value_print(curr2->info.value);
                        printf(" = ");
                        value_print(sum);
                        printf("\n");
                    }
                    curr2 = curr2->link;
                }
            }
            curr1 = curr1->link;
        }
    }
    return flag;
}

/* ESERCIZIO 7 */
void hashtable_changeKey(THashTable *ht, TKey key, TKey newKey) {
    /*Scrivere una funzione che prende in input un puntatore a una tabella hash 
    ht oltre ai valori key e newKey. Se esiste un elemento in ht con chiave key, 
    allora sostituisce la sua chiave con newKey.*/
    TValue * pvalue = hashtable_search(ht, key);

    if (pvalue != NULL) {
        TValue value = *pvalue;
        hashtable_delete(ht, key);
        hashtable_insert(ht, newKey, value);
    }
}

