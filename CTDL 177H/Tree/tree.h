#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct NodeTag{
    DataType data;
    struct NodeTag *left;
    struct NodeTag *right;
}Node;

typedef Node* Tree;

void makeNull(Tree *pT){
    pT = NULL;
}

Tree create(DataType v, Tree l, Tree r){
    Tree N;
    N = (Tree)malloc(sizeof(Node));

    N->data = v;
    N->left = l;
    N->right = r;
    
    return N;
}