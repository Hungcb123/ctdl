#include <stdio.h>
#include <stdlib.h>
#include "dastacklib.h"

void toBinary(int n)
{
    Stack stack;
    makeNull(&stack);
    if(n == 0){
        push(0, &stack);
    }
    while (n != 0) {  
        int x = n % 2;  
        push(x, &stack);  
        n = n / 2;  
    } 
    
    print(stack);
}

int Fibo(int n)
{
    Stack stack;
    makeNull(&stack);

    int rs = 1;
    int result = 0;

    if(n == 0){
        return 0;
    }


    while(n >= 1){
        if(rs == 1 || rs == 2){
            push(1, &stack);
            result = 1;
        }
        else{
            int p1, p2;
            p1 = pop(&stack); p2 = pop(&stack);
            int x = p1 + p2;
            push(p1, &stack);
            push(x, &stack);
            result = x;
        }

        n--;
        rs++;
    }
    return result;
}

int C(int k, int n)
{
    Stack ks;
    makeNull(&ks);
    Stack ns;
    makeNull(&ns);
    int rs = 0;
    push(k, &ks);
    push(n, &ns);
    while (!(isEmpty(ks) && isEmpty(ns)))
    {

        int tempK = pop(&ks);
        int tempN = pop(&ns);
        if (tempK == 0 || tempK == tempN)
            rs += 1;
        else if (tempK == 1)
            rs += tempN;
        else
        {
            push(tempK - 1, &ks);
            push(tempK, &ks);
            push(tempN - 1, &ns);
            push(tempN - 1, &ns);
        }
    }
    return rs;
}


int main()
{
    int n = 10;

    printf("so  fibo thu %d la: %d\n", n, Fibo(n));

    printf("top hop chap %d cua %d la: %d.\n", 3, 5, C(3, 5));

    return 0;
}