#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100
void countingSort(int* arr)
{
	int max = arr[0];
	for(int i=0; i<SIZE; i++)
	{
		if (arr[i]>max)
			max=arr[i];
	}
	int* freq = (int*)malloc(sizeof(int)*max);
	for(int i=0; i<max; i++)
		freq[i]=0;
	for(int i=0; i<SIZE; i++)
		freq[arr[i]]++;
	int k=0;
	for(int i=0; i<max; i++)
		for(int j=0; j<freq[i];j++)
			arr[k++]=i;
	printf("k=%d\n",k);
	free(freq);
}
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSort(int* arr, int first, int last)
{
	int left = first;
	int right = last;
	int mid = arr[(left+right)/2];
	do
	{
		while(arr[left]<mid)
			left++;
		while(arr[right]>mid)
			right--;
		if (left<=right)
		{
			if (arr[left]>arr[right])
				swap(arr+left, arr+right);
			left++;
			right--;
		}

	}
	while(left<=right);
	if (left<last)
		quickSort(arr,left,last);
	if(right>first)
		quickSort(arr, first, right);
}
void mergeSort(int* arr, int left, int right)
{
    int t;
	int mid = (left+right)/2;
    if (left < right)
        if (right -left == 1)
		{
            if (arr[right] < arr[left])
				swap(arr+left,arr+right);
        }
        else
        {                   
            mergeSort(arr, left, mid);
            mergeSort(arr, mid+1,right);
            merge(arr, left,mid, right);
        }
}
void merge(int* arr, int left, int mid, int right) 
{ 
    int i, j, k; 
    int n1 = mid - left + 1; 
    int n2 =  right - mid; 

    int* L=(int*)malloc(sizeof(int)*n1);
	int* R=(int*)malloc(sizeof(int)*n2); 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1+ j]; 
  
    i = 0; 
    j = 0;
    k = left;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    }
	free(L);
	free(R);
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
	countingSort(array);
	print();
	gen();
	print();
	quickSort(array, 0,SIZE-1);
	print();
	gen();
	print();
	mergeSort(array, 0,SIZE-1);
	print();
	return 0;
}