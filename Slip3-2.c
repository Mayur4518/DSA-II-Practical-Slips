/*Write a C program for the Implementation of Prim’s Minimum spanning tree algorithm.*/
#include<stdio.h>
void prims(int a[20][20],int n)
{
	int min,e,i,j,u,v;
	int b,c,mincost;
	int visit[20]={0};
	visit[0]=1;
	for(e=0;e<=n-1;e++)
	{
		for(i=0,min=999;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]<min)
				{
					if(visit[i]==1)
					{
						 min=a[i][j];
						 u=b=i;
						 v=c=j;
					}
				}
			}
		}
		if(visit[u]==0||visit[v]==0)
		{
			printf("\nEdge-%d-%d cost-%d",u+1,v+1,min);
			visit[v]=1;
			mincost=mincost+min;
		}
		a[u][v]=a[v][u]=999;
	}
	printf("\nMinimum Cost=%d",mincost);
}
int main()
{
	int a[20][20],i,j,n;
	printf("Enter limit:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)
			  a[i][j]=999;
		}
	}
	prims(a,n);
}
