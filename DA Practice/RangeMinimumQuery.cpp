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
int query(int seg[],int start,int end,int left,int right,int pos)
{
	if(start<=left&&end>=right)
	  return seg[pos];
	if(end<left||start>right)
	  return INT_MAX;
	int mid=(left+right)/2;
	return min(query(seg,start,end,left,mid,2*pos+1),query(seg,start,end,mid+1,right,2*pos+2));
}
void update(int arr[],int seg[],int left,int right,int pos,int val,int idx)
{
	if(left==right)
	{
		seg[pos]+=val;
		arr[idx]+=val;
	}
	else
	{
		int mid=(left+right)/2;
		if(left<=idx&&idx<=mid)
		{
			update(arr,seg,left,mid,2*pos+1,val,idx);
		}
		else
		{
			update(arr,seg,mid+1,right,2*pos+2,val,idx);
		}
		seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
	}
}
int main()
{
	int N,Q,i,l,r;
	cin>>N>>Q;
	int arr[N],seg[2*N-1];
	for(i=0;i<N;i++)
	   cin>>arr[i];
	construct_tree(arr,seg,0,N-1,0);
	while(Q--)
	{
		char x;
		cin>>x>>l>>r;
		if(x=='q')
		   cout<<query(seg,l-1,r-1,0,N-1,0)<<endl;
	    else if(x=='u')
	       update(arr,seg,0,N-1,0,r,l-1);
	}
	return 0;
}
