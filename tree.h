/*Implement a Binary search tree (BST) library (btree.h) with operations – create, insert, post order. Write 
a menu driven program that performs the above operations*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};
struct node *create(struct node *root)
{
	struct node *newnode,*p,*q;
	int n,i;
	printf("Enter limit:");
	scanf("%d",&n);
	printf("Enter n no of nodes:");
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
struct node *insert(struct node *root)
{
	struct node *newnode,*p,*q;
	int i;
	printf("Enter value:");
	newnode=(struct node *)malloc(sizeof(struct node));
	scanf("%d",&newnode->data);
	newnode->left=newnode->right=NULL;
	if(root==NULL)
	{
		return newnode;
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
	return root;
}
void postorder(struct node *root)
{
	struct node *temp=root;
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d\t",temp->data);
	}
}
