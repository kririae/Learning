#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010,maxd=160;
int a[maxn],A,B,C,D,n,ans;

struct Tbinary_index_tree{
	int t[maxd];
	void clear(){ memset(t,0,sizeof(t)); }
	void insert(int x,int v){
		for(int i=++x;i<maxd;i+=i&-i)
			t[i]=max(t[i],v);
	}
	int query(int x){
		int res=0; ++x;
		for(int i=x;i;i-=i&-i)
			res=max(res,t[i]);
		return res;
	}
}bit;
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d%d",&n,&a[1]);
	scanf("%d%d%d%d",&A,&B,&C,&D);
	for(int i=2;i<=n;++i)
		a[i]=(A*a[i-1]*a[i-1]+B*a[i-1]+C)%D;
	bit.clear(); int ans=0;
	for(int i=1;i<=n;++i){
		int f=bit.query(a[i])+1;
		ans=max(ans,f),bit.insert(a[i],f);
	}
	printf("%d\n",ans);
	return 0;
}
