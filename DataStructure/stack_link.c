#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *link;
}node;
node* top=NULL;
void push(int elem)
{
	node* newnode;
	newnode=(node*)malloc(sizeof(node));
	if(newnode==NULL)
	{
		printf("stack full\n");
		return ;
	}
	newnode->data=elem;
	newnode->link=top;
	top=newnode;
}
int pop()
{
	node *temp;
	int elem;
	if(top==NULL)
	   return -1;
	temp=top;
	elem=temp->data;
	top=top->link;
	free(temp);
	return elem;
}
int main()
{
	int i,choice=1,elem;
	while(choice==1)
    {
    printf("Press 1 to insert and 2 to delete");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Enter element:");
        scanf("%d",&elem);
        push(elem);
    }
    else if(choice==2)
    {
        elem=pop();
        if(elem!=-1)
           printf("the deleted element is:%d\n",elem);
        else
           printf("stack empty\n");
    }
    else 
       printf("Enter right choice");
    printf("press 1 to continue");
    scanf("%d",&choice);
    }
	return 0;
}
