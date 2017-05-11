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
void inorder(node* start){
	if(start)
	{
		inorder(start->left);
		printf("%d ",start->data);
		inorder(start->right);
	}
}
int findSameTree(node* tree1,node* tree2)
{
	if(!tree1&&!tree2)
	  return 1;
	else if(!tree1||!tree2)
	  return 0;
	else
	{
		return(tree1->data==tree2->data&&(findSameTree(tree1->left,tree2->left))&&(findSameTree(tree1->left,tree2->left)));
	}
}
int main()
{
	int choice;
	node* t1,*t2;
	printf("Do u want to create root of tree1");
	scanf("%d",&choice);
	t1=create(choice);
	inorder(t1);
	printf("Do u want to create root of tree2");
	scanf("%d",&choice);
	t2=create(choice);
	inorder(t2);
	choice=findSameTree(t1,t2);
	if(choice==1)
	  printf("Two trees are identical");
	else
	  printf("Two trees are not identical");
	return 0;
}
