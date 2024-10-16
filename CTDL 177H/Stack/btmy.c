#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node{
    ElementType data;
    struct Node *next;
}Node;

typedef Node* Stack;

void makeNull(Stack *stack)
{
    Stack stack2 = (Stack)malloc(sizeof( Node));
    stack2->next = NULL;
    (*stack) = stack2;
}

int empty(Stack stack)
{
    return (stack->next == NULL);
}

ElementType pop(Stack *stack)
{
    ElementType res = (*stack)->next->data;
    Stack temp; temp = (*stack)->next;
    (*stack)->next = temp->next;
    free(temp);
    return res;
}

void push(ElementType x, Stack *stack)
{
    Stack temp = (Stack)malloc(sizeof(Node));
    temp->data = x;
    
    temp->next =(*stack)->next;
    (*stack)->next = temp;
}

int calC(int k, int n)
{
     int result = 0;

    Stack K;
    makeNull(&K);
    Stack N;
    makeNull(&N);

    push(k, &K);
    push(n, &N);

    while(!(empty(K) && empty(N))){
        int kdata = pop(&K);
        int ndata = pop(&N);

        if(kdata == 0 || kdata == ndata)
        {
            result += 1;
        }
        else if(kdata == 1)
        {
            result += ndata;
        }
        else
        {
            push(kdata-1, &K);
            push(kdata, &K);
            push(ndata-1, &N);
            push(ndata-1, &N);
        }

    }

    return result;
}



void to_binary(int n)
{
    printf("%d -> ", n);
    Stack s;
    makeNull(&s);
    if (n == 0)
    {
        push(0, &s); 
    }
    else
    {
        while (n != 0)
        {
            push(n % 2, &s); 
            n /= 2;          
        }
    }

    
    while (!empty(s))
    {
        printf("%d", pop(&s));
    }
    printf("\n");
}

int calFibo(int n)
{
    Stack s;
    makeNull(&s);
    push(n, &s);
    int rs = 0;
    while (!empty(s))
    {
        int temp = pop(&s);
        if (temp > 2)
        {
            push(temp - 2, &s);
            push(temp - 1, &s);
        }
        else
            rs += 1;
    }
    return rs;
}
int main(){
    int number = 10;
    to_binary(number);

    printf("so  fibo thu %d la: %d\n", number, calFibo(number));
    printf("C(3, 4): %d", calC(3,4));
}