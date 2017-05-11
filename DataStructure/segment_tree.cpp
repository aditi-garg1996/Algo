#include<bits/stdc++.h>
using namespace std;
void construct_tree(int input[],int segtree[],int low,int high,int pos)
{
	if(low==high){
	   segtree[pos]=input[low];
	   return;
    }
    int mid=(low+high)/2;
    construct_tree(input,segtree,low,mid,2*pos+1);
    construct_tree(input,segtree,mid+1,high,2*pos+2);
    segtree[pos]=min(segtree[2*pos+1],segtree[2*pos+2]);
}
int range_query(int segtree[],int qlow,int qhigh,int low,int high,int pos)
{
	if(qlow<=low&&qhigh>=high)
	   return segtree[pos];
	if(qlow>high||qhigh<low)
	   return INT_MAX;
	int mid=(low+high)/2;
	return min(range_query(segtree,qlow,qhigh,low,mid,2*pos+1),
	range_query(segtree,qlow,qhigh,mid+1,high,2*pos+2));
}
int main(){
	int n,qlow,qhigh,r;
	cin>>n;
	int input[n],segtree[2*n-1];
	for(int i=0;i<n;i++)
	  cin>>input[i];
	memset(segtree,INT_MAX,sizeof(segtree));
	construct_tree(input,segtree,0,n-1,0);
	cin>>r;
	while(r--)
	{
		cin>>qlow>>qhigh;
		cout<<range_query(segtree,qlow,qhigh,0,n-1,0)<<endl;
	 } 
}
