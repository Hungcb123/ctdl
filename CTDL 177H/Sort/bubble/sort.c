#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[4]={19,6,1,4};

    for(int i = 0; i < 4; i++)
    {
        for(int j = 3; j > i; j--)
        {
            if(arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
    for(int i = 0; i< 4; i++)
    {
        printf("%d ", arr[i] );
    }
}