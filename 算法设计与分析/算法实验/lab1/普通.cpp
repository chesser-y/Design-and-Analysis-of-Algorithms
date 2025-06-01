#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	{
		if(a[i]>a[j]) ans++;
	}
	printf("%d",ans);
}
