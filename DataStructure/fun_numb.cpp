#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	if(a==b)
	return a;
	else if(a>b)
	return gcd(a-b,b);
	else if(b>a)
	return gcd(a,b-a);
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a,b,count=0,k;
		cin>>a>>b;
		if(a==1&&b==1)
		  cout<<"0"<<endl;
		else{
			while(a!=1||b!=1)
			{
				count++;
				k=gcd(a,b);
				if(k==1)
				{
					if(a%2!=0&&b%2==0)
					{
						if(a==1)
						   b-=1;
						else if(a>b)
						   a-=1;
						else
						   b-=1;
					}
					else if(a%2==0&&b%2!=0)
					{
						if(b==1)
						   a-=1;
						else if(b>a)
						   b-=1;
						else
						   a-=1;
					}
					else
					{
						if(a==1)
						   b-=1;
						else if(b==1)
						   a-=1;
						else if(a>b)
						   a-=1;
						else
						   b-=1;
					}
				}
				else
				{
					a=a/k;
					b=b/k;
				}
			}
		}
		cout<<count<<endl;
	}
}
