#include<stdio.h>
#include<stdlib.h>

void inputArray(int *A , int size)
{
	int i = 0;
	for(i=0 ; i<size ; i++)
	{
		printf("A[%d] : ",i);
		scanf("%d",&A[i]);
	}
	printf("\n");	
}

void printArray(int *A , int size)
{
	int i =0;
	printf("{ ");
	for(i=0 ; i<size ; i++)
	{
		printf("%d, ",A[i]);
	}
	printf("}\n\n");
}

void merge(int *A , int i1, int j1 , int i2 , int j2 )
{
	int temp[(j1-i1) + (j2-i2) + 2];
	int i=i1,j=i2,k=0;
	
	while(i<=j1 && j<=j2)
	{
		if(A[i] < A[j])
			temp[k++] = A[i++];
		else if(A[j] < A[i])
			temp[k++] = A[j++];
		else if(A[j] == A[i])
		{
			temp[k++] = A[j];
			temp[k++] = A[i];
		}
	}
	
	while(i <= j1)
		temp[k++] = A[i++];
	while(j <= j2)
		temp[k++] = A[j++];
		
	for(i=i1,j=0;i<=j2;i++,j++)
		A[i]=temp[j];
		
}

void mergeSort(int *A, int l, int h)
{
	if(l<h)
	{
	    int m = (l+h)/2;
	    //printf("%d %d\n",l,m);
		mergeSort(A,l,m);
		//printf("%d %d\n",m+1,h);
		mergeSort(A,m+1,h);
		merge(A,l,m,m+1,h);
	}
}

int main()
{
	//int *Array;
	int size;
	
	printf("\n\nEnter the array size : ");
	scanf("%d",&size);
	int Array[size];
	printf("Enter the elements of the array \n");
	inputArray(Array , size);
	printf("Array before sorting \n");
	printArray(Array , size);
	printf("Array after sorting \n");
	mergeSort(Array , 0, size-1);
	printArray(Array , size); 
				
	return 0;	
}
