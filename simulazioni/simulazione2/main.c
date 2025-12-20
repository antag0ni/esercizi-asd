#include <stdio.h>

#include "tinfo.h"
#include "hashtable.h"
#include "binary_tree.h"
#include "TStack.h"
#include "TQueue.h"

/*
 * COGNOME: .............
 * NOME: ................
 * MATRICOLA: ...........
 *
 * Una biblioteca vuole tener traccia dei libri prestati mediante
 * alcuni elenchi tra cui elenco1 (un BST), elenco2 (una HT),
 * elenco3 (una coda), elenco4 (uno stack).
 * In ciascuna struttura un libro è rappresentato
 * da un codice numerico (campo chiave) e da un titolo.
 * Elenco1 contiene tutti i libri presenti in biblioteca.
 * Elenco2 contiene l'elenco dei libri non disponibili per il prestito.
 * Elenco3 contiene le richieste di prestito.
 * Elenco4 contiene una pila di libri restituiti che il bibliotecario
 * non ha ancora sistemato negli scaffali.
 * Si dovra' realizzare un programma che cancelli da elenco2 tutti
 * i libri presenti in elenco4. Successivamente dovrà gestire le nuove richieste
 * di prestito cancellando da elenco3 le sole richieste evase.
 * Infine il programma dovrà vericare se per il bst ogni nodo dell'albero,
 * escluse le foglie, abbia un nodo destro ed un nodo sinistro.
 * Per realizzare tale programma occorre sviluppare le seguenti funzioni.
 *
 * 1) void HT_rimuovi_libri_restituiti(THashTable* ht, TStack *stack):
 *    funzione ITERATIVA che rimuove da ht tutti i libri presenti in stack.
 *
 * 2) TList evadi_prestiti(const TBinaryTree bst, THashTable* ht, TQueue* queue):
 *    funzione ITERATIVA che restituisce una lista con le richieste di prestito
 *    evase ed aggiorna ht di conseguenza. La richiesta può essere evasa solo se
 *    il libro non è già in prestito, e se il libro è presente nell' Elenco1 (bst).
 *    Elenco1 non deve essere modificato.
 *    Aggiorna la coda in base alle richieste evase.
 *
 * 3) TList list_delete_odd(list): funzione RICORSIVA che elimina da list tutti i
 *    libri con ISBN dispari. Restituisce la lista aggiornata.
 *
 * 4) int is_full_binary_tree(TBinaryTree root, int* height): funzione RICORSIVA
 *    che controlla se ogni nodo di un albero, escluse le foglie,
 *    ha un nodo destro ed un nodo sinistro.
 *    Inoltre deve valorizzare altezza con l'latezza massima dell'albero
 *
 * Lo scheletro delle funzioni è già presente nel file main.c. La funzione main
 * è già fornita ed include del codice di test che riempie le strutture con i dati
 * di alcuni libri e richiama le funzioni necessarie. E' altresì fornito il codice
 * delle strutture dati richieste. Si suggerisce di testare le funzioni anche con
 * valori diversi da quelli forniti.
 *
 * si ricorda che per le strutture dati quali code e stack è vietato utilizzare i
 * dettagli implementativi, sfruttando l'incapsulamento.
 *
 */
void HT_rimuovi_libri_restituiti(THashTable* ht, TStack* stack);

TList evadi_prestiti(const TBinaryTree bst, THashTable* ht, TQueue* queue);

TList list_delete_odd(TList list);

// Funzione per verificare se ogni nodo ha entrambi i sottoalberi e calcolare l'altezza
bool is_full_binary_tree(TBinaryTree root, int *height);

int main()
{
    TBinaryTree elenco1 = binarytree_create();
    /*
     * L'albero cosi' inserito soddisfa la qualita' che ogni nodo abbia
     * un sottoalbero sinistro ed uno destro, foglie escluse.
     * Basta commentare, ad esempio, una delle prime tre insert affinche' la proprieta'
     * non sia soddisfatta
     */
    elenco1 = binarytree_insert(elenco1, (TInfo){2372, "Orgoglio e pregiudizio"});
    elenco1 = binarytree_insert(elenco1, (TInfo){4223, "Delitto e castigo"});
    elenco1 = binarytree_insert(elenco1, (TInfo){3432, "Finzioni"});
    elenco1 = binarytree_insert(elenco1, (TInfo){1448, "Il processo"});
    elenco1 = binarytree_insert(elenco1, (TInfo){2234, "Madame Bovary"});
    elenco1 = binarytree_insert(elenco1, (TInfo){1238, "L'amore ai tempi del colera"});
    elenco1 = binarytree_insert(elenco1, (TInfo){1321, "Le mille e una notte"});
    elenco1 = binarytree_insert(elenco1, (TInfo){6643, "Il vecchio e il mare"});
    elenco1 = binarytree_insert(elenco1, (TInfo){1111, "Anna Karenina"});
    elenco1 = binarytree_insert(elenco1, (TInfo){9090, "Le metamorfosi"});
    elenco1 = binarytree_insert(elenco1, (TInfo){5357, "Il rosso e il nero"});
    elenco1 = binarytree_insert(elenco1, (TInfo){1112, "Alla ricerca del tempo perduto"});
    elenco1 = binarytree_insert(elenco1, (TInfo){1110, "L'uomo senza qualità"});
    elenco1 = binarytree_insert(elenco1, (TInfo){9111, "Moby-Dick"});
    elenco1 = binarytree_insert(elenco1, (TInfo){8059, "Pippi Calzelunghe"});

    printf("\n");

    THashTable *elenco2 = hashtable_create(5);
    hashtable_insert(elenco2, 5357, (TValue){"Il rosso e il nero"});
    hashtable_insert(elenco2, 9111, (TValue){"Moby-Dick"});
    hashtable_insert(elenco2, 1448, (TValue){"Il processo"});
    hashtable_insert(elenco2, 8059, (TValue){"Pippi Calzelunghe"});
    hashtable_insert(elenco2, 1110, (TValue){"L'uomo senza qualità"});
    hashtable_insert(elenco2, 1111, (TValue){"Anna Karenina"});
    hashtable_insert(elenco2, 9090, (TValue){"Le metamorfosi"});
    hashtable_insert(elenco2, 3432, (TValue){"Finzioni"});

    TQueue elenco3 = queue_create(10);
    queue_add(&elenco3, (TInfo){8059, "Pippi Calzelunghe"});
    queue_add(&elenco3, (TInfo){1110, "L'uomo senza qualità"});
    queue_add(&elenco3, (TInfo){1111, "Anna Karenina"});
    queue_add(&elenco3, (TInfo){9090, "Le metamorfosi"});
    queue_add(&elenco3, (TInfo){3432, "Finzioni"});
    queue_add(&elenco3, (TInfo){7548, "I Promessi Sposi"});
    queue_add(&elenco3, (TInfo){1112, "Alla ricerca del tempo perduto"});

    TStack elenco4 = stack_create();
    stack_push(&elenco4, (TInfo){1111, "Anna Karenina"});
    stack_push(&elenco4, (TInfo){3432, "Finzioni"});
    stack_push(&elenco4, (TInfo){9090, "Le metamorfosi"});
    stack_push(&elenco4, (TInfo){5357, "Il rosso e il nero"});

    printf("Libri in elenco1 (BST):\n");
    binarytree_visit(elenco1);
    printf("\nLibri in elenco2 (HT):\n");
    hashtable_print(elenco2);

    printf("\nRimuovo da elenco2 tutti i libri restituiti presenti in elenco4.\nLibri in elenco2 (HT):\n");
    HT_rimuovi_libri_restituiti(elenco2, &elenco4);
    hashtable_print(elenco2);

    printf("\nProvo ad evadere le richieste di prestito.\nLibri in elenco2 (HT):\n");
    TList list_richieste_evase = list_create();
    list_richieste_evase = evadi_prestiti(elenco1, elenco2, &elenco3);
    hashtable_print(elenco2);
    printf("\nRichieste evase:\n");
    list_print(list_richieste_evase);

    printf("\nRichieste evase (dopo la rimozione degli ISBN dispari):\n");
    list_richieste_evase = list_delete_odd(list_richieste_evase);
    list_print(list_richieste_evase);

    int altezza = 0;
    if (is_full_binary_tree(elenco1, &altezza))
        printf("\nL'albero di altezza %d soddisfa la qualita' richiesta", altezza);
    else
        printf("\nL'albero di altezza %d non soddisfa la qualita' richiesta", altezza);

    binarytree_destroy(elenco1);
    hashtable_destroy(elenco2);
    queue_destroy(&elenco3);
    stack_destroy(&elenco4);
    list_destroy(list_richieste_evase);
    return 0;
}

void HT_rimuovi_libri_restituiti(THashTable* ht, TStack* stack)
{
    /* COMPLETARE QUESTA FUNZIONE - SEGUE CODICE DA RIMUOVERE */
    while (!stack_is_empty(stack))
    {
        TInfo libro = stack_pop(stack);
        TValue * pvalue = hashtable_search(ht, libro.key);
        if (pvalue != NULL) 
        {
            hashtable_delete(ht, libro.key);
        }
    }    
}

TList evadi_prestiti(const TBinaryTree bst, THashTable* ht, TQueue* queue)
{
    /* COMPLETARE IL CORPO DELLA FUNZIONE */
    TList list = list_create();
    TQueue new_queue = queue_create(10);
    while (!queue_is_empty(queue))
    {
        TInfo richiesta = queue_remove(queue);

        if (hashtable_search(ht, richiesta.key) == NULL && 
            binarytree_search(bst, richiesta) != NULL)
        {
            list = list_insert(list, richiesta);
            hashtable_insert(ht, richiesta.key, richiesta.value);
        } 
        else
            queue_add(&new_queue, richiesta);
    }
    while (!queue_is_empty(&new_queue))
    {
        queue_add(queue, queue_remove(&new_queue));
    }
    return list;
}

TList list_delete_odd(TList list)
{
    /* COMPLETARE IL CORPO DELLA FUNZIONE */
    if (list == NULL)
        return list;
    TList new_list = list_delete_odd(list->link);
    if ((list->info.key) % 2 == 0)
        new_list = list_insert(new_list, list->info);
    return new_list;
}

// Funzione per verificare se ogni nodo ha entrambi i sottoalberi e calcolare l'altezza
bool is_full_binary_tree(TBinaryTree root, int* height)
{
    /* COMPLETARE IL CORPO DELLA FUNZIONE */
    //caso in cui l'albero non esista
    if (root == NULL) 
    {
        *height = 0;
        return true;
    }
    //caso in cui la radice è una foglia
    if (root->left == NULL && root->right == NULL)
    {
        *height = 1;
        return true;
    }
    //divido in due sotto alberi e calcolo le altezze separatamente
    int left_height, right_height;
    bool full_left = is_full_binary_tree(root->left, &left_height);
    bool full_right = is_full_binary_tree(root->right, &right_height);
    //prendo l'altezza maggiore delle due e la incremento
    *height = (left_height > right_height ? left_height : right_height) + 1;
    //ritorna vero se i sotto alberi esistono e sono pieni
    return (root->left!=NULL && root->right!=NULL && full_left && full_right);
}