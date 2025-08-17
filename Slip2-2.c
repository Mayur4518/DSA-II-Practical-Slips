/*Implement a Binary search tree (BST) library (bitree.h)with operation-create,search,inorder.
Write a menu driven program that performs the above operations.*/
#include<stdio.h>
#include"bitree.h"
int main()
{
	struct node *root=NULL;
	int ch,num,res;
	do
	{
		printf("\nEnter Choice:");
		printf("\n1-Create:\n2-Search:\n3-Inorder:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:root=create(root);
			       break;
			case 2:printf("Enter number to search:");
			       scanf("%d",&num);
			       res=search(root,num);
			       if(res==1)
			         printf("Number Found..!");
			       else
			         printf("Number Not Found..!");
			       break;
			case 3:inorder(root);
			       break;
			default:printf("Invalid Choice..!");
			        break;
		}
	}while(ch<4);
}
