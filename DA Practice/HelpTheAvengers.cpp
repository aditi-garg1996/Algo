#include<bits/stdc++.h>
using namespace std;
int check_prime(int n)
{
	int i,m;
	m=sqrt(n);
	if(n==1)
	  return 0;
	for(i=2;i<=m;i++)
	{
		if(n%i==0)
		  return 0;
	}
	return 1;
}
void construct_tree(int arr[],int seg[],int left,int right,int pos)
{
	if(left==right)
	  seg[pos]=arr[left];
	else
	{
		int mid=(left+right)/2;
		construct_tree(arr,seg,left,mid,2*pos+1);
		construct_tree(arr,seg,mid+1,right,2*pos+2);
		seg[pos]=seg[2*pos+1]+seg[2*pos+2];
	}
}
int query(int seg[],int start,int end,int left,int right,int pos)
{
	if(start<=left&&end>=right)
	  return seg[pos];
	if(end<left||start>right)
	  return 0;
	int mid=(left+right)/2;
	return (query(seg,start,end,left,mid,2*pos+1)+query(seg,start,end,mid+1,right,2*pos+2));
}
void update(int arr[],int seg[],int left,int right,int pos,int val,int idx)
{
	int k=check_prime(val);
	if(left==right)
	{
		seg[pos]=k;
		arr[idx]=k;
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
		seg[pos]=seg[2*pos+1]+seg[2*pos+2];
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--){
	int N,i,Q,l,r;
	cin>>N;
	int a[N],seg[100010];
	for(i=0;i<N;i++)
	   cin>>a[i];
	for(i=0;i<N;i++)
	   a[i]=check_prime(a[i]);
	construct_tree(a,seg,0,N-1,0);
	cin>>Q;
	while(Q--)
	{
		char x;
		cin>>x>>l>>r;
		if(x=='A')
		   cout<<query(seg,l-1,r-1,0,N-1,0)<<endl;
	    else if(x=='C')
	       update(a,seg,0,N-1,0,r,l-1);
	}
    }
	return 0;
}
