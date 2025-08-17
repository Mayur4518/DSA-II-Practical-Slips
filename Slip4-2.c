/*Write a program which uses binary search tree library and counts the total nodes and total leaf nodes   in 
the tree.  
        int countLeaf(T) - returns the total number of leaf nodes from BST. 
        int counttotalnode(T) – returns the total number of nodes from BST.
*/
#include<stdio.h>
#include"countnode.h"
int main()
{
	struct node *root=NULL;
	root=create(root);
	printf("Leaf nodes=%d\n",countleaf(root));
	printf("Total nodes=%d",counttotalnode(root));
}
