#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *link;
}node;
node* create(int choice)
{
	int val;
	node *start,*last,*temp;
	start=NULL;
	while(choice==1)
	{
		printf("Enter the value:");
		scanf("%d",&val);
		temp=(node*)malloc(sizeof(node));
		if(temp==NULL)
		  exit(1);
		temp->data=val;
		if(start==NULL)
		{
			start=temp;
			last=start;
		}
		else
		{
			last->link=temp;
			last=temp;
		}
		printf("want to enter more??pres 1 if yes:");
		scanf("%d",&choice);
	}
	if(start)
	last->link=NULL;
	return start;
}
node* deleteAt(node *start,int val)
{
	int i;
	node *s1,*temp;
	s1=start;
	if(start==NULL)
    {
    	printf("list is empty\n");
    	return NULL;
	}
	if(s1->data==val)
	{
		temp=start;
		start=start->link;
		free(temp);
	}
	else
	{
	while(s1->link&&s1->link->data!=val)
	{
		s1=s1->link;
	}
	if(s1->link==NULL)
	{
		printf("The data entered is not in the list\n");
		return start;
	}
	temp=s1->link;
	s1->link=temp->link;
	free(temp);
    }
	return start;
}
void traversal(node* start)
{
	while(start!=NULL)
	{
		printf("%d ",start->data);
		start=start->link;
	}
}
int main()
{
	node *s1,*s2;
	int val,choice;
	printf("Do u want to create list");
	scanf("%d",&choice);
	s1=create(choice);
	traversal(s1);
	printf("Enter the data u want to delete");
	scanf("%d",&val);
	s2=deleteAt(s1,val);
	traversal(s2);
}
