#include <stdio.h>
#include <stdlib.h>
#include "alistlib.h"



void swap(Position p, Position q, List *list){
    ElementType temp = getAt(p, *list);
    setAt(p, getAt(q, *list), list);
    setAt(q, temp, list);
}

void bubbleSort(List *list){
    for(Position i = first(*list); i < len(*list)-1 ; i = next(i, *list)){
        for(Position j = endList(*list) - 1; j != i  ; j = previous(j, *list)){

            if(getAt(j, *list) < getAt(previous(j, *list), *list)){
            
                swap(j, previous(j, *list), list);
            
            }
        }
    }
}
// void swap(Position p, Position q, List *l)
// {
// 	ElementType temp = getAt(p, *l);
// 	setAt(p, getAt(q, *l), l);
// 	setAt(q, temp, l);
// }
// void bubbleSort(List *l)
// {
// 	for (Position i = first(*l); i != endList(*l) - 1; i = next(i, *l))
// 	{
// 		for (Position j = endList(*l) - 1; j != i; j = previous(j, *l))
// 		{
// 			if (getAt(j, *l) < getAt(previous(j, *l), *l))
// 			{
// 				swap(j, previous(j, *l), l);
// 			}
// 		}
// 	}
// }
int main(){
    List list = {{9, 6,12,233, 1},6};

    print(list);
    bubbleSort(&list);
    print(list);
}