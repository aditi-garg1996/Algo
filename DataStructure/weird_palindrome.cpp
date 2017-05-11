#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		char s[100];
		int i,j,p,q,l;
		cin>>s;
		l=strlen(s);
		for(i=0,j=l-1;i<l/2&&j>=l/2;i++,j--)
		{
			if(s[i]=='#')
			{
				if(s[j]!='#')
				{
					p=(int)s[j]-97;
					q=(char)(122-p);
					s[i]=q;
				}
				else
				{
					s[i]='a';
					s[j]='z';
				}
			}
			else if(s[j]=='#')
			{
				if(s[i]!='#')
				{
					p=(int)s[i]-97;
					q=(char)(122-p);
					s[j]=q;
				}
				else
				{
					s[i]='a';
					s[j]='z';
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
