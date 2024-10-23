#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 6

typedef struct{
    int element[MAXSIZE];
    int front, rear;
}Queue;

//Make a null queue
void makeNullQueue(Queue *queue){ 
    queue->front = 0;
    queue->rear = -1;
}

int emptyQueue(Queue queue){
    return (queue.rear == 0 && queue.front == 0);
}

int fullQueue(Queue queue){
    return (queue.rear == MAXSIZE - 1 && queue.front == 0);
}

int size(Queue queue){
    return (queue.rear - queue.front + 1);
}

void shiftLeft(int n, Queue *queue){
    int i;
    for(i = n; i < MAXSIZE; i++){
        queue->element[i-n] = queue->element[i];
    }
    queue->front = 0;
    queue->rear -= n;
}

void enQueue(int x, Queue *queue){
    if(queue->front > 0 && queue->rear == MAXSIZE-1){
        shiftLeft(queue->front, queue);
    }
    if(size(*queue) == MAXSIZE){
        printf("Queue da day");
    }
    queue->element[queue->rear + 1] = x;
    queue->rear += 1;
}

int deQueue(Queue *queue){
    Queue testEmpty = *queue;
    if(emptyQueue(testEmpty))
        exit(EXIT_FAILURE);
    int resutl = queue->element[queue->front];
    queue->front += 1;
    return resutl;
}

void printQueue(Queue queue){
    for(int i = queue.front; i <= queue.rear; i++){
        printf("%d %d %d", queue.element[i], queue.front, queue.rear);
    }
    printf("\n");
}



