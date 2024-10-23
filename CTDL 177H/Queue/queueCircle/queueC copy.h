#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5


typedef int ElementType;

typedef struct Queue{
    ElementType element[MAXSIZE];
    int front, rear;
}Queue;

void makeNullQueue(Queue *queue){
    queue->front = 0;
    queue->rear = -1;
}

int sizeQueue(Queue queue){
    return ((queue.rear + MAXSIZE - queue.front + 2) % (MAXSIZE  + 1)) ;
}

int emptyQueue(Queue queue){
    return (queue.front == queue.rear + 1);
}

int fullQueue(Queue queue){
    return  (((queue.rear + 1) % MAXSIZE) == queue.front) && queue.rear != -1;
}

void enQueue(ElementType x, Queue *queue){
    if(fullQueue(*queue)){
        printf("Day queue, khong the them phan tu");
    }
    queue->rear = ((queue->rear + 1) % (MAXSIZE)); 
    queue->element[queue->rear] = x;
}

ElementType deQueue(Queue *queue){
    if(emptyQueue(*queue))
        exit(EXIT_FAILURE);
    
    ElementType result = queue->element[queue->front];
    if(queue->front < queue->rear){
        queue->front = (queue->front + 1) % MAXSIZE;
    }
    return result;
}

void printQueue(Queue queue){
    int i = queue.front;
    while(i != queue.rear){
        printf("%d ", queue.element[i]);
        i = (i+1) % (MAXSIZE);
        if(i == queue.rear){
            printf("%d ", queue.element[queue.rear]);
        }
    }
}