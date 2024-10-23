#include "Circularqueuelib.h"

void inputQueue(int n,Queue *q){
    while(n > 0){
        int x; scanf("%d", &x);
        enQueue(x, q);
        n--;
    }
}

int main(){
    
}