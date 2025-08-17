/*Write a C program for the implementation of Floyd Warshall’s algorithm for finding all pairs shortest 
path using adjacency cost matrix.*/
#include<stdio.h>
int i,j,k,n,a[10][10];
void printMatrix()
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==99)
			   printf("%4s","INF");
			else
			   printf("%4d",a[i][j]);
		}
		printf("\n");
	}
}
void FloydWarshall()
{
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][k]+a[k][j]<a[i][j])
				{
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
		printf("\nd(%d):\n",k+1);
		printMatrix();
	}
}
int main()
{
	printf("Enter limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	FloydWarshall();
}
