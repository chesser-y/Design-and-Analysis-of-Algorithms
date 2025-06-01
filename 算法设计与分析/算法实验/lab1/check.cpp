#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],ans,b[N];
double t1,t2;
clock_t start,endd;
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
void morden()
{   int ans=0;
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	{
		if(a[i]>a[j]) ans++;
	}
	return;
}
int main()
{
	int x;
	start=clock();
	srand((unsigned int)time(NULL));//ĞŞ¸ÄÖÖ×Ó
	for(int k=1;k<=1;k++)
	{
		for(size_t i=0;i<10000;i++)
	   {
		x=rand();
		int p=x%(99999)+1;
		for(int j=1;j<=10000;j++) a[j]=p;
		}
		
		devide_sort(1,10000);
	}   
	endd=clock();
	t1=((double)(endd-start))/CLK_TCK;
	printf("%lf",t1);
 } 
