#include "dstack.h"

TDStack dstack_create(void)
{
    TDStack s;
    s.array = array_create(0);
    return s;
}

void dstack_destroy(TDStack *stack)
{
    array_destroy(&stack->array);
}

void dstack_push(TDStack *stack, const TInfo elem)
{
    int n = stack->array.length;
    enum growing_mode GM = LINEAR;
    array_resize(&stack->array, n + 1, GM);
    stack->array.item[n] = elem;
}

TInfo dstack_pop(TDStack *stack)
{
    int n = stack->array.length;
    if (n == 0)
    {
        TInfo empty;
        printf("Lo stack è vuoto!\n");
        return empty;
    }
    TInfo elem = stack->array.item[n - 1];
    enum growing_mode GM = LINEAR;
    array_resize(&stack->array, n - 1, GM);
    return elem;
}

TInfo dstack_top(const TDStack *stack)
{
    int n = stack->array.length;
    if (n == 0)
    {
        TInfo empty;
        printf("Lo stack è vuoto!\n");
        return empty;
    }
    TInfo elem = stack->array.item[n - 1];
    return elem;
}

/* controlla se lo stack e' vuoto*/
bool dstack_is_empty(const TDStack *stack)
{
    return stack->array.length == 0;
}
