#include "array2.h"

TArray2 array_create_2(const unsigned int initial_length)
{
    TArray2 a;
    a.item = (TInfo2 *)malloc(initial_length * sizeof(TInfo2));
    assert(initial_length == 0 || a.item != NULL); // NOTA: se initial_length ==0, a.item == NULL
    a.size = initial_length;
    a.length = 0;
    return a;
}

void array_destroy_2(TArray2 *a)
{
    assert(a != NULL);
    if (a->item == NULL)
        return;
    free(a->item);
    a->item = NULL;
    a->length = 0;
    a->size = 0;
}

void array_resize_2(TArray2 *a, const unsigned int new_length,
                  const enum growing_mode_2 GM)
{
    unsigned int new_size = 0;
    switch (GM)
    {
    case LINEAR_2:
        if (new_length > a->size ||
            new_length < a->size - SHRINKING_DELTA)
        {
            new_size = new_length + GROWING_DELTA;
            a->item = realloc(a->item, new_size * sizeof(TInfo2));
            assert(a->item != NULL || new_size == 0);
            a->size = new_size;
        };
        break;
    case GEOMETRIC_2:
        if (new_length > a->size || new_length < a->size / SHRINKING_FACTOR)
        {
            new_size = new_length * GROWING_FACTOR;
            a->item = realloc(a->item, new_size * sizeof(TInfo2));
            assert(a->item != NULL || new_size == 0);
            a->size = new_size;
        };
        break;
    default:
    }
    a->length = new_length; // ATTENZIONE ! Cosa Succede agli elementi che ora sono
                            //  Allocati entro la length e che prima non erano mai
                            //  stati referenziati in scrittura ???
}

// inserisce un nuovo elemento IN CODA
void push_back_2(const TInfo2 elem, TArray2 *a)
{
    assert(a != NULL);
    assert(a->length <= a->size);
    if (a->length == a->size)
    {
        enum growing_mode_2 GM = LINEAR_2;
        array_resize_2(a, a->length, GM);
    }
    a->item[a->length++] = elem;
}

// elimina IN CODA al vettore e torna l'elemento che prima era IN CODA
TInfo2 remove_back_2(TArray2 *a)
{
    if (a->length > 0)
    {
        return a->item[--a->length]; // riempimento è il NUMERO DI elementi, l'ultimo elemento si trova a riempimento-1
    }
}

// stampa il vettore a partire dalla struttura contenitore
// passata per riferimento per evitare la copia
void print_TArray_2(const TArray2 *a)
{
    if (a == NULL)
        return;
    if (a->size <= 0 || a->length <= 0 || a->length > a->size)
        return;

    printf("TArray2[%d/%d]:  [", a->length, a->size);
    TInfo2 *v = a->item;
    for (int i = 0; i < a->length; ++i)
    {
        printf("%d,", v[i]);
    }
    printf("]\n");
}

bool array_contains_2(TArray2 *a, TInfo2 item)
{
    for (int i = 0; i < a->length; i++)
        if (info_equal_2(a->item[i], item))
            return true;
    return false;
}