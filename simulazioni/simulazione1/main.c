#include <stdio.h>
#include <stdlib.h>

#include "tinfo_corsi.h"
#include "tinfo_studenti.h"
#include "hashtable.h"
#include "binary_tree.h"

/*
 * È dato un BST contenente un elenco di studenti ordinati per matricola.
 * Ciascun elemento del BST contiene, oltre la matricola, il nome dello
 * studente ed il codice del corso a cui è iscritto.
 *
 * È data inoltre una Hash Table contenente l'elenco dei corsi attivi presso
 * l'Università di Smallville. Ciascun elemento della Hash Table contiene il
 * codice del corso (campo chiave), il nome dello stesso ed il numero di
 * studenti iscritti (inizialmente impostato a 0).
 *
 * Si desidera sviluppare un'applicazione in grado di stampare il nome del
 * corso (o dei corsi in caso di corsi con il medesimo numero di iscritti)
 * con il maggior numero di studenti iscritti.
 *
 * Per fare ciò si sviluppino le seguenti funzioni:
 *
 * - bst_updateHT(bst_studenti, ht_corsi)
 *   che aggiorna la hash table dei corsi con il numero corretto di iscritti
 *   per corso sulla base dell'elenco di studenti contenuto nel bst
 * - hashtable_printHighest(ht_corsi)
 *   che stampa il nome del corso (o dei corsi) con il numero massimo di
 *   studenti iscritti
 * - la parte mancante della funzione main
 *   che contiene la logica applicativa e richiama le funzioni necessarie
 *   al corretto funzonamento del programma
 *
 * NOTA: non è possibile modificare la firma delle funzioni.
 *
 * Il candidato può (ed è incoraggiato a) cambiare il contenuto iniziale delle
 * strutture dati per testare approfonditamente la propria soluzione.
 *
 */

void bst_updateHT(TBinaryTree tree, THashTable *ht);
void hashtable_printHighest(THashTable *ht);

int main()
{
    TBinaryTree studenti = binarytree_create();
    studenti = binarytree_insert(studenti, (TInfo_studenti){123423, "Clark Kent", 1});
    studenti = binarytree_insert(studenti, (TInfo_studenti){123211, "Lana Lang", 1});
    studenti = binarytree_insert(studenti, (TInfo_studenti){123210, "Lex Luthor", 1});
    studenti = binarytree_insert(studenti, (TInfo_studenti){123233, "Chloe Sullivan", 4});
    studenti = binarytree_insert(studenti, (TInfo_studenti){123643, "Lois Lane", 3});
    studenti = binarytree_insert(studenti, (TInfo_studenti){123234, "Jonathan Kent", 3});
    studenti = binarytree_insert(studenti, (TInfo_studenti){123322, "Martha Kent", 3});
    studenti = binarytree_insert(studenti, (TInfo_studenti){123643, "Lionel Luthor", 4});
    studenti = binarytree_insert(studenti, (TInfo_studenti){123244, "Pete Ross", 4});
    studenti = binarytree_insert(studenti, (TInfo_studenti){123321, "Oliver Queen", 5});
    printf("Studenti:\n");
    binarytree_visit(studenti);

    THashTable* corsi = hashtable_create(10);
    hashtable_insert(corsi, 1, (TValue){"Ingegneria Informatica", 0});
    hashtable_insert(corsi, 2, (TValue){"Ingegneria Elettronica", 0});
    hashtable_insert(corsi, 3, (TValue){"Matematica", 0});
    hashtable_insert(corsi, 4, (TValue){"Informatica", 0});
    hashtable_insert(corsi, 5, (TValue){"Fisica", 0});
    hashtable_insert(corsi, 6, (TValue){"Chimica", 0});
    printf("\nCorsi disponibili:\n");
    hashtable_print(corsi);

    /* INSERIRE QUI LA LOGICA APPLICATIVA */



    hashtable_destroy(corsi);
    binarytree_destroy(studenti);
}


void bst_updateHT(TBinaryTree tree, THashTable *ht)
{
    /* INSERIRE QUI IL CORPO DELLA FUNZIONE */

}

void hashtable_printHighest(THashTable *ht)
{

    /* INSERIRE QUI IL CORPO DELLA FUNZIONE */

}