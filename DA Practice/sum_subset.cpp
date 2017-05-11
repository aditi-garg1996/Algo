#include<bits/stdc++.h>
using namespace std;
int x[100];
void print(int x[],int k,int a[])
{
	int i;
	for(i=0;i<=k;i++)
	{
		if(x[i])
		  cout<<a[i]<<" ";
	}
    cout<<endl;
}
void sum_subset(int s,int k,int r,int n,int a[],int m)
{
	if(k>=n)
	   return;
	x[k]=1;
	if(s+a[k]==m)
	   print(x,k,a);
	else if(s+a[k]+a[k+1]<=m)
	   sum_subset(s+a[k],k+1,r-a[k],n,a,m);
	if((s+a[k+1]<=m)&&(s+r-a[k]>=m))
	{
	   x[k]=0;
	   sum_subset(s,k+1,r-a[k],n,a,m);
    }
}
int main()
{
	int i,n,a[1000],sum=0,m;
	cout<<"enter the number of terms:";
	cin>>n;
	cout<<"Enter the elements:";
	for(i=0;i<n;i++)
	   cin>>a[i];
	cout<<"Enter the maximum sum:";
	cin>>m;
	sort(a,a+n);
	sum=0;
	for(i=0;i<n;i++)
	   sum+=a[i];
	sum_subset(0,0,sum,n,a,m);
}
