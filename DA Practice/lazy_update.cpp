#include<bits/stdc++.h>
using namespace std;
void construct_tree(int arr[],int seg[],int left,int right,int pos)
{
	if(left==right)
	  seg[pos]=arr[left];
	else
	{
		int mid=(left+right)/2;
		construct_tree(arr,seg,left,mid,2*pos+1);
		construct_tree(arr,seg,mid+1,right,2*pos+2);
		seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
	}
}
void range_update(int seg[],int lazy[],int start,int end,int left,int right,int pos,int val)
{
	if(lazy[pos]!=0)
	{
		seg[pos]+=lazy[pos];
		lazy[2*pos+1]=lazy[pos];
		lazy[2*pos+2]=lazy[pos];
		lazy[pos]=0;
	}
	if(right<start||left>end)
	  return;
	if(start<=left&&end>=right)
	{
		seg[pos]+=val;
		if(left!=right)
		{
			lazy[2*pos+1]+=val;
			lazy[2*pos+2]+=val;
		}
		return;
	}
	int mid=(left+right)/2;
	range_update(seg,lazy,start,end,left,mid,2*pos+1,val);
	range_update(seg,lazy,start,end,mid+1,right,2*pos+2,val);
	seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}
int query(int seg[],int arr[],int lazy[],int start,int end,int left,int right,int pos)
{
	if(lazy[pos]!=0)
	{
		seg[pos]+=lazy[pos];
		lazy[2*pos+1]=lazy[pos];
		lazy[2*pos+2]=lazy[pos];
		lazy[pos]=0;
	}
	if(right<start||left>end)
	  return INT_MAX;
	if(start<=left&&end>=right)
	  return seg[pos];
	int mid=(left+right)/2;
	return min(query(seg,arr,lazy,start,end,left,mid,2*pos+1),query(seg,arr,lazy,start,end,mid+1,right,2*pos+2));
}
int main()
{
	int N,i;
	cin>>N;
	int arr[N],seg[4*N+1],lazy[4*N+1];
	for(i=0;i<N;i++)
	  cin>>arr[i];
	memset(lazy,0,sizeof(lazy));
	construct_tree(arr,seg,0,N-1,0);
	range_update(seg,lazy,0,3,0,N-1,0,3);
	range_update(seg,lazy,0,3,0,N-1,0,1);
	range_update(seg,lazy,0,0,0,N-1,0,2);
	cout<<query(seg,arr,lazy,3,5,0,N-1,0);
}
