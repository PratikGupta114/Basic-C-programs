#include<stdio.h>

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

void insertionSort(int *A , int size)
{
	int i = 0 ;
	int value , hole;
	for(i=0 ; i<size ; i++)
	{
		value = A[i];
		hole = i;
		while(hole > 0 && A[hole-1] > value)
		{
			A[hole] = A[hole-1];
			hole--;
		}
		A[hole] = value;
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
	insertionSort(Array , size);
	printArray(Array , size); 
				
	return 0;	
}
