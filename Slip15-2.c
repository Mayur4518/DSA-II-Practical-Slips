/* Write a C program for the implementation of Dijkstra’s shortest path algorithm for finding shortest path from a 
given source vertex using adjacency cost matrix.*/
#include<stdio.h>
int a[20][20],i,j,n;
void Dijkstras()
{
	int d[20]={0},visit[20],min,v,k;
	i=0;
	visit[0]=1;
	d[0]=0;
	for(j=i;j<n;j++)
	{
		d[j]=a[i][j];
	}
	for(j=0;j<n;j++)
	{
		printf("%d\t",d[j]);
	}
	k=1;
	while(k<n-1)
	{
		min=999;
		for(j=1;j<n;j++)
		{
			if(d[j]<min && visit[j]==0)
			{
				min=d[j];
				v=j;
			}
		}
		visit[v]=1;
		for(j=1;j<n;j++)
		{
			if(d[v]+a[v][j]>d[j])
			{
				d[j]=d[v]+a[v][j];
			}
		}
		k++;
		printf("\nDijkstras Shortest Path\n");
		for(j=0;j<n;j++)
		{
			printf("%d\t",d[j]);
		}
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
	Dijkstras();
}
