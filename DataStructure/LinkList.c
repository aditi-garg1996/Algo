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
int count(node *start)
{
	int count1=0;
	while(start)
	{
		count1++;
		start=start->link;
	}
	return count1;
}
int countrec(node *start)
{
	if(start)
	return 1+countrec(start->link);
	else
    return 0;
}
int main()
{
	node *s1;
	int choice;
	printf("Do u want to create list??press 1 if yo");
	scanf("%d",&choice);
	s1=create(choice);
	traversal(s1);
	printf("The count of the linked list is:%d\n",count(s1));
	printf("The recursive count of the linked list is:%d",countrec(s1));
	return 0;
}
