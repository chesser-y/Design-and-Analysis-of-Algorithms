#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int ans=1;
int n,s[N],f[N],d[N];
void dfs(int x,int num,int final)
{
	if(x==n) {ans=max(ans,num);return;}
	if(num+(n-x)<ans) return;//�������ȫѡҲ�����������ֵ
	if(s[x+1]>final) dfs(x+1,num+1,f[x+1]);//ѡ 
	dfs(x+1,num,final); //��ѡ 
}
int main()
{

	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&s[i],&f[i]);
	//̰�� 
	sort(f+1,f+1+n);
	int ans1=1;
	for(int i=2;i<=n;i++)
	if(f[i-1]<s[i]) ans1++;
	printf("%d",ans1);
	//��̬�滮
	sort(f+1,f+1+n);
	for(int i=1;i<=n;i++)
	{
		d[f[i]]=max(d[f[i]],d[s[i]-1]+1);
		for(int j=f[i];j<=f[n];j++)
		if(d[j]<d[f[i]]) d[j]=d[f[i]];
	}
	printf("%d",d[f[n]]);
	//������
	sort(f+1,f+1+n);
    dfs(1,1,f[1]);
    printf("%d",ans);
}
