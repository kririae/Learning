#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
const int maxn=55,maxc=35,maxv=10010;
int v[maxn],vm;
int n,m,lim,cnt;

void init(){
	scanf("%d%d",&n,&m);
	assert(n>=1 && n<=50);
	assert(m>=1 && m<=100000);
	for(int i=1;i<=n;++i)
		scanf("%d",v+i),assert(v[i]>=1 && v[i]<=10000);
	scanf("%d%d",&lim,&cnt);
	assert(lim>=0 && lim<=20000);
	assert(cnt>=0 && cnt<=30);
	sort(v+1,v+n+1),vm=v[1];
}

namespace process1{
	bitset<maxc*maxv> f[maxc];
	void solve(){
		assert(vm>=lim);
		for(int i=0;i<=cnt;++i)
			f[i].reset(),f[i].set(0);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=cnt;++j)
				f[j]|=(f[j-1]<<v[i]);
		for(int i=1;i<=m;++i){
			int64 W; scanf("%lld",&W);
			if(W>v[n]*cnt || !f[cnt].test(W))
				puts("No");
			else puts("Yes"); 
		}
	}
}

bool debug=false;

namespace process2{
	struct Tedge{
		int son; int64 dis; Tedge *pre;
		void add(int s_,int64 d_,Tedge *p_){
			son=s_,dis=d_,pre=p_;
		}
	}edge[maxv<<1],*pos[maxv];
	int tot;
	void add(int a,int b,int64 c){
		edge[++tot].add(b,c,pos[a]),pos[a]=edge+tot;	
	}
	void clear(){ tot=0,memset(pos,0,sizeof(pos)); }
	
	int q[maxv]; bool vis[maxv];
	void spfa(int64 dis[]){
		memset(vis,false,sizeof(vis));
		memset(dis,63,sizeof(*dis)*maxv);
		int head=0,tail=1; q[1]=vm,dis[vm]=0;
		while(head!=tail){
			++head; if(head>=maxv) head=1;
			int x=q[head]; vis[x]=false;
			for(Tedge *i=pos[x];i;i=i->pre)
				if(dis[i->son]>dis[x]+i->dis){
					dis[i->son]=dis[x]+i->dis;
					if(!vis[i->son]){
						++tail; if(tail>=maxv) tail=1;
						q[tail]=i->son,vis[i->son]=true;
					}
				}
		}
	}
	
	
	int64 f[maxc][maxv];
	void solve(){
		assert(vm<lim);
		memset(f,63,sizeof(f));
		for(int i=0;i<=cnt;++i)
			f[i][0]=0;
		for(int i=2;i<=n;++i)
			if(v[i]>=lim){
				for(int j=1;j<=cnt;++j){
					for(int k=0;k<vm;++k)
						f[j][k]=min(f[j][k],f[j-1][(k+vm-v[i]%vm)%vm]+v[i]);
/*					for(int k=0;k<vm;++k)
						printf("f[%d][%d][%d]=%lld\n",i,j,k,f[j][k]);
					cout<<endl;*/
				}
			}
			else{
				for(int j=0;j<=cnt;++j){
					clear();
					for(int k=0;k<vm;++k){
						add(vm,k,f[j][k]),add(k,(k+v[i])%vm,v[i]);
					}
					spfa(f[j]);
					if(i==5 && j==cnt) debug=false;
/*					for(int k=0;k<vm;++k)
						printf("f[%d][%d][%d]=%lld\n",i,j,k,f[j][k]);
					cout<<endl;*/
				}
			}
		for(int i=1;i<=m;++i){
			int64 W; scanf("%lld",&W);
			assert(W<=1000000000000000000LL);
			if(f[cnt][W%vm]<=W)
				puts("Yes");
			else puts("No");
		}
	}
}

int main(){
	freopen("bag.in","r",stdin);
	freopen("bag.out","w",stdout);
	init();
	if(vm>=lim)
		process1::solve();
	else process2::solve();
	return 0;
}
