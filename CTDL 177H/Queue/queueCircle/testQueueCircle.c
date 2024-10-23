#include "queueC copy.h"



int main(){
    Queue queue;
    makeNullQueue(&queue);
    enQueue(1, &queue);
    enQueue(2, &queue);
    enQueue(3, &queue);
    enQueue(4, &queue);
    enQueue(5, &queue);
    // enQueue(6, &queue);
    // enQueue(7, &queue);
    // enQueue(8, &queue);
    // enQueue(19, &queue);
    // enQueue(10, &queue);
    deQueue(&queue);
    enQueue(100, &queue);
    printQueue(queue);



}