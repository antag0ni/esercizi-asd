/*
 * Una struttura ospedaliera deve riorganizzare alcuni elenchi di pazienti 
 * tra cui elenco1 (un BST) ed elenco2 (una HT). In ciascuna struttura, un paziente
 * e' rappresentato da un ID (campo chiave), dal nome e dal cognome.
 * In tutte le strutture coinvolte, i pazienti con esenzione dal ticket
 * vengono indicati con uno 0 finale nel loro ID.
 * 
 * Si dovrà realizzare un programma che sposti tutti i pazienti con esenzione
 * (ID la cui ultima cifra sia 0) da elenco1 ad elenco2, rimuovendo
 * gli eventuali duplicati. Inoltre, si dovranno copiare in elenco3 (un TArray)
 * tutti i pazienti di elenco2 con ID compreso tra min e max, rimuovendoli anche da ht.
 * Bisogna anche rimuovere da elenco1 il paziente con ID piu' grande.
 *
 * Per realizzare tale programma occorre sviluppare le seguenti funzioni.
 *    
 * 1) bst_toHT_exemption(bst, ht): funzione RICORSIVA che copia da bst a ht tutti i
 *    pazienti con ID la cui ultima cifra sia 0, rimuovendoli da bst.
 *    Se un paziente di bst gia' esiste in ht esso non verra'
 *    duplicato (ma verra' comunque rimosso da bst).
 * 
 * 2) ht_toArray_range(ht, array, min, max): funzione ITERATIVA che copia da ht ad array
 *    tutti i pazienti con ID compreso tra min e max e, inoltre, li rimuove da ht.
 *
 * 3) binarytree_removeLast(bst): funzione RICORSIVA che rimuove da bst l'ultimo
 *    elemento in ordine di ID (ossia il paziente con ID massimo). 
 *    Restituisce il bst aggiornato.
 * 
 * 4) print_orderedArray(array): funzione ITERATIVA che stampa in ordine crescente di ID
 *    solo i pazienti con esenzione. Si possono utilizzare strutture dati di appoggio.
 *  
 * 
 * I prototipi delle funzioni sono gia' presenti nel file main.c. La funzione main 
 * e' gia' fornita e include del codice di test che riempie le strutture con i dati 
 * di alcuni pazienti e richiama le funzioni necessarie. E' altresi' fornito il codice 
 * delle strutture dati richieste. Si suggerisce di testare le funzioni anche con 
 * valori diversi da quelli forniti.
 * Rendere il codice generale, sfruttando il tipo TInfo.
 *
 */

/* *************
 * COGNOME: .............
 * NOME: ................
 * MATRICOLA: ...........
 */

#include <stdio.h>
#include "hashtable.h"
#include "binary_tree.h"
#include "TArray.h"

int patient_hasExemption(TInfo patient){
    /* COMPLETARE QUESTA FUNZIONE */
    
}

TBinaryTree bst_toHT_exemption(TBinaryTree bst, THashTable* ht) {
/*    bst_toHT_exemption(bst, ht): funzione RICORSIVA che copia da bst a ht tutti i
 *    pazienti con ID la cui ultima cifra sia 0, rimuovendoli da bst.
 *    Se un paziente di bst gia' esiste in ht esso non verra'
 *    duplicato (ma verra' comunque rimosso da bst). 
 */ 
    
}

void ht_toArray_range(THashTable* ht, TArray* array, TKey min, TKey max) {

    /* COMPLETARE QUESTA FUNZIONE */


}

TBinaryTree binarytree_removeLast(TBinaryTree bst) {

    /* COMPLETARE QUESTA FUNZIONE */

}

void print_orderedArray_exemptions(TArray *array) {

    /* COMPLETARE QUESTA FUNZIONE */

}


int main() {
    TBinaryTree elenco1 = binarytree_create();
    elenco1 = binarytree_insert(elenco1, (TInfo) {1320, "Mario", "Rossi"});
    elenco1 = binarytree_insert(elenco1, (TInfo) {2370, "Antonio", "Bianchi"});
    elenco1 = binarytree_insert(elenco1, (TInfo) {3432, "Lucia", "Verdi"});
    elenco1 = binarytree_insert(elenco1, (TInfo) {4223, "Camilla", "Neri"});
    elenco1 = binarytree_insert(elenco1, (TInfo) {4443, "Aldo", "Giallini"});
    elenco1 = binarytree_insert(elenco1, (TInfo) {4230, "Carlo", "Aranci"});
    elenco1 = binarytree_insert(elenco1, (TInfo) {1238, "Maria", "Scarlatti"});
    elenco1 = binarytree_insert(elenco1, (TInfo) {2644, "Luigi", "Turchesi"});
    elenco1 = binarytree_insert(elenco1, (TInfo) {1110, "Giovanni", "Argento"});

    THashTable *elenco2 = hashtable_create(3);
    hashtable_insert(elenco2, 3351, (TValue) {"Nicola", "Grigetti"});
    hashtable_insert(elenco2, 7675, (TValue) {"Costanza", "Violetti"});
    hashtable_insert(elenco2, 4260, (TValue) {"Filippa", "Azzurri"});
    hashtable_insert(elenco2, 4443, (TValue) {"Aldo", "Giallini"});
    hashtable_insert(elenco2, 3233, (TValue) {"Anna", "Indaco"});
    hashtable_insert(elenco2, 6320, (TValue) {"Luigi", "Rosi"});
    hashtable_insert(elenco2, 1110, (TValue) {"Giovanni", "Argento"});
    hashtable_insert(elenco2, 5430, (TValue) {"Lucia", "Verdi"});
    hashtable_insert(elenco2, 1238, (TValue) {"Maria", "Scarlatti"});
    hashtable_insert(elenco2, 3450, (TValue) {"Biagio", "Verdini"});

    printf("Pazienti in elenco1 (BST):\n");
    binarytree_visit(elenco1);
    printf("\nPazienti in elenco2 (HT):\n");
    hashtable_print(elenco2);

    elenco1 = bst_toHT_exemption(elenco1, elenco2);

    printf("\nPazienti in elenco1 (BST) dopo lo spostamento:\n");
    binarytree_visit(elenco1);
    printf("\nPazienti in elenco2 (HT) dopo lo spostamento\n:\n");
    hashtable_print(elenco2);

    TArray elenco3 = array_create(0);
    TKey min = 2000, max = 6000;
    ht_toArray_range(elenco2, &elenco3, min, max);
    
    printf("\nPazienti in elenco3 (Array):\n");
    array_print(&elenco3);
    
    printf("\nPazienti in elenco1 (BST dopo aver rimosso l'elemento con ID massimo):\n");
    elenco1 = binarytree_removeLast(elenco1);
    binarytree_visit(elenco1);
    
    printf("\nPazienti con esenzione in elenco3 (Array) in ordine:\n");
    print_orderedArray_exemptions(&elenco3);

    binarytree_destroy(elenco1);
    hashtable_destroy(elenco2);
    array_destroy(&elenco3);

    return 0;
}
