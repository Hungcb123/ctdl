#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;


typedef struct NodeTag{
    ElementType element;
    struct NodeTag *next;
}Node;

#define Position Node*
#define Stack Node*

void makeNull(Stack *pS)
{
    Stack stack;
    stack = (Stack)malloc(sizeof(Node));
    stack->next = NULL;
    *pS = stack;
}

int isEmpty(Stack pS)
{ 
    return (pS->next == NULL);
}

int isFull(Stack pS)
{
    return 0;
}

Stack push(ElementType x, Stack *pS)
{
    Stack stack = *pS;
    Stack newStack;
    newStack = (Stack)malloc(sizeof(Node));

    newStack->element = x;
    newStack->next = stack->next;

    stack->next = newStack;
    return newStack;
}

int pop(Stack *pS)
{
    ElementType res = (*pS)->next->element;
    Stack result = (*pS);
    Stack temp = result->next;


    result->next = temp->next;

    return res;
}

void print(Stack stack)
{ 
    Stack temp = stack;
    while(temp->next != NULL)
    {
        printf("%d \n", temp->next->element);
        temp = temp->next;
    }
    printf("\n");
}
