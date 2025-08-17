/*Implement a Binary search tree(BST) library (btree.h)with operations-create,insert,preorder.
 Write a menu driven program that performs the above operation.
 */
#include<stdio.h>
#include"btree.h"
int main()
{
	struct node *root=NULL;
	int ch;
	do
	{
		printf("Enter Choice:");
		printf("\n1-Create:\n2-Insert:\n3-Preorder:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:root=create(root);
			       break;
			case 2:insert(root);
			       break;
			case 3:preorder(root);
			       break;
			default:printf("Invalid Choice..!");
			        break;
		}
	}while(ch<4);
}
