#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tinfo.h"
#include "hashtable.h"
#include "binary_tree.h"
#include "array.h"
#include "dqueue.h"

/*
 * COGNOME: .............
 * NOME: ................
 * MATRICOLA: ...........
 *
 *
 *
 * La segreteria di una Universita' deve riorganizzare alcuni elenchi di studenti
 * tra cui elenco1 (un BST) ed elenco2 (un HT). In ciascuna struttura uno studente
 * è rappresentato dalla matricola (campo chiave), dal nome e dal cognome.
 *
 * Si dovrà realizzare un programma che sposti tutti gli studenti con matricola
 * compresa in un certo range da elenco 1 a elenco 2. Se uno studente selezionato
 * e' presente in elenco 2 esso non andrà inserito ma dovrà essere ugualmente
 * rimosso da elenco 1.
 * Successivamente da elenco 2 andranno rimossi tutti gli studenti il cui numero
 * di matricola è multiplo di un numero indicato.
 *
 * Al termine andranno stampati a video per ordine di prenotazione
 * solo gli studenti presenti in elenco 1 che si sono prenotati per
 * un dato esame. L'elenco dei prenotati è memorizzato in elenco 3 (una CODA).
 *
 * Per realizzare tale programma occorre sviluppare le seguenti funzioni.
 *
 * 1) bst_to_ht_by_matricola(bst, ht, min, max): funzione RICORSIVA che
 *    copia da bst a ht tutti gli studenti con matricola compresa fra
 *    min e max (inclusi).
 *    Gli studenti con matricola compresa fra min e max andranno rimossi da bst.
 *
 * 2) ht_remove_by_divisor_number(ht, number): funzione ITERATIVA che cancella
 *    da ht tutti gli studenti il cui numero di matricola è multiplo di number.
 *    Si suggerisce di utilzzare un array dinamico di appoggio per memorizzare
 *    tutti gli studenti da cancellare.
 *    HINT: se matricola = 1234 e number = 4 --> matricola % number = 2
 *          se matricola = 1234 e number = 2 --> matricola % number = 0 --> multiplo
 *          se matricola = 4236 e number = 5 --> matricola % number = 1
 *          se matricola = 4236 e number = 3 --> matricola % number = 0 --> multiplo
 *
 * 3) print_student_by_reservation(queue, bst, codice_esame): funzione che stampa
 *    tutti gli studenti in elenco 1 con una prenotazione in elenco 3 per un
 *    particolare codice_esame.
 *
 * Nel main, dove richiesto, andranno inserite le invocazioni alle funzioni
 * da implementare.
 *
 * I prototipi delle funzioni sono gia' presenti nel file main.c. La funzione main
 * e' gia' fornita e include del codice di test che riempie le strutture con i dati
 * di alcuni studenti e richiama le funzioni necessarie. E', altresi', fornito il codice
 * delle strutture dati richieste. Si suggerisce di testare le funzioni anche con
 * valori diversi da quelli forniti.
 *
 * Rendere il codice modulare e generale, sfruttando il tipo TInfo.
 *
 */

TBinaryTree bst_to_ht_by_matricola(TBinaryTree bst, THashTable *ht, int min, int max)
{

    /* COMPLETARE QUESTA FUNZIONE */

}

void ht_remove_by_divisor_number(THashTable *ht, int number)
{

    /* COMPLETARE QUESTA FUNZIONE */

}

void print_student_by_reservation(TDQueue *queue, TBinaryTree bst, int codice_esame)
{

    /* COMPLETARE QUESTA FUNZIONE */
    
}

int main()
{
    int min = 1300, max = 2000, number = 1, codice_esame = 1818;
    // int min = 2000, max = 4000, number = 2, codice_esame = 1818;

    TBinaryTree elenco1 = binarytree_create();
    elenco1 = binarytree_insert(elenco1, (TInfo){1321, "Mario", "Rossi"});
    elenco1 = binarytree_insert(elenco1, (TInfo){2372, "Antonio", "Bianchi"});
    elenco1 = binarytree_insert(elenco1, (TInfo){3432, "Lucia", "Verdi"});
    elenco1 = binarytree_insert(elenco1, (TInfo){4223, "Camilla", "Neri"});
    elenco1 = binarytree_insert(elenco1, (TInfo){1445, "Aldo", "Giallini"});
    elenco1 = binarytree_insert(elenco1, (TInfo){2234, "Carlo", "Aranci"});
    elenco1 = binarytree_insert(elenco1, (TInfo){1238, "Maria", "Scarlatti"});
    elenco1 = binarytree_insert(elenco1, (TInfo){6643, "Luigi", "Turchesi"});
    elenco1 = binarytree_insert(elenco1, (TInfo){1111, "Giovanni", "Argento"});

    THashTable *elenco2 = hashtable_create(5);
    hashtable_insert(elenco2, 3357, (TValue){"Nicola", "Grigetti"});
    hashtable_insert(elenco2, 7675, (TValue){"Costanza", "Violetti"});
    hashtable_insert(elenco2, 4222, (TValue){"Filippa", "Azzurri"});
    hashtable_insert(elenco2, 1445, (TValue){"Aldo", "Giallini"});
    hashtable_insert(elenco2, 3233, (TValue){"Anna", "Indaco"});
    hashtable_insert(elenco2, 3321, (TValue){"Luigi", "Rosi"});
    hashtable_insert(elenco2, 1111, (TValue){"Giovanni", "Argento"});
    hashtable_insert(elenco2, 3432, (TValue){"Lucia", "Verdi"});
    hashtable_insert(elenco2, 1238, (TValue){"Maria", "Scarlatti"});

    TDQueue elenco3 = dqueue_create(20);
    dqueue_add(&elenco3, (TInfo2){3357, 2222});
    dqueue_add(&elenco3, (TInfo2){7675, 3030});
    dqueue_add(&elenco3, (TInfo2){4222, 1919});
    dqueue_add(&elenco3, (TInfo2){1445, 2323});
    dqueue_add(&elenco3, (TInfo2){3233, 2727});
    dqueue_add(&elenco3, (TInfo2){3321, 2525});
    dqueue_add(&elenco3, (TInfo2){1111, 1818});
    dqueue_add(&elenco3, (TInfo2){3432, 3030});
    dqueue_add(&elenco3, (TInfo2){1238, 2525});
    dqueue_add(&elenco3, (TInfo2){3357, 3030});
    dqueue_add(&elenco3, (TInfo2){7675, 1919});
    dqueue_add(&elenco3, (TInfo2){6643, 1818});
    dqueue_add(&elenco3, (TInfo2){1445, 2727});
    dqueue_add(&elenco3, (TInfo2){3233, 2525});
    dqueue_add(&elenco3, (TInfo2){3432, 1818});
    dqueue_add(&elenco3, (TInfo2){1111, 3030});
    dqueue_add(&elenco3, (TInfo2){3432, 2525});
    dqueue_add(&elenco3, (TInfo2){1238, 2222});

    printf("Studenti in elenco1 (BST):\n");
    binarytree_visit(elenco1);
    printf("\nStudenti in elenco2 (HT):\n");
    hashtable_print(elenco2);

    /* INSERIRE CODICE QUI */
    elenco1 = bst_to_ht_by_matricola(elenco1, elenco2, min, max);

    printf("\nStudenti in elenco1 (BST) dopo lo spostamento:\n");
    binarytree_visit(elenco1);
    printf("\nStudenti in elenco2 (HT) dopo lo spostamento:\n");
    hashtable_print(elenco2);

    ht_remove_by_divisor_number(elenco2, number);
    printf("\nStudenti in elenco2 (HT) dopo la cancellazione:\n");
    hashtable_print(elenco2);

    /* INSERIRE CODICE PER STAMPA ELENCO PRENOTATI */
    printf("\nStudenti in elenco1 (BST) che hanno inserito una prenotazione per l'esame %d:\n", codice_esame);
    print_student_by_reservation(&elenco3, elenco1, codice_esame);

    binarytree_destroy(elenco1);
    hashtable_destroy(elenco2);
    dqueue_destroy(&elenco3);

    return 0;
}
