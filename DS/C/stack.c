#include <stdio.h>

typedef struct _stack{
	char value[100];
	int top;
} _stack;

void PUSH(char c, _stack * stack){
	stack->top++;
	stack->value[stack->top] = c;
}

char POP(_stack * stack){
	char c = stack->value[stack->top];
	stack->top--;
	return c;
}
