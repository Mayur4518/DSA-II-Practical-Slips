 /*Implement a Binary search tree(BST) library (btree.h)with operations-create,insert,preorder.
 Write a menu driven program that performs the above operation.
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
 	printf("Enter limit:");
 	scanf("%d",&n);
 	printf("Enter values:");
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
 	printf("Enter values:");
 	newnode=(struct node *)malloc(sizeof(struct node));
 	scanf("%d",&newnode->data);
 	newnode->left=newnode->right=NULL;
 	if(root==NULL)
 	{
 		root=newnode;
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
 void preorder(struct node *root)
 {
 	if(root!=NULL)
 	{
 		printf("%d\t",root->data);
 		preorder(root->left);
 		preorder(root->right);
	 }
 }
 
