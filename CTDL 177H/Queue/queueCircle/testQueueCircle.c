#include "queueC.h"



int main(){
    Queue queue;
    makeNull(&queue);
    enQueue(1, &queue);
    enQueue(2, &queue);
    enQueue(3, &queue);
    enQueue(4, &queue);
    enQueue(5, &queue);
    enQueue(6, &queue);
    enQueue(7, &queue);
    enQueue(8, &queue);
    enQueue(19, &queue);
    enQueue(10, &queue);
    printQueue(queue);


    int r = deQueue(&queue);

        int re = deQueue(&queue);
    printf("%d \n", queue.front);
        int res = deQueue(&queue);

    enQueue(999, &queue);
    printf("c %d ", queue.rear);
    enQueue(999, &queue);
    printf("c %d ", queue.rear);
    enQueue(999, &queue);
    printf("c %d ", queue.rear);
    printQueue(queue);
    enQueue(100, &queue);
}