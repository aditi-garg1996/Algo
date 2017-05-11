#include<stdio.h>
#include<stdlib.h>
typedef struct stack1{
	int top,capacity;
	char* array;
}stack1;
stack1 *stack;
void createstack(int size)
{
	stack=(stack1*)malloc(sizeof(stack1));
	stack->top=-1;
	stack->capacity=size;
	stack->array=(char*)malloc(size*sizeof(char));
}
void push(char elem)
{
	if(!isFull())
	{
		stack->top++;
		stack->array[stack->top]=elem;
    }
	else
	   return;
}
char pop()
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
int check(char* a)
{
	int i;
	char ch;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]=='('||a[i]=='{'||a[i]=='[')
		   push(a[i]);
		else
		{
			ch=pop();
			if(a[i]=='}'&&ch!='{')
			return 0;
			if(a[i]==']'&&ch!='[')
			return 0;
			if(a[i]==')'&&ch!='(')
			return 0;
		}
	}
	if(stack==NULL)
	return 1;
	else
	return 0;
}
int main()
{
	createstack(20);
	char exp[20];
	gets(exp);
	printf("%d",check(exp));
	return 0;
}
