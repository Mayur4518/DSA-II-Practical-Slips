/* Write a C program which uses Binary search tree library and displays nodes at each level, and total 
levels in the tree.*/
#include<stdio.h>
#include"level.h"
int main()
{
	struct node *root=NULL;
	root=create(root);
	levelorder(root);
}
