#include <stdio.h>
#include <stdlib.h>
#include "alistlib.h"

int main()
{
    
    //Input
    List L = {{7, 4, 2, 6, 8, 1, 0, 3, 9, 5, 12, 16, 18, 19, 11}, 15};
    
    //Test function print    
    print(L);

    //Sort integer list ascending
    for(int i = 1; i < len(L); i++)
    {
        int j = i;
        
        while(j >= 1 && getAt(j, L) > getAt(j + 1, L)){
            ElementType temp = getAt(j, L);
            setAt(j, getAt(j + 1, L), &L);
            setAt(j + 1, temp, &L);            
            j = j-1;
            if(j == 0 || j == len(L))
                break;
        }
    }

    print(L);

}