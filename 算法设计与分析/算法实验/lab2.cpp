#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[50],b[50],c[50][50],d[50][50];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int j=1;j<=m;j++) scanf("%d",&b[j]);
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(a[i]==b[j])
		{
			for(int k=1;k<=j;k++)
			if(a[i]>=d[i-1][j-k]&&c[i][j]<=c[i-1][j-k]+1)
			c[i][j]=c[i-1][j-k]+1;
			d[i][j]=a[i];
		}
		else{
			if(c[i-1][j]>=c[i][j-1]) {c[i][j]=c[i-1][j];d[i][j]=d[i-1][j];}
			else {c[i][j]=c[i][j-1];d[i][j]=d[i][j-1];}
		}
	}
	printf("C数组******\n");
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=m;j++)
	printf("%d ",c[i][j]);
	printf("\n");
	}
	printf("d数组******\n");
		for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=m;j++)
	printf("%d ",d[i][j]);
	printf("\n");
	}
	printf("最长上升公共子序列："); 
	int l=n,r=m,maxx=d[l][r];
	while(l&&r)
	{   
		if(a[l]==b[r])
		{   if(d[l][r]<=maxx) {maxx=d[l][r];printf("%d",d[l][r]);}
			l--;
			while(d[l][r-1]>d[l][r]) l--;
			r--;
		}
		else
		{
			if(d[l][r-1]==d[l][r]) r--;
			else l--;
		}
	}
	 printf("\n序列长度%d\n",c[n][m]);
 } 
