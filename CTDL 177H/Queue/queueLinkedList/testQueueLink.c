#include "queueLink.h"


int main(){
    Queue x;
    makeNullQueue(&x);
    enQueue(100, &x);  
    enQueue(20, &x); 
    enQueue(10, &x);   
    print(x);
    int ress = deQueue(&x);
    printf("%d\n", ress);
    print(x);
    }