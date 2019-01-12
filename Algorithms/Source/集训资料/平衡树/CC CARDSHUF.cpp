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
#define lf else if
#define Mid ((L+R)>>1)

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

const int N=100000+19;

int R(int l,int r){
	return rand()%(r-l+1)+l;
}

struct node *null;
struct node{
	node *L,*R;
	int val,rev,sz;
	void Update(){
		if (this!=null) sz=L->sz+R->sz+1;
	}
	void Reverse(){
		rev^=1,swap(L,R);
	}
	void Down(){
		if (rev){
			L->Reverse();
			R->Reverse();
			rev=0;
		}
	}
} Nd[N],*rt;
typedef pair<node*,node*> pnn;

node *Merge(node *A,node *B){
	if (A==null) return B;
	if (B==null) return A;
	A->Down();
	B->Down();
	if (R(1,A->sz+B->sz)<=A->sz){
		A->R=Merge(A->R,B);
		A->Update();
		return A;
	} else{
		B->L=Merge(A,B->L);
		B->Update();
		return B;
	}
}
pnn Split(node *A,int k){
	k=min(k,A->sz);
	if (A==null) return mp(null,null);
	A->Down();
	pnn res;
	if (k<=A->L->sz){
		res=Split(A->L,k);
		A->L=res.se;
		res.se=A;
		A->Update();
	} else{
		res=Split(A->R,k-A->L->sz-1);
		A->R=res.fi;
		res.fi=A;
		A->Update();
	}
	return res;
}
node *Build(int L,int R){
	if (L>R) return null;
	node *x=Nd+Mid;
	x->val=Mid;
	x->L=Build(L,Mid-1);
	x->R=Build(Mid+1,R);
	x->Update();
	return x;
}
void dfs(node *x){
	if (x==null) return;
	x->Down();
	dfs(x->L);
	printf("%d ",x->val);
	dfs(x->R);
}

int n,q,A,B,C;

int main(){
	null=Nd;
	*null=(node){null,null,0,0,0};
	n=IN(),q=IN();
	rt=Build(1,n);
	while (q--){
		A=IN(),B=IN(),C=IN();
		pnn S=Split(rt,A),T=Split(S.se,B);
		rt=Merge(S.fi,T.se);
		pnn U=Split(rt,C);
		T.fi->Reverse();
		rt=Merge(Merge(U.fi,T.fi),U.se);
	}
	dfs(rt);
	puts("");
}
