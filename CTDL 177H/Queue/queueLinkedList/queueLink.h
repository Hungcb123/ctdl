#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct NodeTag{
    ElementType data;
    struct NodeTag *next;
}Node;


typedef struct QueueNode{
    Node* rear;
    Node* front;
}Queue;


void makeNullQueue(Queue *queue){
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->next = NULL;
    queue->front = temp;
    queue->rear = queue->front;

}

int emptyQueue(Queue queue){
    return (queue.rear->next == NULL && queue.front->next == NULL);
}

void enQueue(ElementType res, Queue *queue){
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = res;
    temp->next = NULL;
    queue->rear->next = temp;
    queue->rear = queue->rear->next;
}

ElementType deQueue(Queue *queue){
    ElementType result = queue->front->next->data;
    Node *temp;
    temp = queue->front->next;
    queue->front = temp;
    free(temp);
    return result;
}
void print(Queue queue){
    Node *x;
    x = queue.front->next ;
    while(x != NULL){
        printf("%d ", x->data);
        x = x->next;
    }
    printf("\n");
}