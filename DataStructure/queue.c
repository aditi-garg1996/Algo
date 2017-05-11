#include<stdio.h>
#define Size 5
int front=0,rear=0,queue[Size];
void insertq(int elem)
{
	if(!isFull())
	{
	rear=(rear+1)%(Size);
	queue[rear]=elem;
    }
    else
    printf("fulll");
}
int deleteq()
{
	if(!isEmpty())
	{
	front=(front+1)%(Size);
	return queue[front];
    }
    else 
    return -1;
}
int isEmpty()
{
	if(rear==front)
	 return 1;
	else
	 return 0;
}
int isFull()
{
	if((rear+1)%(Size)==front)
	  return 1;
	else
	  return 0;
}
int main()
{
	insertq(3);
	insertq(4);
	insertq(5);
	insertq(6);
	printf("%d %d %d %d %d",deleteq(),deleteq(),deleteq(),deleteq(),deleteq());
}
