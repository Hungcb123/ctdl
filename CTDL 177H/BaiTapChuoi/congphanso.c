#include <stdio.h>

typedef struct{
    int numerator; int denominator;
}Fraction;

Fraction read(){
    Fraction input;  
    do {  
        printf("Nhap tu so va mau so");  
        scanf("%d %d", &(input.numerator), &(input.denominator));  
        if (input.denominator == 0) {  
            printf("Mau so khong the bang 0\n");  
        }  
    } while (input.denominator == 0);  
    return input;
}

void print(Fraction f1){
    printf("%d/%d\n",f1.numerator,f1.denominator);
}
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
void rutgon(Fraction *f1){
    int uocChung = gcd(f1->numerator,f1->denominator);
    f1->numerator /= uocChung;
    f1->denominator /= uocChung;
}

Fraction add(Fraction f1, Fraction f2){
    Fraction fin;
    if(f1.denominator == f2.denominator){
        fin.numerator = f1.numerator+f2.numerator;
        fin.denominator = f1.denominator;
    }
    else{
        fin.denominator = f1.denominator*f2.denominator;
        fin.numerator = (f1.numerator*f2.denominator) + (f2.numerator*f1.denominator);
    }
    return fin;
}

Fraction sub(Fraction f1,Fraction f2){
        Fraction fin;
    if(f1.denominator == f2.denominator){
        fin.numerator = f1.numerator-f2.numerator;
        fin.denominator = f1.denominator;
    }
    else{
        fin.denominator = f1.denominator*f2.denominator;
        fin.numerator = (f1.numerator*f2.denominator) - (f2.numerator*f1.denominator);
    }
    return fin;
}
Fraction mul(Fraction f1, Fraction f2){
    Fraction fin;
    fin.numerator = f1.numerator*f2.numerator;
    fin.denominator = f1.denominator*f2.denominator;
    return fin;
}
Fraction div(Fraction f1,Fraction f2){
    Fraction fin;
    fin.numerator = f1.numerator * f2.denominator;
    fin.denominator = f1.denominator * f2.numerator;
    return fin;
}

int main(){

    Fraction f1, f2;
    f1 = read();
    f2 = read();
    print(f1);
    print(f2);

    Fraction cong = add(f1, f2);
    rutgon(&cong);
    printf("Cong: ");
    print(cong);

    Fraction tru = sub(f1, f2);
    rutgon(&tru);
    printf("Tru: ");
    print(tru);

    Fraction nhan = mul(f1,f2);
    rutgon(&nhan);
    printf("Nhan: ");
    print(nhan);

    Fraction chia = div(f1,f2);
    rutgon(&chia);
    printf("Chia: ");
    print(chia);

    return 0;


}