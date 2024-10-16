#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000
typedef int Position;
typedef int ElementType;

typedef struct{
    ElementType element[MAXSIZE];
    int size;
}List;

void makeNull(List *list){
    
    list->size = 0;
}