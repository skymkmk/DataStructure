#ifndef STACK_H
#define STACK_H
#include "linklist.h"

LStack newStack(const int value);
void push(LStack* stack, const int value);
int pop(LStack* stack);
#endif