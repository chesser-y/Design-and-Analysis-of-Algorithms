#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,ans=0,a[N],b[N];
void merge(int l,int mid,int r)
{   int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r)
	{
		if(a[i]<=a[j]) {
			b[k++]=a[i++];
		}
		else{
		ans+=mid-i+1;
		b[k++]=a[j++];
		}
	}
	while(i<=mid) b[k++]=a[i++];
	while(j<=r) b[k++]=a[j++];
	for(int i=l;i<=r;i++)
	a[i]=b[i];
}
void devide_sort(int l,int r)
{
	if(l==r) return;
	int mid=l+r>>1;
	devide_sort(l,mid);
	devide_sort(mid+1,r);
	merge(l,mid,r);
}
int main()
{ 
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	devide_sort(1,n);
	printf("%d",ans);
 } 
