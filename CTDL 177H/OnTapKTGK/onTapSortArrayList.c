#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[4] = {5,2,8,1};

    for(int i = 0; i < 4; i++){
        for(int j = 3; j > i; j--){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i = 0; i< 4; i++){  
        printf("%d ", arr[i]);
    }
}
