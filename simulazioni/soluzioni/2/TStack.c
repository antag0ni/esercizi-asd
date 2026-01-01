/*
 * TStack: implementazione di uno stack attraverso un array dinamico
 */
#include "TStack.h"

TStack stack_create(void) {
    TStack s;
    s.array = array_create(0);
    return s;
}

void stack_destroy(TStack *stack) {
    array_destroy(&stack->array);
}

void stack_push(TStack *stack, const TInfo x) {
    int n = stack->array.length;
    enum growing_mode GM = LINEAR;
    array_resize(&stack->array, n + 1, GM);
    stack->array.items[n] = x;
}

TInfo stack_pop(TStack *stack) {
    int n = stack->array.length;
    if (n == 0) {
        TInfo empty;
        return empty;
    }
    TInfo elem = stack->array.items[n - 1];
    enum growing_mode GM = LINEAR;
    array_resize(&stack->array, n - 1, GM);
    return elem;
}

TInfo stack_top(const TStack *stack) {
    int n = stack->array.length;
    if (n == 0) {
        TInfo empty;
        return empty;
    }
    TInfo elem = stack->array.items[n - 1];
    return elem;
}

bool stack_is_empty(const TStack *stack) {
    return stack->array.length == 0;
}
