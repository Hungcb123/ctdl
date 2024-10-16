#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    Stack stack;
    makeNull(&stack);
    int n; scanf("%d", &n);
    while(n!=0){
        int x; scanf("%d", &x);
        push(x, &stack);

        n--;
    }
    printf("%d ", pop(&stack));

    print(stack);
}