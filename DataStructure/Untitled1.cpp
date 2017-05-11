#include<stdio.h>
void mcm(int p[],int m[][100],int s[][100],int n)
{
	int i,j,k,l,q;
	for(i=1;i<=n;i++)
	  m[i][i]=0;
    for(l=2;l<=n;l++)
    {
    	for(i=1;i<=(n-l+1);i++)
    	{
    		j=i+l-1;
    		m[i][j]=8765;
    		for(k=i;k<j;k++)
    		{
    			q=m[i][k]+m[k+1][j]+p[i]*p[k]*p[j];
    			if(q<m[i][j])
    			  m[i][j]=q;
			}
			s[i][j]=k;
		}
	}
}
print(int s[][100],int n)
{
	
}
int main()
{
	int n,i,p[100],m[100][100],s[100][100];
	printf("Enter the no of matrices:\n");
	scanf("%d",&n);
	printf("Enter the size array:");
	for(i=1;i<=n+1;i++)
	   scanf("%d",&p[i]);
	mcm(p,m,s,n);
	return 0;
}
