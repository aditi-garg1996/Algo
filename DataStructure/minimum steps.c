#include<stdio.h>
#include<math.h>
#define Size 1000
typedef struct node{
    struct node *left,*right;
	int data;	
}node;
int front=0,rear=0;
node* queue[Size];
void insertq(node* elem)
{
	if(!isFull())
	{
	rear=(rear+1)%(Size);
	queue[rear]=elem;
    }
    else
    printf("fulll");
}
node* deleteq()
{
	if(!isEmpty())
	{
	front=(front+1)%(Size);
	return queue[front];
    }
    else 
    return NULL;
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
int power(int a,int b)
{
	int i,p=1;
	for(i=1;i<=b;i++)
	{
		p=a*a;
	}
	return p;
}
int countMinimum(int num)
{
	int count=1,i,l;
	node *tree=NULL,*temp;
	if(num==0)
	  return 0;
	tree=(node*)malloc(sizeof(node));
	tree->data=0;
	tree->left=NULL;
	tree->right=NULL;
	count=1;
	l=1;
	insertq(tree);
	while(1)
	{
		temp=deleteq();
		temp->left=(node*)malloc(sizeof(node));
		temp->right=(node*)malloc(sizeof(node));
		i=temp->data;
		temp->left->data=i-count;
		if(i-count==num)
		{
			break;
		}
		temp->right->data=i+count;
		if(i+count==num)
		{
			break;
		}
		insertq(temp->left);
		insertq(temp->right);
		l=l+2;
		if(l==(pow(2,count+1)-1))
	    {
		   count++;
	    }
	}
	return count;
}
int main()
{
	int num;
	scanf("%d",&num);
	printf("The minimum number of steps required is:%d",countMinimum(num));
	return 0;
}
