#include<stdio.h>
#include<stdlib.h>
typedef struct stack1{
	int top,capacity;
	int*array;
}stack1;
stack1* createstack(int size)
{
	stack1* stack=(stack1*)malloc(sizeof(stack1));
	if(stack)
	{
	    stack->top=-1;
	    stack->capacity=size;
	    stack->array=(int*)malloc(size*sizeof(int));
	    return stack;
    }
}
void push(stack1* stack,int elem)
{
	if(!isFull(stack))
	{
		stack->top++;
		stack->array[stack->top]=elem;
    }
	else
	{
		printf("stack full\n");
		return;
	}
	   
}
int pop(stack1* stack)
{
	if(!isEmpty(stack))
	{
		return stack->array[stack->top--];
	}
	else
	    return -1;
}
int isEmpty(stack1* stack)
{
	if(stack->top==-1)
	  return 1;
	else
	  return 0;
}
int isFull(stack1* stack)
{
	if(stack->top==stack->capacity-1)
	  return 1;
	else
	  return 0;
}
int main()
{
	int i,choice=1,elem;
	stack1* stack=createstack(20);
	while(choice==1)
    {
    printf("Press 1 to insert and 2 to delete");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Enter element:");
        scanf("%d",&elem);
        push(stack,elem);
    }
    else if(choice==2)
    {
        elem=pop(stack);
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
