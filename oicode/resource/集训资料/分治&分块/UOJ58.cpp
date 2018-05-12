#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fir first
#define sec second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

const int len=200000;
inline char nc(){
	static char buf[len],*b=buf+len;
	if (b==buf+len) fread(buf,1,len,stdin),b=buf;
	return *b++;
}
int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=100000+19;

struct Edge{
	int y,nxt;
} E[N*2];
typedef int one[N];
one Last,v,w,dep,top,fa,sz,son,S,blo,pre,col,vis,c,A;
int n,m,Qc,Mc,cnt,Top,B,num,x,y,T,tot,id;
ll Ans[N],res;

struct QType{
	int o,T,x,y;
	bool operator < (const QType &B) const{
		if (blo[x]!=blo[B.x]) return blo[x]<blo[B.x];
		if (blo[y]!=blo[B.y]) return blo[y]<blo[B.y];
		return T<B.T;
	}
} Q[N],q[N],tmp;

void Link(int x,int y){
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}
void dfs(int x){
	int pre=Top;
	sz[x]=1;
	for (int i=Last[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa[x]){
			dep[y]=dep[x]+1;
			fa[y]=x;
			dfs(y);
			sz[x]+=sz[y];
			if (sz[y]>sz[son[x]]) son[x]=y;
			if (Top-pre>B){
				num++;
				while (Top!=pre) blo[S[Top--]]=num;
			}
		}
	S[++Top]=x;
}
void dfs(int x,int Anc){
	top[x]=Anc;
	if (son[x]) dfs(son[x],Anc);
	for (int i=Last[x],y;~i;i=E[i].nxt){
		if ((y=E[i].y)!=fa[x]&&y!=son[x]) dfs(y,y);
	}
}
int LCA(int x,int y){
	int a=top[x],b=top[y];
	while (a!=b){
		if (dep[a]>dep[b]) swap(a,b),swap(x,y);
		y=fa[b],b=top[y];
	}
	return dep[x]<dep[y]?x:y;
}
void Reverse(int x){
	if (!vis[x]){
		res+=1ll*v[A[x]]*w[++c[A[x]]];
		vis[x]=1;
	} else{
		res-=1ll*v[A[x]]*w[c[A[x]]--];
		vis[x]=0;
	}
}
void work(int x,int y){
	while (x!=y){
		if (dep[x]>dep[y]) swap(x,y);
		Reverse(y),y=fa[y];
	}
}
void Modify(int x,int y){
	if (!vis[x]) A[x]=y;else{
		res-=1ll*v[A[x]]*w[c[A[x]]--];
		A[x]=y;
		res+=1ll*v[A[x]]*w[++c[A[x]]];
	}
}

int main(){
	memset(Ans,-1,sizeof(Ans));
	memset(Last,-1,sizeof(Last));
	n=IN(),m=IN(),Qc=IN();
	B=int(pow(n,2.0/3.0));
	For(i,1,m+1) v[i]=IN();
	For(i,1,n+1) w[i]=IN();
	For(i,1,n) Link(IN(),IN());
	For(i,1,n+1) A[i]=col[i]=IN();
	dfs(1);
	dfs(1,1);
	num++;
	while (Top) blo[S[Top--]]=num;
	For(i,1,Qc+1){
		tmp=(QType){IN(),i,IN(),IN()};
		if (tmp.o==1){
			if (blo[tmp.x]>blo[tmp.y]) swap(tmp.x,tmp.y);
			Q[++id]=tmp;
		}
		if (tmp.o==0){
			tot++;
			pre[tot]=col[tmp.x];
			col[tmp.x]=tmp.y;
			q[tot]=tmp;
		}
	}
	q[0].T=0;
	q[tot+1].T=Qc+1;
	sort(Q+1,Q+id+1);
	x=1,y=1;T=0;
	For(i,1,id+1){
		work(x,Q[i].x);
		work(y,Q[i].y);
		x=Q[i].x;
		y=Q[i].y;
		while (q[T+1].T<=Q[i].T) T++,Modify(q[T].x,q[T].y);
		while (q[T].T>Q[i].T) Modify(q[T].x,pre[T]),T--;
		int z=LCA(x,y);
		res+=1ll*v[A[z]]*w[++c[A[z]]];
		Ans[Q[i].T]=res;
		res-=1ll*v[A[z]]*w[c[A[z]]--];
	}
	For(i,1,Qc+1){
		if (~Ans[i]) printf("%lld\n",Ans[i]);
	}
}
