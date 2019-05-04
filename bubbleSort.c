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

void bubbleSort(int *A, int size)
{
	int i, j, tmp=0;
	for(i=1 ; i<size ; i++ )
	{
		for(j=0 ; j<size-i ; j++)
		{
			if(A[j] > A[j+1])
			{
				tmp = A[j];
				A[j] = A[j+1];
				A[j+1] = tmp;
			}
		}
	}
}

int main()
{
	int size;
	
	printf("\n\nEnter the array size : ");
	scanf("%d",&size);
	int Array[size];
	printf("Enter the elements of the array \n");
	inputArray(Array , size);
	printf("Array before sorting \n");
	printArray(Array , size);
	printf("Array after sorting \n");
	bubbleSort(Array , size);
	printArray(Array , size); 
				
	return 0;	
}
