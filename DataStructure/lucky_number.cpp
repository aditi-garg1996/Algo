#include<iostream>
using namespace std;
int main()
{
		int n,a[100],k,sum=0,i;
		cin>>n;
		while(n)
		{
			a[k++]=n;
			n=n/10;
		}
		for(i=0;i<k;i++)
		{
			if(a[i]%72==0)
			{
				sum=(sum+a[i])%(1000000007);
			}
		}
		cout<<sum;
}
