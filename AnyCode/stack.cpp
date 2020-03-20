#include <stdio.h>
#include <windows.h>

typedef struct stack {
    
    int array[100];
    int top;
    
} stack_t;

bool stack_empty(stack_t S)
{
    if(S.top == 0) {
        return true;
    }
    return false;
}


void push(stack_t* S, int x)
{
    S->top += 1;
    S->array[S->top] = x;
}


int pop(stack_t* S)
{
    if(stack_empty(*S)) {
        printf("\nunderflow stack\n");
        exit(-1);
    } else {
        S->top -= 1;
        return S->array[S->top+1];
    }
}