#include "dastacklib.h"
#include "Circularqueuelib.h"

void inputStack(int n, Stack *s){
    while(n > 0){
        int xs; scanf("%d", &xs);
        push(xs, s);
        n--;
    }
}

void reverseStack(Stack *s){
    Queue q;
    makeNullQueue(&q);
    int n = s->top;
    while(n >= 0){
        int temp; 
        temp = pop(s);
        enQueue(temp, &q);
        n--;
    }
    int n1 = q.rear;

    while(n1 >= 0){
        int tempQ = deQueue(&q); 
        push(tempQ, s);
        n1--;
    }
}

void inputQueue(int n, Queue *q){
    while(n > 0){
        int temp;scanf("%d", &temp);
        enQueue(temp, q);
        n--;
    }
}

void reverseQueue(Queue *q){
    int n = sizeQueue(*q); int n2 = sizeQueue(*q);
    Stack s; makeNull(&s);
    while(n > 0){
        int temp = deQueue(q);
        push(temp, &s);
        n--;
    }
    makeNullQueue(q);
    while(n2 > 0){
        int temp2 = pop(&s);
        enQueue(temp2, q);
        n2--;
    }
}

int main(){
    printf("Nhap so phan tu cua Stack\n");
    int n; scanf("%d", &n);
    Stack s;
    makeNull(&s); 
    inputStack(n, &s);
    print(s);
    reverseStack(&s);
    printf("Sau khi dao nguoc Stack: ");
    print(s);

    printf("Nhap so phan tu cua Queue\n");
    int n1; scanf("%d", &n1);
    Queue q; makeNullQueue(&q);
    inputQueue(n1, &q);
    printQueue(q);
    reverseQueue(&q);
    printf("Sau khi dao nguoc Queue: ");
    printQueue(q);

    printf("Nhap so luong phan tu\n");
    int n2; scanf("%d", &n2);
    int arr[n2];
    printf("Nhap day ngau nhien\n");
    for(int i = 0; i < n2; i++){
        scanf("%d", &arr[i]);
    }
    int j = 0;
    Queue res; makeNullQueue(&res);
    while(fullQueue(res) != 1){
        if(j == n2 - 1){
            j = 0;
        }
        int temp = arr[j];
        if(temp % 2 == 1){
            printf("san xuat sp\n");
            enQueue(1, &res);
        }
        else{
            printf("Ban san pham\n");
            deQueue(&res);
        }
        j++;
    }
}