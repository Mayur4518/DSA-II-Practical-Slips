/*Write a C program that accepts the vertices and edges of a graph and stores it as an
adjacency matrix.Display the adjacency matrix.*/
#include<stdio.h>
int main()
{
	int a[10][10],n,i,j;
	printf("Enter no of vertices:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
			if(i!=j)
			{
				printf("Enter edges between V%d and V%d",i+1,j+1);
				scanf("%d",&a[i][j]);
			}
		}
	}
	printf("Adjacency Matrix\n");
	printf("\tV1\tV2\tV3\tV4\n");
	for(i=0;i<n;i++)
	{
		printf("V%d\t",i+1);
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
