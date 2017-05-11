#include<bits/stdc++.h>
using namespace std;
typedef struct node{
	string s;
	int time;
}node;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,i,k;
		vector<node>a;
		scanf("%d",&N);
		node b[N];
		int c[N];
		for(i=0;i<N;i++)
		{
			cin>>b[i].s;
		}
		for(i=0;i<N;i++)
			scanf("%d",&(b[i].time));
		for(i=0;i<N;i++)
			a.push_back(b[i]);
		for(i=0;i<N-1;i++)
		  scanf("%d",&c[i]);
		int maxi=0;
		for(i=0;i<N-1;i++)
		{
			k=c[i]-1;
			if(i==0)
			  maxi=a[k].time;
			else
			  maxi=max(maxi,a[k].time);
		    cout<<a[k].s;
			printf(" %d\n",maxi);
			a.erase(a.begin()+k);
		}
		  maxi=max(maxi,a[0].time);
		    cout<<a[0].s;
			printf(" %d\n",maxi);
	}
	return 0;
}
