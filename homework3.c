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
int linearSearch(int* a, int arrSize, int value)
{
	if (arrSize==1 && value!=a[0])
		return 1;
	if (value==a[0])
		return 0;
	if (value!=a[0])
		return 1+linearSearch(a+1, arrSize-1, value);
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
	int searchArr[5] = {2,5,6,7,3};
	int arrSize = 5;
	printArray(searchArr,5);
	int id3 = linearSearch(searchArr, arrSize, 3);
	printf("Id of 3: %d\n", id3);
	int id8 = linearSearch(searchArr, arrSize, 8);
	if (id8>arrSize-1)
		printf("8 not found\n");
	else
		printf("Id of 8: %d\n", id8);
	int id6 = linearSearch(searchArr, arrSize, 6);	
	printf("Id of 6: %d\n", id6);
	return 0;
}