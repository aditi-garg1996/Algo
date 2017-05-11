#include<stdio.h>
#define Size 10
int graph[10][10];
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
	int i,j;
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			if(i!=j)
			{
			    printf("Enter 1 if %d-%d edge exist",i,j);
			    scanf("%d",&graph[i][j]);
		    }
		    else
		        graph[i][j]=0;
		}  
	}
}
void bfs(int nodes)
{
	int a,i;
	insertq(0);
	visited[0]=1;
	while(!isEmpty())
	{
		a=deleteq();
		printf("%d ",a);
		for(i=0;i<nodes;i++)
		{
			if(!visited[i]&&graph[a][i])
			{
		        insertq(i);
		        visited[i]=1;
		    }
		}
	}
}
void dfs(int k,int nodes)
{
	int i;
	printf("%d ",k);
	visited[k]=1;
	for(i=0;i<nodes;i++)
	{
		if(!visited[i]&&graph[0][i])
		{
			dfs(i,nodes);
		}
	}
}
void print(int nodes)
{
	int i,j;
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int k,i;
	printf("Enter the number of nodes in graph");
	scanf("%d",&k);
	createGraph(k);
	print(k);
	printf("The bfs travel of the graph is:\n");
	bfs(k);
	for(i=0;i<k;i++)
	  if(!visited[i])
	    printf("%d ",i);
	for(i=0;i<k;i++)
	   visited[i]=0;
	printf("The dfs traversal of graph is:");
	dfs(0,k);
	return 0;
}
