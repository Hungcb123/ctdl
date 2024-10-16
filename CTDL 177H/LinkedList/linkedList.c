#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;

    struct node *next;
        
}Node;

Node *creatNewNode(int arr[],int n){
    Node *head = NULL;
    Node *tail = NULL;
    int i = 0;
    while(n--)
    {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        i++;
    }
    return head;
}

int main()
{
    int arr[]= {34,4,5,6,7};
    Node *node1 = creatNewNode(arr ,5);
    Node *temp = node1;
    
    while(temp)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}