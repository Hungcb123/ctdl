#include <stdio.h>
#include <stdlib.h>
// #include "stackLink.h"

typedef int ElementType;


typedef struct NodeTag{
    ElementType element;
    struct NodeTag *next;
}Node;

#define Position Node*
#define Stack Node*
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
int pop(Stack *pS)
{
    ElementType res = (*pS)->next->element;
    Stack result = (*pS);
    Stack temp = result->next;


    result->next = temp->next;

    return res;
}
Stack traverse(int n)
{
    Stack head = NULL;
    Stack tail;
    Stack temp;
    int x = 0;
    while(x < n)
    {
        int res1; scanf("%d", &res1);
        temp = (Stack)malloc(sizeof(Node));
        temp->element = res1;
        if(head == NULL)
        {
            head = temp;
        }        
        else
        {
            tail->next = temp;
        }
        tail = temp;

        x++;
    }
    Stack res; res = (Stack)malloc(sizeof(Node));
    res->next = head;
    tail->next = NULL;
    return res;
}

int main(){
    int n; scanf("%d", &n);
    
    Stack x = traverse(n);  
    print(x);
    // push(100, &x);
    // print(x);

    int re = pop(&x);
    printf("Pop %d\n", re);
    print(x);
}