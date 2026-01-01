#include "array.h"

TArray array_create(const unsigned int initial_length)
{
    TArray a;
    a.item = (TInfo *)malloc(initial_length * sizeof(TInfo));
    assert(initial_length == 0 || a.item != NULL); // NOTA: se initial_length ==0, a.item == NULL
    a.size = initial_length;
    a.length = 0;
    return a;
}

void array_destroy(TArray *a)
{
    assert(a != NULL);
    if (a->item == NULL)
        return;
    free(a->item);
    a->item = NULL;
    a->length = 0;
    a->size = 0;
}

void array_resize(TArray *a, const unsigned int new_length,
                  const enum growing_mode GM)
{
    unsigned int new_size = 0;
    switch (GM)
    {
    case LINEAR:
        if (new_length > a->size ||
            new_length < a->size - SHRINKING_DELTA)
        {
            new_size = new_length + GROWING_DELTA;
            a->item = realloc(a->item, new_size * sizeof(TInfo));
            assert(a->item != NULL || new_size == 0);
            a->size = new_size;
        };
        break;
    case GEOMETRIC:
        if (new_length > a->size || new_length < a->size / SHRINKING_FACTOR)
        {
            new_size = new_length * GROWING_FACTOR;
            a->item = realloc(a->item, new_size * sizeof(TInfo));
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
void push_back(const TInfo elem, TArray *a)
{
    assert(a != NULL);
    assert(a->length <= a->size);
    if (a->length == a->size)
    {
        enum growing_mode GM = LINEAR;
        array_resize(a, a->length, GM);
    }
    a->item[a->length++] = elem;
}

// elimina IN CODA al vettore e torna l'elemento che prima era IN CODA
TInfo remove_back(TArray *a)
{
    if (a->length > 0)
    {
        return a->item[--a->length]; // riempimento è il NUMERO DI elementi, l'ultimo elemento si trova a riempimento-1
    }
}

// stampa il vettore a partire dalla struttura contenitore
// passata per riferimento per evitare la copia
void print_TArray(const TArray *a)
{
    if (a == NULL)
        return;
    if (a->size <= 0 || a->length <= 0 || a->length > a->size)
        return;

    printf("TArray[%d/%d]:  [", a->length, a->size);
    TInfo *v = a->item;
    for (int i = 0; i < a->length; ++i)
    {
        printf("%d,", v[i]);
    }
    printf("]\n");
}

bool array_contains(TArray *a, TInfo item)
{
    for (int i = 0; i < a->length; i++)
        if (info_equal(a->item[i], item))
            return true;
    return false;
}