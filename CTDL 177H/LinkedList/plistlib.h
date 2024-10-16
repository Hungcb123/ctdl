#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef int Position;

typedef struct NodeTag {
    ElementType data;
    struct NodeTag* next;
} Node;

typedef Node* PNode;
typedef Node* List;

// Make the List null
void makeNull(List *L) { (*L)->next = NULL; }

// Return length of List
int len(List L)
{
    int size = 1;
    List res = L;

    while (res->next != NULL) {
        size++;

        res = res->next;
    }
    return size;
}

// Check whether the list is empty
int empty(List L) { return (L->next == NULL); }

// Check whether the list is full
int fullList(List L) { return 0; }

// Print each element of list
void print(List L)
{
    if(empty(L))
    {
        printf("Error...!!!List is empty, imposible to print");
        exit(EXIT_FAILURE);
    }

    List list = L;
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }

    printf("\n");
}

// Get position in ith
PNode getPosition(ElementType i, List L)
{
    List list = L;
    while (i > 1) {
        i--;
        list = list->next;
    }
    return list;
}

// Return the element at position p
ElementType getAt(Position p, List L)
{
    List temp = getPosition(p, L);
    if (temp != NULL)
        return temp->data;
    printf("Error getAt: Position do not exis !!\n");
    exit(EXIT_FAILURE);
}


// Return first position of list
PNode first(List L) { return L; }

//Return last postion of list
PNode end(List L)
{
    List list = L;
    while (list->next != NULL) {
        list = list->next;
    }
    return list;
}

//Set data at position p
void setAt(Position p, ElementType x, List *L)
{
    PNode list = *L;
    List temp = getPosition(p, list);
    temp->data = x;
}

//Insert x at position p
void insertAt(Position p, ElementType x, List *L)
{
    List list = *L;

    List newNode;
    newNode = (Node*)malloc(sizeof(Node));

    List temp = getPosition(p, list);

    List connect = getPosition(p-1, list);

    connect->next = newNode;

    newNode->data = x;
    newNode->next = temp;

    free(temp);
}

//Remove and return the element at position p
ElementType popAt(Position p, List *L)
{
    PNode list = *L;
    PNode temp = getPosition(p, list);

    ElementType res = temp->data;

    PNode pop = temp->next;
    PNode get = getPosition(p-1, list);
    get->next = pop;

    return res;
}

//Insert x to the first position
void insertFirst(ElementType x, List *L)
{
    List res;
    res = (Node*)malloc(sizeof(Node));

    res->data = x;
    res->next = *L;

    *L = res;
}

//Remove and return the first element
ElementType popFirst(List *L)
{
    List temp = *L;
    ElementType res = temp->data;
    *L = temp->next;
    free(temp);

    return res;
}

//Append a new element to the list
void append(ElementType x, List *L)
{
    List list = (*L);

    //Create newNode 
    List newNode;
    newNode= (Node*)malloc(sizeof(Node));
    
    List temp = end(list);
    temp->next = newNode;

    newNode->data = x;
    newNode->next = NULL;
}

PNode previous(Position p, List L);
//Remove and return the last element
ElementType popLast(List *L)
{
    List list = *L;

    ElementType res = end(list)->data;

    PNode last = getPosition(len(list)-1, list);
    last->next = NULL; 
    
    return res;
}

//Return the position of the first appearance of x in the list
Position locate(ElementType x, List L)
{
    Position res = 1;
    List list = L;
    while(list->data != x)
    {
        list = list->next;
        res++;
    }
    return res;
}

//Return the pointer referring to the next position of i in L
PNode next(Position p, List L)
{
    PNode nex = getPosition(p, L);

    if(nex->next == NULL)
    {
        printf("Error...!!!Next position is NULL");
        exit(EXIT_FAILURE);
    }

    return nex->next;
}

//Return the pointer referring to the previous position of p in L
PNode previous(Position p, List L)
{    
    List list = L;

    PNode pre = getPosition(p-1, list);
    return pre;
}

//hàm xóa toàn bộ list