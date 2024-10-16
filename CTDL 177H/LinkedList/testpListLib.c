#include <conio.h>
#include <stdio.h>
#include "plistlib.h"

int a[]={32,51,27,83,66,11,45,75};

// a.ham nhap theo thu tu nhap
void appendList(int a[], int n, List *L){

	PNode head = NULL;
	PNode tail = NULL;

	int i = 0;
	while(i < n)
	{
		PNode temp;
		temp = (PNode)malloc(sizeof(Node));
		temp->data = a[i];

		if(head == NULL)
		{
			head = temp;
		}
		else
		{
			tail->next = temp;
		}

		tail = temp;

		i++;
	}
	tail->next = NULL;
	*L = head;
	
}
// ham tao danh sach dao
void reverseList(int a[],int n, List *L){
	PNode head = NULL;
	PNode tail = NULL;
	PNode temp = NULL;
	PNode list =  *L;
	int i = 0, count = n;
	while(i < n)
	{
		temp = (PNode)malloc(sizeof(Node));
		temp = getPosition(count, list);
		if(head == NULL)
		{
			head = temp;
		}
		else
		{
			tail->next = temp;
		}
		tail = temp;
		

		i++; count--;
	}
	tail->next = NULL;


	*L = head;
}


// ham sap xep bubble sort
void bubbleSort(List *L){
	List list = *L;
	int n = len(list);

	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			PNode temp1 = getPosition(j+1, list); PNode temp2 = getPosition(j + 2, list);
			if(temp1->data > temp2->data)
			{
				int tempData = temp1->data;
				temp1->data = temp2->data;
				temp2->data = tempData;
			}
		}
	}

}

// h�m chinh de chay chuong trinh
int main(int argc, char *argv[]){
	List L1;
	appendList(a, sizeof(a)/sizeof(int), &L1);
	print(L1);
	reverseList(a, sizeof(a)/sizeof(int), &L1);
	print(L1);
	insertAt(3,22,&L1);
	print(L1);
	bubbleSort(&L1);
	print(L1);
}


