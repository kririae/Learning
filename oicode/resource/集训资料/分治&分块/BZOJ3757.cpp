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

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=50000+19,M=100000+19;

struct Edge{
	int y,nxt;
} E[N*2];
typedef int one[N];
one Last,S,blo,dfn,c,dep,vis,fa,col,son,sz,Top;
int Ans[M];
int n,Qc,cnt,top,num,tot,x,y,res,Sz;

struct QType{
	int x,y,a,b,id;
	bool operator < (const QType &B) const{
		if (blo[x]!=blo[B.x]) return blo[x]<blo[B.x];
		return dfn[y]<dfn[B.y];
	}
} Q[M];

void Link(int x,int y){
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}
void dfs(int x){
	int pre=top;
	sz[x]=1;
	dfn[x]=++tot;
	for (int i=Last[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa[x]){
			fa[y]=x;
			dep[y]=dep[x]+1;
			dfs(y);
			sz[x]+=sz[y];
			if (sz[y]>sz[son[x]]) son[x]=y;
			if (top-pre>=Sz){
				num++;
				while (top!=pre) blo[S[top--]]=num;
			}
		}
	S[++top]=x;
}
void dfs(int x,int Anc){
	Top[x]=Anc;
	if (son[x]) dfs(son[x],Anc);
	for (int i=Last[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa[x]&&y!=son[x]) dfs(y,y);
}
void Reverse(int x){
	if (vis[x]){
		if (--c[col[x]]==0) res--;
	} else{
		if (++c[col[x]]==1) res++;
	}
	vis[x]^=1;
}
void work(int x,int y){
	while (x!=y){
		if (dep[x]<dep[y]) swap(x,y);
		Reverse(x);
		x=fa[x];
	}
}
int LCA(int x,int y){
	int a=Top[x],b=Top[y];
	while (a!=b){
		if (dep[a]>dep[b]) swap(a,b),swap(x,y);
		y=fa[b],b=Top[y];
	}
	return dep[x]<dep[y]?x:y;
}

int main(){
	memset(Last,-1,sizeof(Last));
	n=IN()+1,Qc=IN();
	Sz=int(pow(n,2.0/3.0));
	For(i,2,n+1) col[i]=IN();
	For(i,1,n) Link(IN()+1,IN()+1);
	dfs(1);
	dfs(1,1);
	For(i,1,Qc+1){
		Q[i]=(QType){IN()+1,IN()+1,IN(),IN(),i};
		if (dfn[Q[i].x]>dfn[Q[i].y]) swap(Q[i].x,Q[i].y);
	}
	if (top){
		num++;
		while (top) blo[S[top--]]=num;
	}
	sort(Q+1,Q+Qc+1);
	x=2;y=2;
	For(i,1,Qc+1){
		work(x,Q[i].x);
		work(y,Q[i].y);
		x=Q[i].x;
		y=Q[i].y;
		int b=0,z=LCA(x,y);
		Reverse(z);
		if (Q[i].a!=Q[i].b){
			if (c[Q[i].a]&&c[Q[i].b]) b=1;
		}
		Ans[Q[i].id]=res-b;
		Reverse(z);
	}
	For(i,1,Qc+1) printf("%d\n",Ans[i]);
}
