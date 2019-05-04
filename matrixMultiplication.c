#include<stdio.h>
#include<stdlib.h>


struct matrix
{
	int m ;
	int n ;
	int **Array;
};

struct matrix* createMatrix()
{

	int i,j;
	
	struct matrix *A = (struct matrix *)malloc(sizeof( struct matrix ));
	
	printf("\nEnter the order of the matrix \nm : ");
	scanf("%d",&(A->m));
	printf("n : ");
	scanf("%d",&(A->n));
	
	printf("\nEnter the elements of the matrix : \n");
	
	A->Array = (int **)malloc( (A->m) * sizeof(int *) );
	
	for(i=0 ; i< (A->m) ; i++)
	{
		A->Array[i] = (int *)malloc( (A->n) * sizeof(int) );
		
		for(j=0 ; j<(A->n) ; j++)
		{
			printf("A[%d][%d] : ",i,j);
			scanf( "%d" , &(A->Array[i][j]) );
		}
	}
	
	printf("\n");
	return A;
}

void printMatrix(struct matrix* M)
{
	int i,j;
	
	printf("The elements of the Matrix are :\n\n");
	
	for(i=0 ; i<(M->m) ; i++)
	{
		for(j=0 ; j<(M->n) ; j++)
		{
			printf( "\t%d" , M->Array[i][j] );
		}
		printf("\n\n");
	}
}

struct matrix* productOf(struct matrix* A , struct matrix* B)
{
	//Check if the matrices can be multiplied 
	if( (A->n) != (B->m) )
	{
		printf("\nMatrices cannot be multiplied \n");
		exit(0);	
	}
	// If yes then multiply the two matrices
	
	int i,j,k;
	struct matrix* C = (struct matrix*)malloc(sizeof(struct matrix));
	C->m = A->m;
	C->n = B->n;
	
	C->Array = (int**)malloc((C->m) * sizeof(int*));
	
	for(i=0 ; i<(C->m) ; i++)
	{
		C->Array[i] = (int *)malloc((C->n) * sizeof(int));
		
		for(j=0 ; j<(C->n) ; j++)
		{
			C->Array[i][j] = 0;
			
			for(k=0 ; k<(A->n) ; k++)
			{
				C->Array[i][j] += A->Array[i][k] * B->Array[k][j];
			}
		}
	}
	return C;
}

int main()
{
	// initialize necessary variables
	int i,j;
		
	// Create Matrix A and its attributes 
	printf("\nFor Matrix A : \n");
	struct matrix* A = createMatrix();
	printMatrix(A); 
	
	// Create Matrix B
	printf("For Matrix B : \n");
	struct matrix* B = createMatrix();
	printMatrix(B);
	
	// Create Product of A and B
	printf("For Product of Two Matrices A and B \n");
	struct matrix* C = productOf(A,B);
	printMatrix(C);

	return 0;	
}
