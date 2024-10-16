#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000
typedef int Position;
typedef int ElementType;


typedef struct FacEx{
    ElementType factor[MAXSIZE];
    ElementType exponent[MAXSIZE];
}FacEx;

typedef struct Polynominal{
    FacEx polynominal;
    int size;
}Polynominal;



void sortExponent(Polynominal *polynominalR)
{
    for(int i = 0; i < polynominalR->size-1; i++)
    {
        int j = i;
        
        while(j >= 0 && polynominalR->polynominal.exponent[j] < polynominalR->polynominal.exponent[j + 1])
        {
            int factor = polynominalR->polynominal.factor[j];
            int exponent = polynominalR->polynominal.exponent[j];
            

            polynominalR->polynominal.factor[j] = polynominalR->polynominal.factor[j + 1];
            polynominalR->polynominal.exponent[j] = polynominalR->polynominal.exponent[j + 1];


            polynominalR->polynominal.factor[j + 1] = factor;
            polynominalR->polynominal.exponent[j + 1] = exponent;

            j--;
        }
    }
}

Polynominal add(Polynominal polynominal1, Polynominal polynominal2)
{

    sortExponent(&polynominal1); 
    sortExponent(&polynominal2);

    Polynominal polyRes;
    polyRes.size = polynominal1.size;
    int expo = polynominal1.size;
    int i = 0;

    while(i < polynominal1.size)
    {
        polyRes.polynominal.factor[i]   = polynominal1.polynominal.factor[i] + polynominal2.polynominal.factor[i];
        polyRes.polynominal.exponent[i] = expo - 1;
        expo--;
        i++;
    }
    return polyRes;
}

void print(Polynominal result)
{
    sortExponent(&result);
    for(int i = 0; i < result.size; i++)
    {
        printf(" %dx^%d ", result.polynominal.factor[i], result.polynominal.exponent[i]);
        if(i != result.size - 1)
        {
            printf("+");
        }
    }
    printf("\n");
}

Polynominal derivative(Polynominal idx)
{
    sortExponent(&idx);
    Polynominal res;
    res.size = idx.size;

    for(int i = 0; i < idx.size; i++)
    {

        if(idx.polynominal.exponent[i] > 1)
        {
            res.polynominal.factor[i]   = idx.polynominal.factor[i] * idx.polynominal.exponent[i];
            res.polynominal.exponent[i] = idx.polynominal.exponent[i] - 1;
        }
        else if(idx.polynominal.exponent[i] == 1)
        {
            res.polynominal.factor[i] = idx.polynominal.factor[i];
            res.polynominal.exponent[i] = idx.polynominal.exponent[i] - 1;
        }
        else
        {
            res.size -= 1;
        }
        
    }

    return res;
}

void inputPolynomial(Polynominal *polynominal) {  
    printf("Enter the number of terms in the polynomial: ");  
    scanf("%d", &polynominal->size);  

    for (int i = 0; i < polynominal->size; i++) {  
        printf("Enter factor and exponent for term %d(format: factor exponent): ", i + 1);  
        scanf("%d %d", &polynominal->polynominal.factor[i], &polynominal->polynominal.exponent[i]);  
    }  
}



