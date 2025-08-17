/*Implement a Binary search tree (BST) library (btree.h) with operations – create, insert, post order. Write 
a menu driven program that performs the above operations*/
#include<stdio.h>
#include"tree.h"
int main()
{
	int ch;
	struct node *root=NULL;
	do{
		printf("Enter Choice:\n");
		printf("1-Create:2-Insert:3-Post Order:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:root=create(root);
			       break;
			case 2:insert(root);
			       break;
			case 3:postorder(root);
			       break;
			default:printf("Invalid Choice..!");
			       break;
		}
	}while(ch<4);
}
