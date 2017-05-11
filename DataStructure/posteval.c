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
int posteval(char* a)
{
	int i,x,y;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			push(a[i]-'0');
		}
		else
		{
			x=pop();
			y=pop();
			switch(a[i])
			{
				case '+':push(y+x);
				         break;
				case '-':push(y-x);
				         break;
				case '*':push(y*x);
				         break;
				case '/':push(y/x);
				         break;
				default:printf("invalid operand");
		                return;
			}
		}
	}
	return stack->array[stack->top];
}
int main()
{
	createstack(20);
	char postfix[20];
	gets(postfix);
	printf("%d",posteval(postfix));
	return 0;
}
