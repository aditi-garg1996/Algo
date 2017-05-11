#include<bits/stdc++.h>
using namespace std;
typedef struct node{
	int weight;
	int profit;
}node;
int x[100];
int maxim;
vector<int> b;
void find_print(int x[],int k,node a[])
{
	int i,sum=0;
	for(i=0;i<=k;i++)
	{
		if(x[i])
		  sum+=a[i].profit;
	}
	if(sum>maxim)
	{
		maxim=sum;
		b.clear();
	    for(i=0;i<=k;i++)
		{
			if(x[i])
		  	b.push_back(a[i].profit);
		}
	}
}
void sum_subset(int s,int k,int r,int n,node a[],int m)
{
	if(k>=n)
	   find_print(x,k-1,a);
	x[k]=1;
	if(s+a[k].weight==m)
	  find_print(x,k,a);
	if(s+a[k].weight+a[k+1].weight<=m)
	{
	   sum_subset(s+a[k].weight,k+1,r-a[k].weight,n,a,m);
    }
	if((s+a[k+1].weight<=m)&&(s+r-a[k].weight>=m))
	{
	   x[k]=0;
	   sum_subset(s,k+1,r-a[k].weight,n,a,m);
    }
}
int comparison(node a,node b)
{
	return a.weight<b.weight;
}
int main()
{
	int i,n,sum=0,m;
	node a[1000];
	cout<<"enter the number of terms:";
	cin>>n;
	cout<<"Enter the weight and profit:";
	for(i=0;i<n;i++)
	   cin>>a[i].weight>>a[i].profit;
	cout<<"Enter the maximum sum:";
	cin>>m;
	sort(a,a+n,comparison);
	sum=0;
	for(i=0;i<n;i++)           
	   sum+=a[i].weight;
	sum_subset(0,0,sum,n,a,m);
	for(i=0;i<b.size();i++)
	  cout<<b[i]<<" ";
}
