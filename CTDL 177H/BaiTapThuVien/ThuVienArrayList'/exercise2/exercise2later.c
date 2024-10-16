#include <stdio.h>
#include <stdlib.h>
#include "alistlib2.h"

Polynominal read(){
    printf("Input your number of x in polinominal1 : \n");
    int n; scanf("%d", &n);
    Polynominal res;
    for(int i = 0; i < n ; i++)
    {
        scanf()
    }
    
}

int main(){
    //{Factor of each element},{Exponent of each element}
    //Example 2x^1 + 3x^0 = {{2, 3},{1, 0}} 
    Polynominal poly1 = {{{3,1},{0,1}},2};
    Polynominal poly2 = {{{2,3},{1,0}},2};

    //Add
    printf("Add two Polinominal : \n");
    print(poly1);
    print(poly2);
    Polynominal res = add(poly1, poly2);
    printf("Result : ");
    print(res);
    printf("\n");

    //Derivative
    Polynominal poly3 = {{{3,4,5,2},{3,2,1,0}},4};
    printf("Derivative of Polinominal : \n");
    print(poly3);
    Polynominal deri = derivative(poly3);
    printf("Result : ");
    print(deri);
}

