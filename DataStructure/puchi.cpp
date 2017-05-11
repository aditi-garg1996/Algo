#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	long long int arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	 int m,a,b;
	cin>>m;
	long long int arr1[n];
	memset(arr1,0,sizeof(arr1));
	while(m--)
	{
		cin>>a>>b;
		a--;
		arr1[a]=b;
	}
	for(i=1;i<n;i++)
	{
		arr[i]+=arr[i-1];
		arr1[i]+=arr1[i-1];
	}
	long long int maxi=0;
	for(i=0;i<n;i++)
	{
		cout<<arr1[i];
		maxi=max(maxi,arr1[i]-arr[i]);
	}
	cout<<maxi<<endl;
	return 0;
}
