#include <stdio.h>
#include <stdlib.h>
#include "plistlib.h"


// List inputList(int n)
// {
//     List head = NULL;
//     List temp = NULL;
//     List np = NULL;

//     while(n > 0)
//     {
//         temp = (Node*)malloc(sizeof(Node));
//         scanf("%d", &(temp->data)); 

//         if(head == NULL)
//         {
//             head = temp;
//         }
//         else
//         {
//             np->next = temp;
//         }
        
//         np = temp;
//         n--;
//     }
//     return head;

// }  


int main(){
    
    List L = (List)malloc(sizeof(Node)); // Khởi tạo nút đầu tiên
    L->data = 2;

    L->next = (List)malloc(sizeof(Node)); // Khởi tạo nút thứ hai
    L->next->data = 3;

    L->next->next = (List)malloc(sizeof(Node)); // Khởi tạo nút thứ ba
    L->next->next->data = 4;

    L->next->next->next = NULL;

    printf("\n-----My test function-----\n");


    // List testMakeNULL = L;
    // makeNull(&testMakeNULL);  
    // int checkEmptyMakeNUL = empty(testMakeNULL);
    // printf("\nTest makeNull && empty : %d\n", checkEmptyMakeNUL);


    printf("\nTest fullList : %d\n", fullList(L));


    printf("\nTest print : ");
    print(L);


    printf("\nTest getAt(2, L)\n");
    print(L);
    int get = getAt(2, L);
    printf("%d\n len: %d",get,len(L));//


    // printf("\nTest getPosition by getAt(3/p, L)\n");
    // print(L);



    printf("\nTest first by getAt\n");
    print(L);
    PNode st= first(L);
    printf("Result: %d\n", st->data);

    printf("\nTest end by getAt\n");
    print(L);
    PNode last = end(L);
    printf("Result: %d\n",last->data);

    printf("\nTest setAt(2, 100, L)\n");
    print(L);

    setAt(2, 100, &L);
    print(L);

    printf("\nTest insertAt(2, 123, L)\n");
    print(L);

    insertAt(2, 123, &L);
    print(L);

    printf("\nTest popAt(3, L)\n");
    print(L);
    int x = popAt(3, &L);
    printf("%d \n", x);
    print(L);

    printf("\nTest insertFirst\n");
    print(L);
    insertFirst(1456, &L);
    print(L);

    printf("\nTest popFirst\n");
    print(L);
    int popf = popFirst(&L);
    printf("%d \n", popf);
    print(L);

    printf("\nTest append\n");
    print(L);
    append(222, &L);
    print(L);

    printf("\nTest popLast\n");
    print(L);
    int popL = popLast(&L);
    printf("%d\n", popL);
    print(L);

    printf("\nTest locate 2\n");
    print(L);
    int loca = next(1, L)->data;
    printf("%d \n", loca);


    printf("\nTest next 2\n");
    print(L);
    // PNode nex = next(2, L);
    // printf("%d -> %d", L->data , next(L)->data);


    printf("\nTest\n");
    print(L);


}