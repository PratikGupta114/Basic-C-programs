#include<stdio.h>

int numberOfSteps = 0;

void TowerOfHanoi(int n , char S , char D , char A)
{
	
	if(n==1)
	{
		printf("Move disk %d from %c to %c \n",n,S,D);
		numberOfSteps++;
		return;
	}
	else
	{
		// move disk(s) n-1 from Source to Auxiliary
		TowerOfHanoi(n-1 , S , A , D);
		
		// move disk n from Source to Destination
		printf("Move disk %d from %c to %c \n",n,S,D);
		numberOfSteps++;
		
		// move the rest n-1 disk(s) from Auxiliary to Destination
		TowerOfHanoi(n-1 , A , D , S);
	}
}

int main()
{
	int N;
	printf("Enter the number of Disks \n");
	scanf("%d",&N);
	TowerOfHanoi(N , 'A' , 'C' , 'B' );
	printf("\nTotal Number of Steps : %d \n\n",numberOfSteps);
	
	return 0;
}
