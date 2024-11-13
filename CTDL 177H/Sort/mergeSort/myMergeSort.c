#include <stdio.h>
#include <stdlib.h>

void merge(){

}

void mergeSort(){

}

//print each element of array and create the new line in the end of function
void printArray(int array[], int number){
    for(int i = 0; i < number; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int number;
    scanf("%d", &number);

    int array[number];
    for(int i = 0; i < number; i++){
        scanf("%d", &arr(i));
    }

    printArray(array[],number);
    mergeSort(array[], 0, number);
    printArray(array[]);

}