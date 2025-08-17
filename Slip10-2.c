/*Write a C program that accepts the vertices and edges of a graph. Create adjacency list and display the     
adjacency list.*/
#include<stdio.h>
#include<stdlib.h>
int a[20][20],i,j,n;
struct node
{
	int data;
	struct node *next;
};
struct node *head[20];
void accept()
{
	printf("Enter no of nodes:");
	scanf("%d",&n);
	printf("Enter Matrix:");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
			if(i!=j)
			  scanf("%d",&a[i][j]);
		}
	}
}
void disp()
{
	printf("\n");
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
void create()
{
	struct  node *temp,*newnode;
	for(i=0;i<n;i++)
	{
		head[i]=NULL;
		for(j=0;j<n;j++)
		{
			if(a[i][j]==1)
			{
				newnode=(struct node *)malloc(sizeof(struct node));
				newnode->data=j+1;
				newnode->next=NULL;
				if(head[i]==NULL)
				{
					head[i]=temp=newnode;
					continue;
				}
				temp->next=newnode;
				temp=newnode;
			}
		}
	}
}
void displist()
{
	struct node *temp;
	for(i=0;i<n;i++)
	{
		printf("V%d---->",i+1);
		for(temp=head[i];temp!=NULL;temp=temp->next)
		{
			printf("V%d-",temp->data);
		}
		printf("NULL\n");
	}
}
int main()
{
	accept();
	disp();
	create();
	displist();
}
