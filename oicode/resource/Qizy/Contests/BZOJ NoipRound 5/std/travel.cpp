#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int,int> mp;
#define pb push_back
const LL inf = 1ll<<50;
const int maxn = 200005;

int n,l,s,pos[maxn];
int x[maxn],ans1[maxn];
int y[maxn],ans2[maxn];
mp ord[maxn];
bool tag[maxn];

LL solve(int n,int l,int s,int x[],int ans[]) {
	int cnt=0,tot=0;
	if (l<s) {
		for (int i=s-1;i>s-l;i--) ans[++cnt]=i;
		for (int i=1;i<=s-l;i++) if (i!=s) ans[++cnt]=i;
		for (int i=s+1;i<=n;i++) ans[++cnt]=i;
		return (LL)x[n]-x[1]+x[s]-x[1];
	}
	l-=s-1;
	if (l==n-s-1) {
		for (int i=s-1;i>=1;i--) ans[++cnt]=i;
		for (int i=n;i>s;i--) ans[++cnt]=i;
		return (LL)x[n]-x[1]+x[s]-x[1]+x[n]-x[s+1];
	}
	
	for (int i=s+1;i<n-1;i++) ord[++tot]=mp(x[i+1]-x[i],i+1);
	sort(ord+1,ord+tot+1);
	for (int i=1;i<=tot;i++) pos[ord[i].second]=i;
	LL minv=inf,sum=0;int e,j;
	for (int i=1;i<=l;i++) sum+=ord[i].first;
	minv=sum*2;e=n;j=l;
	
	for (int i=n-1,p=l;i>=n-l;i--) {
		if (pos[i]<=p) sum-=ord[pos[i]].first;
		else sum-=ord[p--].first;
		while (p&&ord[p].second>=i) --p;
		if (sum*2+x[n]-x[i]<minv) {
			minv=sum*2+x[n]-x[i];e=i;j=p;
		}
	}
	
	memset(tag,false,sizeof tag);
	for (int i=s-1;i>=1;i--) ans[++cnt]=i;
	for (int i=s+2;i<e;i++) if (pos[i]<=j) tag[i]=true;
	for (int i=s+1;i<e;i++)
	if (!tag[i+1]) ans[++cnt]=i;
	else {
		int tmp=i+1;while (tag[tmp]) ++tmp;
		for (int j=tmp-1;j>i;j--) ans[++cnt]=j;
		ans[++cnt]=i;i=tmp-1;
	}
	for (int i=n;i>=e;i--) ans[++cnt]=i;
	return (LL)x[n]-x[1]+x[s]-x[1]+minv;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
	#endif
	scanf("%d %d %d",&n,&l,&s);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<=n;i++) y[i]=-x[n-i+1];
	if (s!=1&&l==0) {puts("-1");return 0;}
	if (s!=n&&l==n-1) {puts("-1");return 0;}

	LL cost1=solve(n,l,s,x,ans1);
	LL cost2=solve(n,n-1-l,n-s+1,y,ans2);
	if (cost1<cost2) {
		printf("%lld\n",cost1);
		for (int j=1;j<n;j++)
			printf("%d ",ans1[j]);
	}
	else {
		printf("%lld\n",cost2);
		for (int j=1;j<n;j++)
			printf("%d ",n-ans2[j]+1);
	}
	return 0;
}
