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

int partition(int *A , int l, int h )
{
	int i = l , j = h , pivot = A[l],tmp=0;
	while(i < j)
	{
		do{
			i++;
		}while(A[i] <= pivot);
		
		do{
			j--;
		}while(A[j] > pivot);
		
		if(i < j)
		{
	    	tmp = A[i];
	    	A[i] = A[j];
	    	A[j] = tmp;
	    } 
	}
	tmp = A[l];
	A[l] = A[j];
	A[j] = tmp;
	return j;
}

void quickSort(int *A, int l, int h)
{
	if(l < h)
	{
		int index = partition(A , l , h);
		quickSort(A , l , index);
		quickSort(A , index+1 , h);
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
	quickSort(Array , 0, size);
	printArray(Array , size); 
				
	return 0;	
}
