#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000
typedef Node* Position;
typedef int ElementType;


typedef struct NodeTag{
    ElementType data;   
    struct NodeTag *next;
}Node;

typedef Node* List;

//Initialize an empty list
void makeNull(List *L)
{
    Node *header = (Node*)malloc(sizeof(Node));
    header->next = NULL;
    (*L) = header;
}


//Number of element
int len(List L)
{
    Node *Res = L; 
    int res = 1;
    while(Res->next != NULL)
    {
        Res = Res->next;
        res++;
    }
    return res;
}


//Check whether the list is empty
int empty(List L)
{
    return L->next==NULL;
}


//Check whether the list is full
int fullList(List L)
{
    Node *Res = L;
    return len(Res) >= MAXSIZE;
}


//Print all element of list
void print(List L)
{
    Node *Res = L;

    while(Res->next != NULL)
    {
        printf("%d ",Res->next->data);
        Res = Res->next;
    }

    printf("\n");
}
   

//
ElementType getAt(Position p, List L)
{
    if(p->next != NULL)
        return p->next->data;
    printf("Error !");
    exit(EXIT_FAILURE);
}


//
void setAt(Position p, ElementType x, List *L)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode = p->next;
    newNode->data = x;
    newNode->next = p->next->next;
}



void insertAt(Position p, ElementType x, List *L)
{

}









