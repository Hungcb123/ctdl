#include "alistlib.h"

int binarySearch(ElementType x, List l){
    int f = 1, e = len(l), i; 
    while(f <= e){
        i = (f + (e))/2;
        if(getAt(i, l) == x){
            return i;
        }
        if(x < getAt(i, l)){
            e = i - 1;
        }
        else{
            f = i + 1;
        }
    }
    return -1;
}

int main(){
    // int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    List l = {{1, 2, 3, 4, 5, 6, 7}, 7};
    printf("%d ", binarySearch(7, l));
    // printf("%d ", binarySearch(2, l));
}