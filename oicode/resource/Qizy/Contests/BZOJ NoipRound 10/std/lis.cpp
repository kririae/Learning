#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
const int maxn=1010,maxd=160;
int a[maxd],b[maxd<<1],c[maxd],pos[maxd];
int m; int64 st,ed,n;

void brute_force(){
	int f[maxn]={0,1},q[maxn],ans=1;
	int A,B,C,D; scanf("%d",q+1);
	scanf("%d%d%d%d",&A,&B,&C,&D);
	for(int i=2;i<=n;++i){
		q[i]=(A*q[i-1]*q[i-1]+B*q[i-1]+C)%D,f[i]=0;
		for(int j=1;j<i;++j)
			if(q[j]<=q[i]) f[i]=max(f[i],f[j]);
		ans=max(ans,++f[i]);
	}
	printf("%d\n",ans);
}

void init(){
	int A,B,C,D; scanf("%d",a+1);
	scanf("%d%d%d%d",&A,&B,&C,&D);
	assert(a[1]>=0 && a[1]<=150);
	assert(A>=0 && A<=150);
	assert(B>=0 && B<=150);
	assert(C>=0 && C<=150);
	assert(D>=1 && D<=150);
	memset(pos,-1,sizeof(pos)),pos[a[1]]=1;
	for(int i=2;;++i){
		a[i]=(A*a[i-1]*a[i-1]+B*a[i-1]+C)%D;
		if(pos[a[i]]!=-1){ st=i,m=i-pos[a[i]]; break; }
		pos[a[i]]=i;
	}
	ed=n-(n-st+1)%m,b[1]=c[1]=a[st];
	for(int i=2;i<=(m<<1);++i)
		b[i]=(A*b[i-1]*b[i-1]+B*b[i-1]+C)%D;
	for(int i=2;i<=n-ed;++i)
		c[i]=(A*c[i-1]*c[i-1]+B*c[i-1]+C)%D;
	assert((ed-st+1)%m==0);
	assert(st>=1 && ed<=n);
	assert((ed-st+1)/m>=2);
/*	printf("T=%d [%lld,%lld]\n",m,st,ed);
	cout<<"a: "; for(int i=1;i<st;++i) cout<<a[i]<<' '; cout<<endl;
	cout<<"b: "; for(int i=1;i<=(m<<1);++i) cout<<b[i]<<' '; cout<<endl;
	cout<<"c: "; for(int i=1;i<=n-ed;++i) cout<<c[i]<<' '; cout<<endl;*/
}

struct matrix{
	int64 mat[maxd][maxd];
	void clear(){ memset(mat,-1,sizeof(mat)); }
}G,I;
matrix& operator*=(matrix &res,matrix b){
	matrix a=res; res.clear();
	for(int i=1;i<=m;++i)
		for(int j=1;j<=m;++j)if(a.mat[i][j]!=-1)
			for(int k=1;k<=m;++k)if(b.mat[j][k]!=-1)
				res.mat[i][k]=max(res.mat[i][k],a.mat[i][j]+b.mat[j][k]);
	return res;
}
matrix mypow(matrix a,int64 n){
	matrix res=I;
	for(int64 i=n;i;i>>=1,a*=a)
		if(i&1) res*=a;
	return res;
}

int lf[maxd],rf[maxd],f[maxd<<1];
void dp(){
	G.clear(),I.clear();
	for(int i=1;i<=m;++i) I.mat[i][i]=0;
	memset(lf,0,sizeof(lf));
	memset(f,0,sizeof(f));
	for(int i=1;i<st;++i){
		for(int j=1;j<i;++j)
			if(a[j]<=a[i]) f[i]=max(f[i],f[j]);
		lf[a[i]]=max(lf[a[i]],++f[i]);
	}
	for(int i=1;i<maxd;++i)
		lf[i]=max(lf[i],lf[i-1]);
	memset(rf,0,sizeof(rf));
	memset(f,0,sizeof(f));
	for(int i=n-ed;i>=1;--i){
		for(int j=n-ed;j>i;--j)
			if(c[j]>=c[i]) f[i]=max(f[i],f[j]);
		rf[c[i]]=max(rf[c[i]],++f[i]);
	}
	for(int i=maxd-2;i>=0;--i)
		rf[i]=max(rf[i],rf[i+1]);
	for(int k=1;k<=m;++k){
		memset(f,-1,sizeof(f)),f[k]=0;
		for(int i=k+1;i<=(m<<1);++i){
			if(b[i]<b[k]) continue;
			for(int j=k;j<i;++j)
				if(b[j]<=b[i]) f[i]=max(f[i],f[j]+1);
		}
		for(int i=m+1;i<=(m<<1);++i)
			G.mat[k][i-m]=f[i];
	}
}

void solve(){
	G=mypow(G,(ed-st+1)/m-1); int64 ans=0;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=m;++j)
			ans=max(ans,lf[b[i]]+1+G.mat[i][j]+rf[b[j]]);
	printf("%lld\n",ans);
}

int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%lld",&n);
	if(n<=800)
		brute_force();
	else init(),dp(),solve();
	return 0;
}
