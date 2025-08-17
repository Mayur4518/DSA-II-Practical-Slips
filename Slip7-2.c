/*Write a C program that accepts the vertices and edges of a graph and store it as an adjacency matrix. 
Implement function to traverse the graph using Breadth First Search (BFS) traversal*/
#include<stdio.h>
int i,j,n,a[20][20];
#define MAX 30
struct que
{
	int a[MAX];
	int front,rear;
}q;
void init()
{
	q.front=q.rear=-1;
}
int isempty()
{
	return q.front==q.rear;
}
int isFull()
{
	return q.rear==MAX-1;
}
void add(int num)
{
	q.a[++q.rear]=num;
}
int rm()
{
	return q.a[++q.front];
}
void BFS(int a[20][20],int n,int v)
{
	init();
	int visit[20]={0};
	add(v);
	visit[v]=1;
	while(!isempty())
	{
		i=rm();
		printf("V%d\t",i+1);
		for( j=0;j<n;j++)
		{
			if(a[i][j]==1 && visit[j]==0)
			{
				add(j);
				visit[j]=1;
			}
		}
	}
}
int main()
{
	printf("Enter no of vertices:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
			if(i!=j)
			{
				printf("Enter edge between V%d and V%d",i+1,j+1);
				scanf("%d",&a[i][j]);
			}
		}
	}
	printf("BFS ="); 
	BFS(a,n,0);
}
