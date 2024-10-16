#include <stdio.h>
#include "alistlib.h"

int main(){
    List L = {{1, 2, 5, 7, 8}, 5};
    printf("Print ");
    print(L);

    // makeNull(&L);  

    printf("Len : %d\n",len(L));
    printf("\n");

    printf("Empty : %d\n",empty(L));
    printf("\n");
    
    printf("Full List : %d\n",fullList(L));
    printf("\n");
    
    printf("Get at 3 : %d\n",getAt(3, L)); 
    printf("\n");
     
    printf("First : %d\n",first(L));  
    printf("\n");
    
    printf("EndList : %d\n",endList(L));  
    printf("\n");
    
    List Set = {{1, 2, 5, 7, 8}, 5};
    print(Set); 
    setAt(3, 10, &Set); 
    printf("Set at 3 = 10 : ");
    print(Set);
    printf("\n");
    
    List Insert = {{1, 2, 5, 7, 8}, 5};
    print(Insert);  
    insertAt(2, 10, &Insert); 
    printf("Inset at 2 = 10 : ");
    print(Insert);
    printf("\n");
    
    List Pop = {{1, 2, 5, 7, 8}, 5};
    print(Pop);
    printf("Pop 3 : %d\n",popAt(3, &Pop));
    print(Pop);
    printf("\n");
    
    List Insertdautien = {{1, 2, 5, 7, 8}, 5};
    print(Insertdautien);
    printf("InsertFirst = 10 : ");
    insertFirst(10, &Insertdautien);  
    print(Insertdautien);
    printf("\n");
    
    List Popdau = {{1, 2, 5, 7, 8}, 5};
    print(Popdau);
    printf("PopFirst : %d\n",popFirst(&Popdau));
    print(Popdau);
    printf("\n");
    
    List Append1 = {{1, 2, 5, 7, 8}, 5};
    print(Append1);
    printf("Append : ");
    append(10, &Append1);  
    print(Append1);
    printf("\n");
    
    List PopLast1 = {{1, 2, 5, 7, 8}, 5};
    print(PopLast1);
    printf("PopLast : %d\n",popLast(&PopLast1));  
    print(PopLast1);
    printf("\n");
    
    List Locate1 = {{1, 2, 5, 7, 8}, 5};
    print(Locate1);
    printf("Locate 8 : %d\n",locate(8, Locate1));  
    printf("\n");
    
    
    printf("Next cua 1 : %d\n",next(1, L));  
    printf("\n");
    
    
    printf("Previous cua 2 : %d\n",previous(2, L));  
    printf("\n");
    
    
}
