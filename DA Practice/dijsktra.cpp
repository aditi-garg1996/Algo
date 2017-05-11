#include<bits/stdc++.h>
using namespace std;
int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
int minKey(int dis[],int vis[],int n)
{
	int i,key;
	int min=INT_MAX;
	for(i=0;i<n;i++)
	{
		if(vis[i]==0&&dis[i]<=min)
		{
			min=dis[i];
			key=i;
		}
	}
	return key;
}
void print(int dis[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<i<<"->"<<dis[i]<<endl;
	}
}
void dijkstra(int n)
{
	int dis[100],vis[100],i,u,v;
	vis[0]=0;
	dis[0]=0;
	for(i=1;i<n;i++)
	{
		dis[i]=INT_MAX;
		vis[i]=0;
	}
	for(i=1;i<n;i++)
	{
		u=minKey(dis,vis,n);
		cout<<u<<" ";
		vis[u]=1;
		for(v=0;v<n;v++)
		{
			if(!vis[v]&&graph[u][v]&&dis[u]!=INT_MAX&&(dis[v]>dis[u]+graph[u][v]))
		    {
		    	dis[v]=dis[u]+graph[u][v];
			}
		}
	}
	print(dis,n);
}
int main()
{
	int i;
    dijkstra(9);
}
