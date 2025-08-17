//Write a C program for the implementation of Topological sorting. 
#include<stdio.h>
int a[20][20],i,j,n;
int visit[20]={0};
int indegree[20]={0};
#define max 20
struct stack
{
	int a[max];
	int top;
};
struct stack s;
void init()
{
	s.top=-1;
}
int isempty()
{
	return s.top==-1;
}
int isFull()
{
	return s.top==max-1;
}
void push(int num)
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
			if(a[j][i]!=0)
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
		if(isempty())
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
	printf("Enter no vertices:");
	scanf("%d",&n);
	printf("Enter elements of matrix:");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
			if(i!=j)
			{
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
	printf("\nTopological Sort=");
	topologicalsort();
}
