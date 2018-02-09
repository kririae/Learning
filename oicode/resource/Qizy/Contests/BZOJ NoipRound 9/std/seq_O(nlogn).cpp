#include<bits/stdc++.h>
using namespace std;
const int maxn=100011;
int n,a[maxn],A[maxn];
void init(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",A+i);
}
struct Tbit{
	long long t[maxn];
	void ins(int x,long long a){for (;x<=n;x+=x&-x) t[x]=max(t[x],a);}
	long long Query(int x){
		long long res=0;
		for (;x;x-=x&(-x)) res=max(res,t[x]);
		return res;
	}
	void clear(){memset(t,0,sizeof(t));}
}t;
inline bool cmp_A(int a,int b){return A[a]<A[b];}
void preset(){
	static int w[maxn]; for (int i=1;i<=n;++i) w[i]=i;
	sort(w+1,w+n+1,cmp_A); int i;
	for (a[w[1]]=1,i=2;i<=n;++i) a[w[i]]=A[w[i]]==A[w[i-1]]?a[w[i-1]]:a[w[i-1]]+1;
//	for (int i=1;i<=n;++i) cout<<a[i]<<' '; cout<<endl;
}
void work(){
	preset(); t.clear(); static long long f[maxn];
	for (int i=1;i<=n;++i) f[i]=t.Query(a[i]-1)+A[i],t.ins(a[i]	,f[i]);
	long long ans=0; for (int i=1;i<=n;++i) ans=max(ans,f[i]); ans*=2;
	t.clear(); long long x;
	for (int i=n;i>=1;--i)
		x=t.Query(a[i]-1)+A[i],ans=max(ans,f[i]+x-A[i]),t.ins(a[i],x);
	printf("%.3f\n",ans/2.0);
}
int main(){
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	init();
	work();
	return 0;
}
