#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int n,m,i,j,k,a[MAXN],b[MAXN],c[MAXN],px[26],py[26],s[26],f[26],ans,ans1[26],ans2[26];
bool B[26];
int get(int x)
{
	if(f[x]==x)return x;
	int r=get(f[x]);
	s[x]=(s[x]+s[f[x]])%m;
	return f[x]=r;
}
int main()
{
	freopen("password.in","r",stdin);
	freopen("password.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%d",a+i);
	for(i=0;i<n;i++)scanf("%d",b+i);
	memset(px,-1,sizeof(px));
	for(i=0;i<m;i++)f[i]=i;
	for(i=0;i<n;i++)
	{
		a[i]=(a[i]+i)%m;
		if(~px[b[i]])
		{
			j=get(px[b[i]]);
			k=get(a[i]);
			if(j==k)continue;
			f[j]=k;
			s[j]=(-s[px[b[i]]]-py[b[i]]+i/m%m+s[a[i]]+(m<<1))%m;
		}
		else
		{
			px[b[i]]=a[i];
			py[b[i]]=i/m%m;
		}
	}
	for(i=0;i<m;i++)if(!B[get(i)])
	{
		B[get(i)]=1;
		ans++;
	}
	for(i=0;i<m;i++)ans1[i]=s[i];
	for(i=0;i<n;i++)
	{
		c[i]=(ans1[a[i]]+i/m)%m;
		ans2[c[i]]=b[i];
	}
	for(i=0;i<m;i++)cout<<ans1[i]<<' ';
	cout<<endl;
	for(i=0;i<m;i++)cout<<ans2[i]<<' ';
	cout<<endl;
	return 0;
}

