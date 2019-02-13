#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100
void countingSort(int* arr, int size)
{
	int max = arr[0];
	for(int i=0; i<size; i++)
	{
		if (arr[i]>max)
			max=arr[i];
	}
	int* freq = (int*)malloc(sizeof(int)*max);
	for(int i=0; i<max; i++)
		freq[i]=0;
	for(int i=0; i<size; i++)
		freq[arr[i]]++;
	int k=0;
	for(int i=0; i<max; i++)
		for(int j=0; j<freq[i];j++)
			arr[k++]=i;
	free(freq);
}
int array[SIZE];
void gen()
{
	for(int i=0; i<SIZE;i++)
		array[i]=rand()%100;
}
void print()
{
	for(int i=0; i<SIZE;i++)
		printf("%d ", array[i]);
	printf("\n");
}
int main()
{
	srand(time(NULL));
	gen();
	print();
	countingSort(array,SIZE);
	print();
	return 0;
}