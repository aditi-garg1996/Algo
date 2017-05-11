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
int precedence(char ch)
{
	if(ch=='/'||ch=='*')
	  return 2;
	if(ch=='+'||ch=='-')
	  return 1;
	return 0;
}
void intopost(char infix[],char postfix[])
{ 
    int i,k=0;
    char ch;
	for(i=0;infix[i]!='\0';i++)
	{
	    ch=infix[i];
		if(ch>='a'&&ch<='z')
		   	postfix[k++]=ch;
		else if(ch=='(')
		    push(ch);
		else if(ch==')')
		{
			while(!(isEmpty())&&(ch=pop())!='(')
			{
			   postfix[k++]=ch;
		    }
		}
		else
		{
		if(precedence(ch)>precedence(stack->array[stack->top])||isEmpty())
		  push(ch);
		else
		{
			while(!isEmpty()&&precedence(stack->array[stack->top])>=precedence(ch))
			postfix[k++]=pop();
			push(ch);
	    }
	    }
	   // printf("%c\n",stack->array[stack->top]);
	}	
	while(!isEmpty())
	{
		postfix[k++]=pop();
	}
	postfix[k++]='\0';
}
int main()
{
	char infix[20],postfix[20];
	createstack(20);
	gets(infix);
	intopost(infix,postfix);
	puts(postfix);
	return 0;
}
