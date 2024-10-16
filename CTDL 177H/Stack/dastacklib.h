#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct{
    ElementType *element;
    int capacity;
    int top;
}Stack;

void makeNull(Stack *stack) 
{
    stack->element = (ElementType*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = 1;
}

int isEmpty(Stack stack)
{
    return (stack.top == -1);
}

int isFull(Stack stack)
{
    return ((stack.top - 1) == stack.capacity);
}

void resize(Stack *stack, int newCapacity)
{
    ElementType *newElement = (ElementType*)malloc(newCapacity * sizeof(ElementType));  
    for (int i = 0; i <= stack->top; i++) {  
        newElement[i] = stack->element[i];  
    }  
    free(stack->element);  
    stack->element = newElement;
    stack->capacity = newCapacity;    
}

void push(ElementType x, Stack *stack)
{
    Stack sta = *stack;
    if(isFull(sta)==1)
    {
        resize(&sta, sta.capacity*2);
    }

    stack->top = stack->top + 1;
    stack->element[stack->top] = x;
}

ElementType pop(Stack *stack)
{
    ElementType x = stack->element[stack->top];
    
    stack->top = stack->top - 1;
    
    return x;
}

void print(Stack stack)
{
    int i = stack.top;
    while(i >= 0)
    {
        printf("%d ", stack.element[i]);
        i--;
    }
    printf("\n");
}