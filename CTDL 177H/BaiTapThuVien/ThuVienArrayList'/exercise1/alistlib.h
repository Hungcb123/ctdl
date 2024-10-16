#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
typedef int ElementType;
typedef int Position;

typedef struct List{
    ElementType element[MAXSIZE];
    int size;
}List;


void makeNull(List *L)
{
    L->element[0] = '\0';
    L->size = 0;
}

int len(List L)
{
    return L.size;
}

int empty(List L)
{
    return (L.size == 0);
}

int fullList(List L)
{
    return (L.size == MAXSIZE);
}

void print(List L)
{
    for(int i = 0; i < L.size; i++)
    {
        printf("%d ",L.element[i]);
    }
    printf("\n");
}

ElementType getAt(Position p, List L)
{
	if (p >= 1 && p <= L.size)
		return L.element[p-1];
	printf("Error Position !!");
	exit(EXIT_FAILURE);
}

Position first(List L)
{   

        return 1;

}

Position endList(List L)
{
    if(empty(L)){
        return 1;
    }
    else{
        return L.size + 1;
    }
}

void setAt(Position p, ElementType x, List *L)
{
    L->element[p-1] = x;
}

void insertAt(Position p, ElementType x, List *L)
{

    for(int i = (L->size); i >= p; i--)
    {
        L->element[i] = L->element[i-1];
    }

    L->element[p-1] = x;
    L->size++;

}

ElementType popAt(Position p, List *L)
{
    if(p > 0 && p <= L->size)
    {
        ElementType res = L->element[p-1];

        for(int i = p-1; i <= endList(*L); i++)
        {
            L->element[i] = L->element[i + 1];
        }
        L->size--;

        return res;
    }
    else{
        printf("Position Error! Exit....\n");
        exit(EXIT_FAILURE);
    }
}

void insertFirst(ElementType x, List *L)
{
    for(int i = (L->size)-1; i >= 0; i--)
    {
        L->element[i+1] = L->element[i];
    }
    L->element[0] = x;
    L->size++;
} 

ElementType popFirst(List *L)
{
    return popAt(first(*L), L);
}

void append(ElementType x, List *L)
{
    L->element[L->size] = x;
    L->size++;
}

ElementType popLast(List *L)
{
    return popAt(endList(*L)-1, L);
}

Position locate(ElementType x, List L)
{
    Position res;
    for(int i = 0; i < L.size; i++)
    {
        if(x == L.element[i])
        {
            res = i + 1;
            return res;
        }
    }

    return 0;
}


Position next(Position p, List L)
{
    if(p > 0 && p <= L.size)
    {
        return p + 1;
    }
    else
    {
        printf("Position Error! Exit....\n");
        exit(EXIT_FAILURE);
    }
}


Position previous(Position p, List L)
{
    if(p > 1 && p <= L.size)
    {
        return p - 1;
    }
    else
    {
        printf("Position Error! Exit....\n");
        exit(EXIT_FAILURE);
    }
}