#include<bits/stdc++.h>
using namespace std;
void floyd_warshall(int dp[100][100],int n,int path[100][100])
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(dp[i][k]!=INT_MAX&&dp[k][j]!=INT_MAX)
				{
					if(dp[i][j]>(dp[i][k]+dp[k][j]))
					{
						dp[i][j]=dp[i][k]+dp[k][j];
						path[i][j]=k;				
					}
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<endl;
		for(j=0;j<n;j++)
		  cout<<dp[i][j]<<" ";
	}
}
void find_path(int path[100][100],int src,int dest)
{
	int i,p[100],j=0;
	for(i=0;i<4;i++)
	{
		cout<<endl;
		for(j=0;j<4;j++)
		  cout<<path[i][j]<<" ";
	}
	j=0;
	i=path[src][dest];
	p[j++]=dest;
	while(i!=src&&i!=dest)
	{
		p[j++]=i;
		i=path[src][i];
	}
	p[j++]=src;
	for(i=j-1;i>=0;i--)
	  cout<<p[i]<<" ";
}
int main()
{
	int graph[100][100],n,e,a,b,c,path[100][100],i,j;
	cin>>n>>e;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		   if(i==j)
		     graph[i][j]=0;
		   else
		     graph[i][j]=INT_MAX;
		   path[i][j]=n;
	    }
	}
	for(i=0;i<e;i++)
	{
		cin>>a>>b>>c;
		graph[a][b]=c;
		path[a][b]=a;
	}
	floyd_warshall(graph,n,path);
	find_path(path,0,n-1);
}
