#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "TInfo.h"

/*
A partire dalle librerie fornite sugli Alberi Binari di Ricerca (BST), 
realizzare le versioni iterative delle operazioni di ricerca e inserimento di un nuovo nodo.

Realizzare, alresì, le principali funzioni di accumulazione (mediante il paradigma ricorsivo) 
su BST secondo i seguenti prototipi:
*/
TBTNode *binarytree_search_iterative(TBinaryTree bt, TInfo info);
TBinaryTree binarytree_insert_iterative(TBinaryTree bt, TInfo info);
TInfo binarytree_sum_nodes(TBinaryTree);
int binarytree_count_nodes(TBinaryTree);
int binarytree_count_leaves(TBinaryTree);
TInfo binarytree_sum_leaves(TBinaryTree);
int binarytree_height(TBinaryTree);
int binarytree_depth(TBinaryTree);
int binarytree_nodeVal_depth(TBinaryTree, TInfo); 
void printTree(TBinaryTree, int);

int main(int argc, char **argv) {
    TBinaryTree bt = binarytree_create();
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    size_t n = sizeof(values) / sizeof(values[0]);

    printf("[*]Creazione albero e inserimento valori.\n");
    for (size_t i = 0; i < n; ++i) {
        bt = binarytree_insert(bt, values[i]);
    }

    TBTNode *elem_trovato = binarytree_search_iterative(bt, 60);
    if (elem_trovato != NULL) {
        printf("Elemento 60 trovato (iterativo).\n");
    } else {
        printf("Elemento 60 non trovato (iterativo).\n");
    }
    TBTNode *elem_trovato2 = binarytree_search_iterative(bt, 42);
    if (elem_trovato2 != NULL) {
        printf("Elemento 32 trovato (iterativo).\n");
    } else {
        printf("Elemento 32 non trovato (iterativo).\n");
    }

    bt = binarytree_insert_iterative(bt, 42);
    printf("[*]Inserito elemento 42 (iterativo).\n");
    printf("visita in-order dopo inserimento 42:\n");
    binarytree_visit(bt);
    printf("\n");
    

    printf("Stampa a video dell'albero (ruotato):\n");
    printTree(bt, 5);
    printf("\n");

    printf("Somma di tutti i nodi: %d\n", binarytree_sum_nodes(bt));
    printf("Conteggio totale dei nodi: %d\n", binarytree_count_nodes(bt));
    printf("Conteggio delle foglie: %d\n", binarytree_count_leaves(bt));
    printf("Somma dei valori delle foglie: %d\n", binarytree_sum_leaves(bt));
    printf("Altezza dell'albero: %d\n", binarytree_height(bt));
    printf("Profondità dell'albero: %d\n", binarytree_depth(bt));
    printf("Profondità del nodo con valore 30: %d\n", binarytree_nodeVal_depth(bt, 30));

    bt = binarytree_destroy(bt);
    if (bt == NULL)
        printf("[*]Albero distrutto correttamente.\n");
    else
        printf("[*]Errore nella deallocazione dell'albero.\n");

    return (EXIT_SUCCESS);
}

/* Prototipi richiesti (dichiarati in `main.c` come promemoria per l'implementazione):
     *
     * Versioni iterative (da implementare in forma ITERATIVA):
     */
    /* Cerca l'elemento di valore `info` in modo iterativo. Ritorna il riferimento
     * al nodo se presente, altrimenti NULL. (Iterativa)
     */
    TBTNode *binarytree_search_iterative(TBinaryTree bt, TInfo info) {
        TBTNode * curr = bt;
        while (curr!=NULL)
        {
            if (curr->info == info)
                return curr;
            if (curr->info > info)
            {
                curr = curr->left; //spostamento a sinistra
            } else if (curr->info < info)
            {
                curr = curr->right; //spostamento a destra
            }
        }
        return NULL; //nodo non trovato
    }

    /* Inserisce l'elemento di valore `info` preservando l'ordinamento.
     * Implementare la versione iterativa che non usa ricorsione esplicita.
     * Restituisce l'albero risultante (potrebbe essere la nuova radice).
     * (Iterativa)
     */
    TBinaryTree binarytree_insert_iterative(TBinaryTree bt, TInfo info) {
        TBTNode * new = node_create(info);
        if (new == NULL) {
            printf("Errore di allocazione della memoria\n");
            return bt;
        }
        if (bt == NULL)
        {
            return new; //albero vuoto, il nuovo nodo e' la radice
        }
        TBTNode* curr = bt;
        while (curr != NULL)
        {
            if (info < curr->info) {
                if (curr->left == NULL)
                {
                    //inserimento a sinistra
                    curr->left = new;
                    return bt;
                } else {
                    curr = curr->left;
                }
            } else if (info > curr->info) {
                if (curr->right == NULL)
                {
                    //inserimento a destra
                    curr->right = new;
                    return bt;
                } else {
                    curr = curr->right;
                }
            }
            
        }
        
        
    }

    /* Funzioni di accumulazione e caratteristiche dell'albero (da realizzare
     * usando il paradigma RICORSIVO):
     */
    /* Restituisce la somma (somma aritmetica) di tutti i valori `TInfo` presenti
     * nei nodi dell'albero. (Ricorsiva)
     */
    TInfo binarytree_sum_nodes(TBinaryTree bt) {
        if (bt == NULL) {
          return 0;
        }
        TInfo sum = binarytree_sum_nodes(bt->left) + binarytree_sum_nodes(bt->right) + bt->info;
        return sum;
    }

    /* Conta e ritorna il numero totale di nodi nell'albero. (Ricorsiva)
     */
    int binarytree_count_nodes(TBinaryTree bt) {
        if (bt == NULL) {
          return 0;
        }
        int cont = binarytree_count_nodes(bt->left) + binarytree_count_nodes(bt->right);
        return cont + 1;
    }

    /* Conta e ritorna il numero di foglie (nodi senza figli). (Ricorsiva)
     */
    int binarytree_count_leaves(TBinaryTree bt) {
        if (bt == NULL) {
          return 0;
        }

        int cont = binarytree_count_leaves(bt->left) + binarytree_count_leaves(bt->right);
        
        if (bt->left == NULL && bt->right == NULL)
            cont++;

        return cont;

    }

    /* Restituisce la somma dei valori `TInfo` presenti solo nelle foglie.
     * (Ricorsiva)
     */
    TInfo binarytree_sum_leaves(TBinaryTree bt) {
        if (bt == NULL) {
          return 0;
        }

        TInfo sum = binarytree_sum_leaves(bt->left) + binarytree_sum_leaves(bt->right);

        if (bt->left == NULL && bt->right == NULL)
        {
            return sum + bt->info;
        } else return sum;
    }

    /* Altezza dell'albero e profondità.
     * - `binarytree_height`: ritorna l'altezza espressa come numero di nodi
     *   nel cammino più lungo da radice a foglia (es. 0 se bt==NULL, 1 se solo
     *   la radice). (Ricorsiva)
     * - `binarytree_depth`: ritorna la profondità espressa come numero di archi
     *   nel cammino più lungo da radice a foglia (es. -1 se bt==NULL, 0 se solo
     *   la radice). (Ricorsiva)
     */
    int binarytree_height(TBinaryTree bt) {
        if (bt == NULL) {
            return 0;
        }
        if (bt->left == NULL && bt->right == NULL) {
            return 1;
        }
        int left_height = binarytree_height(bt->left);
        int right_height = binarytree_height(bt->right);
        return (left_height>right_height ? left_height : right_height) + 1;
    }

    int binarytree_depth(TBinaryTree bt) {
        if (bt == NULL) {
            return -1;
        }
        if (bt->left == NULL && bt->right == NULL) {
            return 0;
        }
        int left_depth = binarytree_depth(bt->left);
        int right_depth = binarytree_depth(bt->right);
        return (left_depth>right_depth ? left_depth : right_depth) + 1;
        
    }

//  Calcolo della profondità di un nodo, 
//  dato il proprio valore TInfo (-1 per elemento non trovato) (ricorsiva)
int binarytree_nodeVal_depth(TBinaryTree bt, TInfo info) {
    
    if (bt == NULL) {
        return -1; // elemento non trovato
    }
    if (bt->info == info) {
        return 0; // elemento trovato alla radice
    }
    
    int left_depth = binarytree_nodeVal_depth(bt->left, info);
    if (left_depth != -1) {
        return left_depth + 1; // elemento trovato nel sottoalbero sinistro
    }
    
    int right_depth = binarytree_nodeVal_depth(bt->right, info);
    if (right_depth != -1) {
        return right_depth + 1; // elemento trovato nel sottoalbero destro
    }
   
    return -1; // elemento non trovato in entrambi i sottoalberi
}

//stampa a video dell'albero
void printTree(TBinaryTree bt, int space) {
    if (bt == NULL) {
      return;
    }
    space += 5;
    printTree(bt->right, space);
    
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d", bt->info);

    printTree(bt->left, space);
}
