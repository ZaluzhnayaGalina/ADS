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
	int left=0, right=n-1;
	while (left<right)
	{
		for (int i=left; i<right; i++)
		{
			operations++;
			if (a[i]>a[i+1])
			{
				swap(a+i, a+i+1);
			}
		}
		right--;
		for(int i=right; i>left; i--)
		{
			operations++;
			if (a[i-1]>a[i])
			{
				swap(a+i-1, a+i);
			}
		}
		left++;
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
int binarySearch(int* a, int arrSize, int value)
{
	int left=0, right = arrSize-1;
	int mid = (left+right)/2;
	while (a[mid]!=value && left<right-1)
	{
		if (value<a[mid])		
			right = mid;		
		else //value>a[mid]		
			left = mid;		
		mid = (left+right)/2;	
	}
	if (a[mid]==value)
		return mid;
	else return -1;
}
int main()
{
	int n = 25;
	int* arr=generateArray(n);	
	printArray(arr, n);
	int sbso = simpleBubbleSort(arr, n);
	printf("Simple bubble sort operations: %d, n^2=%d\n", sbso, n*n);
	arr=generateArray(n);	
	printArray(arr, n);
	int mbso = myBubbleSort(arr, n);
	printf("My bubble sort operations: %d, n^2=%d\n", mbso, n*n);
	arr=generateArray(n);	
	printArray(arr, n);
	int ssso = shakerSort(arr, n);
	printf("Shaker sort operations: %d, n*n=%d\n", ssso, n*n);
	printArray(arr,n);
	int id20 = binarySearch(arr, n, 20);
	printf("Id of 20: %d\n", id20);
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