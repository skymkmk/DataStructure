#include "stack.h"
#include <stdlib.h>

LStack newStack(const int value) {
    LStack stack = (LStack)malloc(sizeof(LNode));
    stack->data = value;
    stack->next = NULL;
    return stack;
}

void push(LStack *stack, const int value) {
    LStack top = newStack(value);
    top->next = *stack;
    *stack = top;
}

int pop(LStack *stack) {
    int value = (*stack)->data;
    LStack tmp = *stack;
    *stack = (*stack)->next;
    free(tmp);
    return value;
}