#include "queueArray.h"

int main(){
    Queue queue = {{3,4,2,7},0,3};
    printQueue(queue);
    deQueue(&queue);
    printQueue(queue);
    enQueue(100, &queue);
    enQueue(100, &queue);
    enQueue(100, &queue);
    enQueue(100, &queue);
    enQueue(100, &queue);






    printQueue(queue);

}