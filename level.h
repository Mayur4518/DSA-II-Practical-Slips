/* Write a C program which uses Binary search tree library and displays nodes at each level, and total 
levels in the tree.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 30
struct node
{
	int data;
	struct node *left,*right;
};
struct que
{
	struct node *a[MAX];
	int front,rear;
}q;
void init()
{
	q.front=q.rear=-1;
}
int isEmpty()
{
	return q.front==q.rear;
}
int isFull()
{
	return q.rear==MAX-1;
}
void add(struct node *temp)
{
	q.a[++q.rear]=temp;
	if(q.front==-1)
	{
		q.front=0;
	}
}
struct node *rm()
{
	return q.a[q.front++];
}
struct node *create(struct node *root)
{
	struct node *newnode,*p,*q;
	int i,n;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	printf("Enter n values:");
	for(i=0;i<n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&newnode->data);
		newnode->left=newnode->right=NULL;
		if(root==NULL)
		{
			root=newnode;
			continue;
		}
		p=root;
		while(p!=NULL)
		{
			q=p;
			if(newnode->data<p->data)
			  p=p->left;
			else
			  p=p->right;
		}
		if(newnode->data<q->data)
		  q->left=newnode;
		else
		  q->right=newnode;
	}
	return root;
}
void levelorder(struct node *root)
{
	struct node *temp,*M=NULL;
	int level=0;
	int cnt=0;
	init();
	add(root);
	add(M);
	printf("Level %d\t:",level);
	while(!isEmpty())
	{
		temp=rm();
		if(temp==M)
		{
			level++;
			cnt++;
			if(!isEmpty())
			{
				add(M);
				printf("\nLevel %d:",level);
			}
		}
		else
		{
			printf("%d\t",temp->data);
			if(temp->left!=NULL)
			  add(temp->left);
			if(temp->right!=NULL)
	          add(temp->right);
		}
	}
	printf("\nTotal Levels=%d",cnt+1);
}
