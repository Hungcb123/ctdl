#include <stdio.h>
#include <stdlib.h>

typedef struct NodeTag{
    ElementType *element;
    int capacity, top;
}Stack;

int isEmpty(Stack stack)
{
    return stack.top == -1;
}

void makeNull(Stack stack)
{
    
}

