#include<stdio.h>
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
void traversal(node* start)
{
	while(start!=NULL)
	{
		printf("%d ",start->data);
		start=start->link;
	}
}
int findMid(node* start)
{
	node *s1,*s2;
	s1=start;
	s2=start;
	while(s1!=NULL&&s1->link!=NULL)
	{
		s1=s1->link->link;
		s2=s2->link;
	}
	if(s2)
	return s2->data;
	else
	return -1;
}
int main()
{
	node* s1;
	int choice;
	printf("Do u want to create list?Press 1 if Yes...");
	scanf("%d",&choice);
	s1=create(choice);
	traversal(s1);
	printf("The mid of the list is:%d ",findMid(s1));
	return 0;
}
