#include<stdio.h>
#include<stdlib.h>
typedef struct stack1{
	int top,capacity;
	int*array;
}stack1;
stack1 *stack;
void createstack(int size)
{
	stack=(stack1*)malloc(sizeof(stack1));
	stack->top=-1;
	stack->capacity=size;
	stack->array=(int*)malloc(size*sizeof(int));
}
void push(int elem)
{
	if(!isFull())
	{
		stack->top++;
		stack->array[stack->top]=elem;
    }
	else
	   return;
}
int pop()
{
	if(!isEmpty())
	{
		return stack->array[stack->top--];
	}
	else
	    return -1;
}
int isEmpty()
{
	if(stack->top==-1)
	  return 1;
	else
	  return 0;
}
int isFull()
{
	if(stack->top==stack->capacity-1)
	  return 1;
	else
	  return 0;
}
void insertAtBottom(int item)
{
	int temp;
	if(isEmpty())
	  push(item);
	else{
		temp=pop();
		insertAtBottom(item);
		push(temp);
	}
}
void reverse()
{
	int temp;
	if(!isEmpty())
	{
		temp=pop();
		reverse();
		insertAtBottom(temp);
	}
}
int main()
{
	createstack(20);
    push(1);
    push(2);
    push(3);
    push(4);
    reverse();
	while(!isEmpty())
	{
		printf("%d\n",pop());
	}
}
