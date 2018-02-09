#include<bits/stdc++.h>
using namespace std;
const int maxn=11,maxm=100011;
int a[maxn][maxn],n,m,ANS=0;
int d[maxm],k[maxm],v[maxm];
void init(){
	scanf("%d%d",&n,&m); memset(a,0,sizeof(a));
	int x,y,V; scanf("%d%d%d",&x,&y,&V); a[x][y]=V;
	scanf("%d%d%d",&x,&y,&V); a[x][y]=V;
	for (int i=1;i<=m;++i) scanf("%d%d%d",d+i,k+i,v+i);
}
bool Game_over(){
	for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) if (!a[i][j]) return false;
	for (int i=1;i<n;++i) for (int j=1;j<=n;++j) if (a[i][j]==a[i+1][j]) return false;
	for (int i=1;i<=n;++i) for (int j=1;j<n;++j) if (a[i][j]==a[i][j+1]) return false;
	return true;
}
bool move(int w){
	bool b=0;
	if (w==0){
		for (int i=2;i<=n;++i) for (int j=1;j<=n;++j)
			if (a[i][j]) for (int t=i-1;t && !a[t][j];--t) b=1,swap(a[t][j],a[t+1][j]);
	}
	if (w==1){
		for (int i=n-1;i>=1;--i) for (int j=1;j<=n;++j)
			if (a[i][j]) for (int t=i+1;t<=n && !a[t][j];++t) b=1,swap(a[t][j],a[t-1][j]);
	}
	if (w==2){
		for (int j=2;j<=n;++j) for (int i=1;i<=n;++i)
			if (a[i][j]) for (int t=j-1;t && !a[i][t];--t) b=1,swap(a[i][t],a[i][t+1]);
	}
	if (w==3){
		for (int j=n-1;j>=1;--j) for (int i=1;i<=n;++i)
			if (a[i][j]) for (int t=j+1;t<=n && !a[i][t];++t) b=1,swap(a[i][t],a[i][t-1]);
	}
	return b;
}
bool merge(int w){
	bool b=0;
	if (w==0){
		for (int i=2;i<=n;++i) for (int j=1;j<=n;++j)
			if (a[i][j] && a[i-1][j]==a[i][j]) b=1,ANS+=a[i][j],a[i-1][j]<<=1,a[i][j]=0;
	}
	if (w==1){
		for (int i=n-1;i>=1;--i) for (int j=1;j<=n;++j)
			if (a[i][j] && a[i+1][j]==a[i][j]) b=1,ANS+=a[i][j],a[i+1][j]<<=1,a[i][j]=0;
	}
	if (w==2){
		for (int j=2;j<=n;++j) for (int i=1;i<=n;++i)
			if (a[i][j] && a[i][j-1]==a[i][j]) b=1,ANS+=a[i][j],a[i][j-1]<<=1,a[i][j]=0;
	}
	if (w==3){
		for (int j=n-1;j>=1;--j) for (int i=1;i<=n;++i)
			if (a[i][j] && a[i][j+1]==a[i][j]) b=1,ANS+=a[i][j],a[i][j+1]<<=1,a[i][j]=0;
	}
	return b;
}
bool gao(int w){
	bool b=0;
	if (move(w)) b=1; if (merge(w)) b=1; move(w);
	return b;
}
void grow(int k,int v){
	int N=0;
	for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) if (!a[i][j]) ++N;
	k=k%N+1;
	for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) if (!a[i][j] && !(--k)) {a[i][j]=v; return;}
}
void work(){
	for (int i=1;i<=m;++i){
		if (Game_over()) {printf("%d\n%d\n",i-1,ANS<<1); exit(0);}
		if (gao(d[i])) grow(k[i],v[i]); else {printf("%d\n%d\n",i-1,ANS<<1); exit(0);}
	}
	printf("%d\n%d\n",m,ANS<<1);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	init();
	work();
	return 0;
}
