#include <stdio.h>
#include <stdlib.h>
typedef int DataType;

struct Node{
    DataType key;
    struct Node *left;
    struct Node *right;
};

typedef struct Node* Tree;

void makeNull(Tree *pT){    
    (*pT)  = NULL;
}

// Tree createTree(DataType v, Tree l, Tree r){
//     Tree N;
//     N = (struct Node*)malloc(sizeof(struct Node));
//     N->key  = v;
//     N->left  = l;
//     N->right = r;
//     return N;
// }

Tree leftChild(Tree tr){
    if(tr != NULL)
    {
        return tr->left;
    } 
    else
    {
        return NULL;
    }
}

Tree leftLeft(Tree tr){
    if(tr != NULL)
    {
        return tr->left;
    } 
    else
    {
        return NULL;
    }
}

void preOrder(Tree tr){
    if(tr != NULL){
        int test = tr->key;
        printf("%c ", tr->key);
        preOrder(tr->left);
        preOrder(tr->right);
    }
}

void inOrder(Tree tr){
    if(tr != NULL){
        inOrder(tr->left);
        printf("%d ", tr->key);
        inOrder(tr->right);
    }
}

int nb_nodes(Tree tr){
    if(tr != NULL){
        return nb_nodes(tr->left) + nb_nodes(tr->right) + 1;
    }
    else{
        return 0;
    }
}

int nb_leaf(Tree tr){
    if(tr == NULL){
        return 0;
    }

    if(tr->left == NULL && tr->right == NULL){
        return 1;
    }
    else{
        return (nb_leaf(tr->left) ) + (nb_leaf(tr->right) );
    }
}

Tree seachTreeNotBST(DataType x, Tree tr){ //O(n)
    if(tr == NULL){
        return NULL;
    }
    else if(tr->key == x){
        return tr;
    }
    else{
        seachTreeNotBST(x, tr->left);
        seachTreeNotBST(x, tr->right); 
    }
}

Tree seachTree(DataType x, Tree tr){
    if(tr == NULL){
        return NULL;
    }
    else if(tr->key == x){
        return tr;
    }
    else if(tr->key < x){
        seachTree(x, tr->right);
    }
    else{
        seachTree(x, tr->left);
    }
}

void insertNode(DataType x, Tree *tr){
    if((*tr) == NULL){
        *tr = (Tree)malloc(sizeof(struct Node));
        (*tr)->key =  x;
        (*tr)->left = NULL;
        (*tr)->right = NULL;
    }
    else if((*tr)->key < x){
        insertNode(x, &((*tr)->right));
    }
    else if((*tr)->key > x){
        insertNode(x, &((*tr)->left));
    }
}

Tree readTree(){
    Tree tr = NULL;
    int n; 
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int value; 
        scanf("%d", &value);
        insertNode(value, &tr);
    }
    return tr;
}

Tree deleteMin(Tree *tr){
    if((*tr)->left == NULL){
        return (*tr)->left;
    }
    else{
        deleteMin(&(*tr)->left);
    }
}

// DataType deleteMax(Tree *tr){
//     if((*tr)->left == NULL){
//         Tree temp = *tr;
//         DataType res = (*tr)->key;
//         (*tr) = (*tr)->left;
//         free(temp);
//         return res;
//     }
//     else{
//         deleteMax1((*tr)->right);
//     }
// }

void deteleNode(DataType x, Tree *tr){
    if((*tr) != NULL){
        if(x < (*tr)->key){
            //seach node left
            deteleNode(x, &(*tr)->left);
        }
        else if(x > (*tr)->key){
            //seach node right
            deteleNode(x, &(*tr)->right);
        }
        else{
            //equals 
            if((*tr)->left == NULL && (*tr)->right == NULL){
                Tree temp = *tr;
                tr = NULL;
                free(temp);
            }
            else if((*tr)->left == NULL){
                Tree temp = (*tr);
                (*tr) = (*tr)->right;
                free(temp);
            }
            else if((*tr)->right == NULL){
                Tree temp = (*tr);
                (*tr) = (*tr)->left;
                free(temp);
            }
            else{
                Tree temp = (*tr)->left;
                Tree freeTr1 = (*tr);
                Tree temp1 = deleteMin(&(*tr)->right);
                (*tr) = temp1;
                free(freeTr1);
                (*tr)->left = temp;
            }
        }
    }
}

int main(){
    Tree tr;
    makeNull(&tr);
    // tr = createTree('+', createTree('*', createTree('3', NULL, NULL), createTree('5', NULL, NULL)), createTree('7', NULL, NULL));   
    // preOrder(tr);
    // printf("\n"); 
    // inOrder(tr);
    // char x = '7';
    // printf("%c ", seachTree(x, tr)->key);
    // printf("\n %d \n", nb_leaf(tr));
    // insertNode('9', &tr);
    tr = readTree();
    inOrder(tr);
    printf("de :"); int de; scanf("%d", &de);
    deteleNode(de, &tr);
    inOrder(tr);

}