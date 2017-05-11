#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left,*right;
}node;
node* create(node* start,int val,int F[])
{
	node *temp,*newnode,*prev;
	int count=0;
    newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL)
    {
    	printf("node doesn't create");
    	return NULL;
	}
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	if(start==NULL)
	{
		start=newnode;
		F[0]=1;
	}
	else
	{
		count=0;
		temp=start;
		while(temp)
		{
			if(val<(temp->data))
			{
				prev=temp;
				temp=temp->left;
			}
			else if(val>(temp->data))
			{
				prev=temp;
				temp=temp->right;
			}
			count++;
		}
		if(val<(prev->data))
		prev->left=newnode;
		else if(val>(prev->data))
		prev->right=newnode;
		F[count]++;
	}
	return start;
}
int main()
{
	int n,F[100]={0},i,a[100],cost=0;
	node *s1=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	   scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		s1=create(s1,a[i],F);
	}
	for(i=0;i<n;i++)
	{
		cost+=F[i]*i;
	}
	printf("%d",cost);
	return 0;
}
