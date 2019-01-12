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
#define fi first
#define se second
#define Mid (L+R>>1)

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=400000+19;

struct Edge{
	int y,nxt;
} E[N*2];
int las[N];
int n,cnt,tot,o,x;
ll ans;

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}

struct node *null;
struct node{
	node *L,*R,*Fa;
	int sz,s;
	ll key,sum,plu;
	void Update(){
		if (this==null) return;
		sz=L->sz+R->sz+s;
		sum=L->sum+R->sum+key;
	}
	void Plus(ll v){
		if (this==null) return;
		plu+=v;
		if (s) key+=v;
		sum+=v*sz;
	}
	void Down(){
		if (this==null) return;
		if (plu){
			L->Plus(plu);
			R->Plus(plu);
			plu=0;
		}
	}
	void Zig(){
		node *y=Fa,*z=y->Fa;
		if (y==z->L) z->L=this;else if (y==z->R) z->R=this;Fa=z;
		y->L=R;if (R!=null) R->Fa=y;
		R=y;y->Fa=this;y->Update();
	}
	void Zag(){
		node *y=Fa,*z=y->Fa;
		if (y==z->L) z->L=this;else if (y==z->R) z->R=this;Fa=z;
		y->R=L;if (L!=null) L->Fa=y;
		L=y;y->Fa=this;y->Update();
	}
} Nd[N],*I[N],*O[N],*A[N],*cur=Nd+1,*rt,*tmp;

node *New(ll val,int s){
	return *cur=(node){null,null,null,s,s,val,val,0},cur++;
}
void Splay(node *x,node *Aim){
	static node *S[N];
	node *tmp=x;int k=0;
	while (tmp->Fa!=Aim) S[++k]=tmp,tmp=tmp->Fa;S[++k]=tmp;
	while (k) S[k--]->Down();
	while (x->Fa!=Aim){
		node *y=x->Fa,*z=y->Fa;
		if (y->Fa!=Aim){
			if (x==y->L) if (y==z->L) y->Zig(),x->Zig();else x->Zig(),x->Zag();
				else if (y==z->L) x->Zag(),x->Zig();else y->Zag(),x->Zag();
		} else{
			if (x==y->L) x->Zig();else x->Zag();
		}
	}
	x->Update();
	if (Aim==null) rt=x;
}
void dfs(int x,int fa){
	A[++tot]=I[x];
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			dfs(y,x);
		}
	A[++tot]=O[x];
}
node *Build(int L,int R){
	if (L>R) return null;
	node *x=A[Mid];
	x->L=Build(L,Mid-1);
	if (x->L!=null) x->L->Fa=x;
	x->R=Build(Mid+1,R);
	if (x->R!=null) x->R->Fa=x;
	x->Update();
	return x;
}
node *pre(node *x){
	Splay(x,null);
	if (x->L==null) return null;
	for (x=x->L,x->Down();x->R!=null;) x=x->R,x->Down();
	return x;
}

int main(){
	null=Nd;
	*null=(node){null,null,null,0,0,0,0};
	n=IN();
	For(i,1,n+1){
		I[i]=New(IN(),1);
		O[i]=New(0,0);
	}
	memset(las,-1,sizeof(las));
	For(i,1,n) Link(IN()+1,IN()+1);
	dfs(1,-1);
	rt=Build(1,tot);
	rt->Fa=null;
	for (int Qc=IN();Qc--;){
		o=IN();x=IN()+1+ans;
		if (o==1){
			n++;
			I[n]=New(IN(),1);
			O[n]=New(0,0);
			I[n]->R=O[n];
			O[n]->Fa=I[n];
			Splay(O[x],null);
			tmp=O[x]->L;
			O[x]->L=I[n];
			I[n]->Fa=O[x];
			I[n]->L=tmp;
			if (tmp!=null) tmp->Fa=I[n];
			I[n]->Update();
			O[x]->Update();
		}
		if (o==2){
			if (pre(I[x])==null){
				Splay(O[x],null);
				rt->L->Plus(IN());
				rt->Update();
			} else{
				Splay(pre(I[x]),null);
				Splay(O[x],rt);
				rt->R->L->Plus(IN());
				rt->R->Update();
				rt->Update();
			}
		}
		if (o==3){
			Splay(pre(I[x]),null);
			Splay(O[x],rt);
			rt->R->L=null;
			rt->R->Update();
			rt->Update();
		}
		if (o==4){
			if (pre(I[x])==null){
				Splay(O[x],null);
				printf("%lld\n",ans=rt->L->sum);
			} else{
				Splay(pre(I[x]),null);
				Splay(O[x],rt);
				printf("%lld\n",ans=rt->R->L->sum);
			}
		}
	}
}
