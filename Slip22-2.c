/* Write a C program that accepts the vertices and edges of a graph and store it as an adjacency matrix. 
Implement functions to print indegree, outdegree and total degree of all vertices of graph. */
#include<stdio.h>
int main()
{
	int a[20][20],i,j,n,sumin,sumout;
	printf("Enter no of vertices:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
			if(i!=j)
			{
				printf("Enter edge between V%d and V%d ",i+1,j+1);
				scanf("%d",&a[i][j]);
			}
		}
	}
	printf("Adjacency Matrix:\n");
	for(i=0;i<n;i++)
	{
		printf("V%d\t",i+1);
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("Vertex\tIndegree\tOutdegree\tTotal\n");
	for(i=0;i<n;i++)
	{
		sumin=0,sumout=0;
		for(j=0;j<n;j++)
		{
			sumin=sumin+a[j][i];
			sumout=sumout+a[i][j];
		}
		printf("V%d\t%d\t%d\t%d\n",i+1,sumin,sumout,(sumin+sumout));
	}
}
