#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct NodeTag{
    DataType key;
    struct NodeTag *left;
    struct NodeTag *right;
}Node;

typedef Node* Tree;

void makeNull(Tree *pT){
    pT = NULL;
}

int get_height(Tree t){
    if(t == NULL){
        return -1;
    }
    int left = get_height(t->left) + 1;
    int right = get_height(t->right) + 1;
    return left>right?left:right;
}
