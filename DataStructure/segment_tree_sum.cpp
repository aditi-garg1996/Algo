#include<bits/stdc++.h>
using namespace std;
void construct_tree(int input[],int segtree[],int low,int high,int pos)
{
	if(low==high)
	{
		segtree[pos]=input[low];
		return;
	}
	int mid=(low+high)/2;
	construct_tree(input,segtree,low,mid,2*pos+1);
	construct_tree(input,segtree,mid+1,high,2*pos+2);
	segtree[pos]=segtree[2*pos+1]+segtree[2*pos+2];
}
int range_query(int segtree[],int qlow,int qhigh,int low,int high,int pos)
{
	if(qlow<=low&&qhigh>=high)
	   return segtree[pos];
	if(qlow>high||qhigh<low)
	   return 0;
	int mid=(low+high)/2;
	return (range_query(segtree,qlow,qhigh,low,mid,2*pos+1)+
	range_query(segtree,qlow,qhigh,mid+1,high,2*pos+2));
}
int main()
{
	int n,r,qlow,qhigh,i;
	cin>>n;
	int input[n],segtree[2*n-1];
	for(i=0;i<n;i++)
	  cin>>input[i];
	construct_tree(input,segtree,0,n-1,0);
	cin>>r;
	while(r--)
	{
		cin>>qlow>>qhigh;
		cout<<range_query(segtree,qlow,qhigh,0,n-1,0)<<endl;
	}
	return 0;
}
