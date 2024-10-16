#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *coder(char code[], int n, int key[], int nKey){

    char *afterCoder = (char*)malloc(sizeof(char)* (n +1));
    int nKeyTest = 0;  
    for(int i = 0; i < n; i++)
    {
        if(nKeyTest == nKey-1)
        {
            nKeyTest = 0;
        }

        afterCoder[i] = code[i] + key[nKeyTest];
        nKeyTest++;
    }
    afterCoder[n] = '\0';
    return afterCoder;
}

char *deCoder(char code[], int n, int key[], int nKey){
    char *afterDecoder = (char*)malloc(sizeof(char) * (n+1));
    int nKeyTest = 0;
    for(int i = 0; i < n; i++)
    {
        if(nKeyTest == nKey-1)
        {
            nKeyTest = 0;
        }
        afterDecoder[i] = code[i] - key[nKeyTest];
        nKeyTest++;
    }
    afterDecoder[n] = '\0';
    return afterDecoder;
}

int main(){
    char code[] = {'D', 'a', 't', 'a', 'S', 't', 'r'};
    int key[] = {2,3,4,5,6};
    // printf("%s",coder(code, 7, key, 4));
    char *afterCoder1 = coder(code, 7, key, 5);
    for(int i = 0; i < 7; i++){
        printf("%c ", afterCoder1[i]);
    }
    char *afterCoder2 = deCoder(afterCoder1, 7, key, 5);
    printf("\n%s\n", afterCoder2);

}