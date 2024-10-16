#include <stdio.h>
#include <stdlib.h>

typedef struct NodeTag{
    int data;
    struct NodeTag *next;
}Node;

typedef Node* List;

List inDex(int n ,List *list){
    Node *header; header = (List)malloc(sizeof(Node));
    Node *tail;   tail = (List)malloc(sizeof(Node));

    tail = header;

    while(n >= 0){

        Node *temp; 
        temp = (Node*)malloc(sizeof(Node));
        scanf("%d", &(temp->data));

            tail->next = temp;
            tail = temp;


        n--;
    }

    tail->next = NULL;
    return header;
}

void print(List l){
    List list = l;
    while(list != NULL){
        printf("%d ", list->next->data);
        list = list->next;
    }
}

void sort(int size, List *list){
    for(int i = 0; i < size; i++){
        for(int j = size; j > 0; j--){
            if(list->next )
        }
    }
}

int main(){
    List list;
    list = inDex(5, &list);


}