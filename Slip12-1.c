 /*Write C program to implement hash table using array insert and display In case of collision apply linear 
probabing.*/
#include<stdio.h>
int HF(int num,int i)
{
	return (num%10+i)%10;
}
void insert(int ht[10],int num)
{
	int i,ind;
	for(i=0;i<10;i++)
	{
		ind=HF(num,i);
		if(ht[ind]==-1)
		{
			ht[ind]=num;
			return;
		}
	}
	printf("Could not insert Number %d",num);
}
void disp(int ht[20])
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d[%d]\n",i,ht[i]);
	}
}
int main()
{
	int i,ht[10],num,ind;
	for(i=0;i<10;i++)
	{
		ht[i]=-1;
	}
	printf("Enter num to insert:");
	scanf("%d",&num);
	insert(ht,num);
	disp(ht);
}
