/*Write a C program that accepts the vertices and edges of a graph and store it as an adjacency matrix. 
Implement function to traverse the graph using Depth First Search (DFS) traversal.*/
#include<stdio.h>
void DFS(int a[20][20],int n,int i,int visit[20])
{
	visit[i]=1;
	printf("V%d\t",i+1);
	for(int j=0;j<n;j++)
	{
		if(a[i][j]==1 &&visit[j]==0)
		{
			visit[j]=1;
			DFS(a,n,j,visit);
		}
	}
}
int main()
{
	int a[20][20],i,j,n,visit[20]={0};
	printf("Enter vertices:");
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
	printf("DFS=");
	DFS(a,n,0,visit);
}
