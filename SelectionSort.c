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

void selectionSort(int *A, int size)
{
	int small ,tmp ,pos , i = 0 , j = 0;
	for(i = 0 ; i < size ; i++)
	{
		small = A[i];
		pos = i;
		
		for(j=i+1 ; j<size ; j++)
		{
			if(A[j] < small )
			{
				small = A[j];
				pos = j;
			}
		}
		tmp = A[i];
		A[i] = A[pos];
		A[pos] = tmp;
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
	selectionSort(Array , size);
	printArray(Array , size); 
				
	return 0;	
}
