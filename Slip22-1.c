//Write a C program of implementation of topological sort.
#include<stdio.h>
#define MAX 30
int a[20][20],i,j,n,v,indegree[20]={0},visit[20]={0};
struct stack
{
	int a[MAX];
	int top;
}s;
void init()
{
	s.top=-1;
}
int isEmpty()
{
	return s.top==-1;
}
int isFull()
{
	return s.top==MAX-1;
}
void push(int num)
{
    s.top++;
    s.a[s.top=num];
}
int pop()
{
	return s.a[s.top--];
}
void topological()
{
	init();
	for(i=0;i<n;i++)
	{
		indegree[i]=0;
		for(j=0;j<n;j++)
		{
			if(a[j][i]==1)
			{
				indegree[i]++;
			}
		}
	}
	while(i)
	{
		for(i=0;i<n;i++)
		{
			if(indegree[i]==0 && visit[i]==0)
			{
				push(i);
				visit[i]=1;
				printf("V%d\t",i+1);
		   }
	    }
		if(isEmpty())
		{
			break;
		}
		v=pop();
		for(i=0;i<n;i++)
		{
			if(a[v][i]==1)
			{
				indegree[i]--;
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
			  scanf("%d",&a[i][j]);
		}
	}
	printf("Topological Sort=");
	topological();
}
