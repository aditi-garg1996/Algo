#include<stdio.h>
typedef struct node{
	int src,dest,weight;
}node;
void print(int distance[],int v)
{
	printf("Vertex     distance from source\n");
	int i;
	for(i=0;i<v;i++)
	   printf(" %d             %d\n",i,distance[i]);
}
int bellman(int v,int e,node a[])
{
	int i,j,V,u,distance[10],parent[10],flag=0;
	distance[0]=0;
	for(i=1;i<V;i++)
	   distance[i]=9999;
	for(i=1;i<V;i++)
	{
		for(j=0;j<e;j++)
		{
			u=a[j].src;
			v=a[j].dest;
			if(distance[v]>(distance[u]+a[j].weight))
			{
				distance[v]=distance[u]+a[j].weight;
				parent[j]=u;
			}
		}
	}
	for(j=0;j<e;j++)
	{
		u=a[j].src;
		v=a[j].dest;
		if(distance[v]>(distance[u]+a[j].weight))
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	  printf("There is a negative cycle in the graph");
	else
	  print(distance,V);
}
int main()
{
    int V = 5;  
    int E = 8;  
    node edge[10];
    edge[0].src = 0;
    edge[0].dest = 1;
    edge[0].weight = -1;
    edge[1].src = 0;
    edge[1].dest = 2;
    edge[1].weight = 4;
    edge[2].src = 1;
    edge[2].dest = 2;
    edge[2].weight = 3;
    edge[3].src = 1;
    edge[3].dest = 3;
    edge[3].weight = 2;
    edge[4].src = 1;
    edge[4].dest = 4;
    edge[4].weight = 2;
    edge[5].src = 3;
    edge[5].dest = 2;
    edge[5].weight = 5;
    edge[6].src = 3;
    edge[6].dest = 1;
    edge[6].weight = 1;
    edge[7].src = 4;
    edge[7].dest = 3;
    edge[7].weight = -3;
 
    bellman(V,E,edge);
 
    return 0;
}
