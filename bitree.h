  /*Implement a Binary search tree (BST) library (bitree.h)with operation-create,search,inorder.
Write a menu driven program that performs the above operations.*/
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
	int i,n;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	printf("Enter n values of nodes:");
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
int search(struct node *root,int num)
{
	struct node *temp=root;
	while(temp!=NULL)
	{
		if(temp->data==num)
		  return 1;
		else if(num<temp->data)
		  temp=temp->left;
		else  
		  temp=temp->right;
	}
	return 0;
}
void inorder(struct node *root)
{
	struct node *temp=root;
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d\t",temp->data);
		inorder(temp->right);
	}
}
