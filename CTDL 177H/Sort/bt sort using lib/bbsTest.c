#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[7] = {5,3,4,1,2,8,9};

    for(int i = 0; i < 7; i++){
        int min = i;
        for(int j = i + 1; j < 7; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", 1/2);
    }
    
}