#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n;
double ans; 
double x[N],y[N],k[N],d[N][N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf",&x[i]);
	for(int j=1;j<=n;j++) scanf("%lf",&y[j]);
	
	for(int i=1;i<=n;i++) //初始化 
	k[i]=y[i]-x[i];

	for(int i=1;i<=n;i++)//遍历对角线元素 
	{
	    double t=k[i]-(d[i][i-1]-d[i-1][i]);
	    if(t<0) d[i+1][i]=(-1)*t;
	    else d[i][i+1]=t;
	    if(t<0) t=t*(-1);
	    ans+=t;
	}
	printf("%lf",ans);
}
