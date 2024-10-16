#include <stdio.h>
#include <stdlib.h>

typedef struct NodeTag{
    char c;
    struct NodeTag* next;
}Node;

typedef Node* List;

List coder(int key[], int lenKey, List *L, int lenList){
    List res = *L;
    List list = *L;
    int i = 0, keyi = 0;
    while(i < lenList){

        if(keyi == lenKey - 1){
            keyi = 0;
        }

        char x = list->c; 
        list->c = x + key[keyi];

        list = list->next;

        keyi++;
        i++;
    }
    return res;
}


int main(){
    List L = NULL;
    List tail = NULL;
        List newNode;
    int i = 4;
    while(i >= 0){
            newNode = (Node*)malloc(sizeof(Node));
            char c1;
            scanf("%c", &c1);
            newNode->c = c1;
        if(L == NULL){
            L = newNode;
        }
        else{
            tail->next = newNode;
        }

        tail = newNode;
        i--;
    }
        tail->next = NULL;


    printf("\n");
    List l1 = L;
    while(l1 != NULL){
        printf("%c", l1->c);
        l1 = l1->next;
    }
    printf("\n");

    int key[] = {2, 3, 4, 5};

    List l2 =  coder(key, 4, &L, 4);
    while(l2 != NULL){
        printf("%c \n", l2->c);
        l2 = l2->next;
    }
    printf("\n");
}