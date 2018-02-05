#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
const int maxn=50010,maxd=160;
int a[maxn],b[maxn],pos[maxd];
int A,B,C,D,m; int64 st,ed,n;

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
void brute_force(){
	scanf("%d%d%d%d%d",a+1,&A,&B,&C,&D);
	bit.clear(),bit.insert(a[1],1); int ans=1;
	for(int i=2;i<=n;++i){
		a[i]=(A*a[i-1]*a[i-1]+B*a[i-1]+C)%D;
		int f=bit.query(a[i])+1;
		bit.insert(a[i],f),ans=max(ans,f);
	}
	printf("%d\n",ans);
}

void init(){
	scanf("%d%d%d%d%d",a+1,&A,&B,&C,&D);
	memset(pos,-1,sizeof(pos)),pos[a[1]]=1;
	for(int i=2;;++i){
		a[i]=(A*a[i-1]*a[i-1]+B*a[i-1]+C)%D;
		if(pos[a[i]]!=-1){ st=i,m=i-pos[a[i]]; break; }
		pos[a[i]]=i;
	}
	ed=n-(n-st+1)%m;
	for(int i=st;i<=st+m*m-1;++i)
		a[i]=(A*a[i-1]*a[i-1]+B*a[i-1]+C)%D;
	b[1]=a[st];
	for(int i=2;i<=n-ed+m*m;++i)
		b[i]=(A*b[i-1]*b[i-1]+B*b[i-1]+C)%D;
	st+=m*m,ed-=m*m; assert(st<ed);
}

int lf[maxd],rf[maxd],f[maxn];
void solve(){
	memset(lf,0,sizeof(lf));
	memset(f,0,sizeof(f)),bit.clear();
	for(int i=1;i<st;++i){
		f[i]=bit.query(a[i])+1;
		bit.insert(a[i],f[i]);
		lf[a[i]]=max(lf[a[i]],f[i]);
	}
	for(int i=1;i<maxd;++i)
		lf[i]=max(lf[i],lf[i-1]);
	memset(f,0,sizeof(f)),bit.clear();
	for(int i=n-ed;i>=1;--i){
		f[i]=bit.query(maxd-b[i]-2)+1;
		bit.insert(maxd-b[i]-2,f[i]);
		rf[b[i]]=max(rf[b[i]],f[i]);
	}
	for(int i=maxd-2;i>=0;--i)
		rf[i]=max(rf[i],rf[i+1]);
	int64 ans=0;
	for(int i=1;i<=m;++i){
		int v=a[st-m*m+i-1];
		ans=max(ans,lf[v]+(ed-st+1)/m+rf[v]);
	}
	printf("%lld\n",ans);
}

int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%lld",&n);
	if(n<=50000)
		brute_force();
	else init(),solve();
	return 0;
}
