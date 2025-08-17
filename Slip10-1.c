//Write a C program for the implementation of Topological sorting. 
#include<stdio.h>
int a[20][20],n,i,j;
int indegree[20]={0};
int visit[20]={0};
#define MAX 30
struct stack
{
	int a[MAX];
	int top;
};
struct stack s;
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
void push(int  num)
{
	s.top++;
	s.a[s.top]=num;
}
int pop()
{
	return s.a[s.top--];
}
void topologicalsort()
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
		int v=pop();
		for(i=0;i<n;i++)
		{
			if(a[v][i]==1)
			{
				indegree[i]--;
			}
		}
	}
}
void accept()
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
				printf("Enter edge between V%d and V%d:",i+1,j+1);
				scanf("%d",&a[i][j]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\nV%d\t",i+1);
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	accept();
	printf("Topological Sort:");
	topologicalsort();
}
