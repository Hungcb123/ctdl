#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef int Position;

typedef struct NodeTag{
    int data;
    struct NodeTag *next;
}Node;

typedef Node* List;

List traverse(int a[], int lenA)
{
    List head = NULL;
    List temp;
    List tail;

    int i = 0;
    while(i < lenA)
    {
        temp = (Node*)malloc(sizeof(Node));

        temp->data = a[i];
        if(head == NULL)
            head = temp;
        else
            tail->next = temp;

        tail = temp;

        i++;
    }

    tail->next = NULL;
    return head;
}

List getPosition(int p, List L){
    List list = L;
    int i = 0; 
    while(i < p){
        list = list->next;

        i++;
    }
    return list;
}

int getLen(List L){
    List list = L;
    int len = 0;
    while(list != NULL){

        list = list->next;
        len++;
    }
    return len;
}
void bubleSort(List *L)
{
    List list = *L;
    int len = getLen(list);
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - i - 1; j++){
            if(getPosition(j, list)->data > getPosition(j + 1, list)->data){
                int temp = getPosition(j, list)->data;
                getPosition(j, list)->data = getPosition(j + 1, list)->data;
                getPosition(j + 1, list)->data = temp;
            }
        }
    }
}

int main(){
    int a[] = {5, 4, 3, 2, 9, 8,7,6,0, 1};
    int len = 10;
    List list = traverse(a,len);

    List l1 = list;
    while(l1 != NULL){
        printf("%d ", l1->data);
        l1 = l1->next;

    }
    bubleSort(&list);

    printf("\n");
    List l2 = list;
    while(l2 != NULL){
        printf("%d ", l2->data);
        l2 = l2->next;

    }
}