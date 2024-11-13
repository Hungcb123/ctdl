#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000
typedef int Position;
typedef int Value;

typedef struct List{
    int element[MAXSIZE];
    int size;
}List;

void inputList(List *list){
    printf("Input your list size : ");
    int size1; scanf("%d", &size1);
    list->size = size1;
    int i = 0;
    while(size1 > 0)
    {
        int tempElement; scanf("%d", &tempElement);
        list->element[i] = tempElement;
        i++;
        size1--;
    }
}

void printList(List list){
    for (size_t i = 0; i < list.size; i++)
    {
        printf("%d ", list.element[i]);    
    }
    printf("\n");
}


int getAt(Position x, List list){
    return list.element[x];
}

void setAt(Value v, Position x, List *list){
    list->element[x] = v;
}

int popAt(Position x, List *list){  
    int valueReturn = list->element[x];
    for(int i = x; i < list->size; i++)
    {
        list->element[i] = list->element[i + 1];
    }
    return valueReturn;
}

int next(Position x ,List list){
    return x + 1;
}

void bubbleSort(List *list){
    for(int i = 0; i < list->size - 1; i++)
    {
        for(int j = 0; j < list->size - i - 1; j++)
        {
            if(getAt(j, *list) > getAt(next(j, *list), *list))
            {
                int temp = getAt(j, *list);
                setAt(getAt(next(j, *list), *list), j, list);
                setAt(temp, next(j, *list), list);
            }
        }
    }
}

void insertSort(List *list){
    for(int i = 1; i < list->size; i++)
    {
        int key = getAt(i, *list);
        int j = i - 1;
        while(j >= 0 && getAt(j, *list) > key)
        {
            setAt(getAt(j, *list), next(j, *list), list);
            j--; 
        }
        setAt(key, next(j, *list), list);
    }
}

void selectionSort(List *list){
    for(int i = 0; i < list->size; i++){
        int min = i;
        for(int j = i+1; j < list->size; j++){
            if(list->element[j] < list->element[min]){
                min = j;
            }
        }
        int temp = list->element[min];
        list->element[min] = list->element[i];
        list->element[i]   = temp;
    }
}

void shellSort(List *list){
    for(int gap = list->size/2; gap > 0; gap /= 2){
        
        for(int i = gap; i < list->size; i++){
            int temp = list->element[i];
            int j;
            for(j = i; j >= gap && list->element[j - gap] > temp; j -= gap){
                list->element[j] = list->element[j - gap]; 
            }
            list->element[j] = temp;
        }
    }
}

int main(){
    List list = {{5, 3, 4, 2 ,1},5};
    // inputList(&list);
    shellSort(&list);
    printList(list);
}
