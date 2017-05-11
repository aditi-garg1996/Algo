#include<stdio.h>
#include<string.h>
typedef struct node{
	int val;
	char ch;
}node;
void lcs(node c[100][100],char a[],char b[])
{
	int i,j,n,m;
	n=strlen(a)-1;
	m=strlen(b)-1;
	for(i=0;i<=m;i++)
	{
		c[i][0].val=0;
	}
	for(i=0;i<=n;i++)
	{
		c[0][i].val=0;
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(b[i]==a[j])
			{
				c[i][j].val=c[i-1][j-1].val+1;
				c[i][j].ch=';';
			}
			else
			{
				if((c[i-1][j].val)>=(c[i][j-1].val))
				{
					c[i][j].val=c[i-1][j].val;
				    c[i][j].ch='|';
				}
				else
				{
					c[i][j].val=c[i][j-1].val;
			    	c[i][j].ch='-';
				}
			}
		}
	}
}
void print_lcs(node c[100][100],int n,int m,char a[100])
{
	int i,j,k;
	char d[100];
	i=m;
	j=n;
	k=1;
	while((i!=0)&&(j!=0))
	{
		if((c[i][j].ch)==';')
		{
			d[k++]=a[j];
			i=i-1;
			j=j-1;
		}
		else if((c[i][j].ch)=='-')
	    {
	    	j=j-1;
		}
		else
		{
			i=i-1;
		}
	}
	for(i=k-1;i>=1;i--)
	  printf("%c",d[i]);
}
int main()
{
	int n,m,i;
	char e[100],f[100],a[100],b[100];
	node c[100][100];
	printf("Enter the first string:");
	gets(e);
	for(i=0;a[i]!='\0';i++)
	   a[i+1]=e[i];
	printf("Enter the second string:");
	gets(f);
	for(i=0;a[i]!='\0';i++)
	   b[i+1]=f[i];
	lcs(c,a,b);
	print_lcs(c,strlen(a)-1,strlen(b)-1,a);
}
