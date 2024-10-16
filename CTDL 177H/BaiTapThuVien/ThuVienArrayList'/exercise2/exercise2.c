#include <stdio.h>
#include <stdlib.h>
#include "alistlib2.h"

int main(){
    //{Factor of each element},{Exponent of each element}
    //Example 2x^1 + 3x^0 = {{2, 3},{1, 0}} 
    Polynominal poly1;
    Polynominal poly2;

    inputPolynomial(&poly1);
    inputPolynomial(&poly2);


    //Add
    printf("Add two Polinominal : \n");
    print(poly1);
    print(poly2);
    Polynominal res = add(poly1, poly2);
    printf("Result : ");
    print(res);
    printf("\n");

    //Derivative
    printf("Derivative of Polinominal : \n");
    print(poly1);
    Polynominal deri = derivative(poly1);
    printf("Result : ");
    print(deri);
}

