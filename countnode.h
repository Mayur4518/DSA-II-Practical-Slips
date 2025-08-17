 /*Write a program which uses binary search tree library and counts the total nodes and total leaf nodes   in 
the tree.  
        int countLeaf(T) - returns the total number of leaf nodes from BST. 
        int counttotalnode(T) – returns the total number of nodes from BST.
*/
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
	printf("Enter n nodes:");
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
int countleaf(struct node *root)
{
	struct node *temp=root;
	static int cnt=0;
	if(temp!=NULL)
	{
		if(temp->left==NULL && temp->right==NULL)
		{
			cnt++;
		}
		countleaf(temp->left);
		countleaf(temp->right);
	}
	return cnt;
}
int counttotalnode(struct node *root)
{
	struct node *temp=root;
	static int cnt;
	if(temp!=NULL)
	{
		cnt++;
		counttotalnode(temp->left);
		counttotalnode(temp->right);
	}
	return cnt;
}
