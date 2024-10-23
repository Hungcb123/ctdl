#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

#define MAXSIZE 7


typedef struct{
    ElementType element[MAXSIZE];
    int top;
}Stack;

void makeNull(Stack *pS)
{
    pS->top = -1;
}

int isEmpty(Stack *pS)
{
    return (pS->top == -1);
}

int size(Stack s){
    return s.top+1;
}
int isFull(Stack pS)
{
    return pS.top == MAXSIZE - 1;
}

void push(ElementType x, Stack *pS)
{
    if(isFull(*pS)){
        printf("Can't push anymore !!! Your stack is full!!\n");
    }
    pS->top = pS->top + 1;
    pS->element[pS->top] = x;
}

ElementType pop(Stack *pS)
{
    ElementType res = pS->element[pS->top];
    pS->top = pS->top - 1;
    return res;
}

void print(Stack pS)
{
    int size = pS.top;

    while(size>=0)
    {
        printf("%d ", pS.element[size]);
        size--;
    }
    printf("\n");
}

