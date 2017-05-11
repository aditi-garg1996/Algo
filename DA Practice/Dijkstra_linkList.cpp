#include<bits/stdc++.h>
using namespace std;
int n,pos[100];
typedef struct node{
	int index;
	int val;
}node;
void swap(node *a,node *b)
{
	node temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void adjust(node heap[],int i)
{
	int left,right,mini;
	left=2*i+1;
	right=2*i+2;
	mini=i;
	if(left<n&&heap[i].val>heap[left].val)
	  mini=left;
	if(right<n&&heap[mini].val>heap[right].val)
	  mini=right;
	if(mini!=i)
	{
	  pos[heap[mini].index]=i;
	  pos[heap[i].index]=mini;
	  swap(&heap[mini],&heap[i]);
	  adjust(heap,mini);
    }
}
node extract_min(node heap[])
{
	node a=heap[0];
	pos[heap[0].index]=n-1;
	pos[heap[n-1].index]=0;
	heap[0]=heap[n-1];
	n=n-1;
	adjust(heap,0);
	return a;
}
void decrease_key(node heap[],int i)
{
	if(heap[i].val<heap[(i-1)/2].val)
	{
		pos[heap[i].index]=(i-1)/2;
	    pos[heap[(i-1)/2].index]=i;
		swap(&heap[i],&heap[(i-1)/2]);
	    decrease_key(heap,(i-1)/2);
	}
}
int main()
{
	int N,E,i,a,b,c,u,k;
	cin>>N>>E;
	node heap[N],st;
	n=N;
	int set[N],dist[N];
	memset(set,0,sizeof(set));
	vector<pair<int,int> >graph[N];
	for(i=0;i<E;i++)
	{
		cin>>a>>b>>c;
		graph[a-1].push_back(make_pair(b-1,c));
		graph[b-1].push_back(make_pair(a-1,c));
	}
	for(i=0;i<N;i++)
	{
		heap[i].index=i;
		pos[i]=i;
		if(i==0)
		  heap[i].val=0;
		else
		  heap[i].val=INT_MAX;
	}
	while(n)
	{
		st=extract_min(heap);
		u=st.index;
		dist[u]=st.val;
		set[u]=1;
		for(i=0;i<graph[u].size();i++)
		{
			if(set[graph[u][i].first]==0&&dist[u]!=INT_MAX)
			{
				k=pos[graph[u][i].first];
				if(heap[k].val>(dist[u]+graph[u][i].second))
				{
				    heap[k].val=dist[u]+graph[u][i].second;
				    decrease_key(heap,k);
				  /*  for(int i=0;i<n;i++)
	  cout<<heap[i].val<<" "<<heap[i].index<<" ";*/
				}
			}
		}
	}
	for(i=0;i<N;i++)
	{
		cout<<dist[i]<<" ";
	}
}
