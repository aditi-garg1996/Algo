#include<stdio.h>
typedef struct node{
    struct node *left,*right;
	int data;	
}node;
node* create(int choice)
{
	if(choice==1)
	{
	node *temp,*start=NULL;
	temp=(node*)malloc(sizeof(node));
	if(temp!=NULL)
	{
		printf("Enter the data u want to insert");
		scanf("%d",&(temp->data));
		if(start==NULL)
		start=temp;
		printf("Do u want to create left child of node %d:",temp->data);
		scanf("%d",&choice);
		temp->left=create(choice);
		printf("Do u want to create right child of node %d:",temp->data);
		scanf("%d",&choice);
		temp->right=create(choice);
		return start;
	}
    }
    else
      return NULL;
}
void printPath(int path[],int pathlen)
{
	int i=0;
	for(i=0;i<pathlen;i++)
	{
		printf("%d ",path[i]);
	}
	printf("\n");
}
void printpathleaf(node *tree,int path[],int pathlen)
{
	if(tree==NULL)
	   return;
	path[pathlen]=tree->data;
	pathlen++;
	if((tree->left==NULL)&&(tree->right==NULL))
	   printPath(path,pathlen);
	else
	{
		printpathleaf(tree->left,path,pathlen);
		printpathleaf(tree->right,path,pathlen);
	}
}
int main()
{
	int choice,path[1000];
	node* t1;
	printf("Do u want to create root");
	scanf("%d",&choice);
	t1=create(choice);
	printpathleaf(t1,path,0);
	return 0;
}
