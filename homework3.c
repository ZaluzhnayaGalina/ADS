#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
int* generateArray(int n)
{
	int* a = (int*)malloc(n*sizeof(int));
	srand(time(NULL));
	for(int i=0; i<n;i++)
		a[i]=rand()%100;
	return a;
}

void printArray(int* a, int n)
{	
	for(int i=0;i<n;i++)
		printf("%d ", a[i]);
	printf("\n");
}
void swap(int* a1, int* a2)
{
	int tmp = *a1;
	*a1=*a2;
	*a2=tmp;
}
int simpleBubbleSort(int* a, int n)
{
	int operations = 0;
	for (int i=0; i<n; i++)
		for(int j=0; j<n-1; j++)
		{		
			operations++;
			if (a[j]>a[j+1])
			{
				swap(a+j, a+j+1);
			}
		}
	return operations;
}
int myBubbleSort(int* a, int n)
{
	int operations = 0;
	for (int i=0; i<n; i++)
		for(int j=0; j<n-i-1; j++)//последние i больших элементов уже "всплыли" наверх, и их можно не рассматривать, уменьшаем число сравнений
		{
			operations++;
			if (a[j]>a[j+1])
			{
				swap(a+j, a+j+1);
			}
		}
	return operations;
}
int shakerSort(int* a, int n)
{
	int operations = 0;
	int d=0;
	while (d<n-d-1)
	{
		for (int i=d; i<n-d-1; i++)
		{
			operations++;
			if (a[i]>a[i+1])
			{
				swap(a+i, a+i+1);
			}
		}
		d++;
		for(int i=n-d-1; i>=d; i--)
		{
			operations++;
			if (a[i-1]>a[i])
			{
				swap(a+i-1, a+i);
			}
		}
		d++;
	}
	return operations;
}

int main()
{
	int n = 25;
	int* arr=generateArray(n);	
	printArray(arr, n);
	int sbso = simpleBubbleSort(arr, n);
	printf("Simple bubble sort operations: %d\n", sbso);
	arr=generateArray(n);	
	printArray(arr, n);
	int mbso = myBubbleSort(arr, n);
	printf("My bubble sort operations: %d\n", mbso);
	arr=generateArray(n);	
	printArray(arr, n);
	int ssso = shakerSort(arr, n);
	printf("Shaker sort operations: %d\n", ssso);
	printArray(arr,n);
	return 0;
}