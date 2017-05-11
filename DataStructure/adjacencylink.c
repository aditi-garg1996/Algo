#include<stdio.h>
#define Size 10
typedef struct node{
	int data;
	struct node *link;
}node;
node* n[10];
int visited[10]={0};
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
void createGraph(int nodes)
{
	node *newnode,*last;
	int i,choice;
	for(i=0;i<nodes;i++)
	{
		printf("Do u want to connect node %d to other?Press 1 if yes",i);
		scanf("%d",&choice);
		n[i]=NULL;
		while(choice==1)
		{
			newnode=(node*)malloc(sizeof(node));
			if(newnode==NULL)
			{
				printf("malloc fails");
				exit(1);
			}
			printf("Enter the node to which u want to connect");
			scanf("%d",&(newnode->data));
			if(n[i]==NULL)
		    {
		    	n[i]=newnode;
		    	last=newnode;
			}
			else
			{
				last->link=newnode;
				last=newnode;
			}
			if(last)
			  last->link=NULL;
			printf("Do u want more connections");
			scanf("%d",&choice);
		}
	}
}
void bfs()
{
	int a,i;
	node* start;
	insertq(0);
	visited[0]=1;
	while(!isEmpty())
	{
		a=deleteq();
		printf("%d ",a);
		start=n[a];
		while(start)
		{
			if(!visited[start->data])
			{
		        insertq(start->data);
		        visited[start->data]=1;
		    }
		    start=start->link;
		}
	}
}
void dfs(int k)
{
	node* start;
	printf("%d ",k);
	visited[k]=1;
	start=n[k];
	while(start)
	{
		if(!visited[start->data])
		{
			dfs(start->data);
		}
	}
}
int main()
{
	int k,i;
	printf("Enter the number of nodes u want to create");
	scanf("%d",&k);
	createGraph(k);
	printf("The bfs travel of the graph is:\n");
	bfs();
	for(i=0;i<k;i++)
	  if(!visited[i])
	    printf("%d ",i);
	for(i=0;i<k;i++)
	   visited[i]=0;
	printf("The dfs traversal of graph is:");
	dfs(0);
	return 0;
}
