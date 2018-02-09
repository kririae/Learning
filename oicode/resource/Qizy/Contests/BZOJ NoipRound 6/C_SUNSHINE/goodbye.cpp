#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long LL;
const int MS=222,MN=16,M=998244353;
typedef int Mat[MS][MS];
int n,m,A[MN],B[MN],tA[MN],tB[MN],rB[MN],P[MN];
int N;
map<vector<int>,int> I;
vector<vector<int> > C;

Mat F,X,temp;

int fpw(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=(LL)a*a%M)
		if(b&1)s=(LL)s*a%M;
	return s;
}

void mult(Mat &a,Mat &b,Mat &c)
{
	int i,j,k;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			temp[i][j]=0;
			for(k=0;k<N;k++)
				temp[i][j]=(temp[i][j]+(LL)a[i][k]*b[k][j])%M;
		}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			c[i][j]=temp[i][j];
}

void dfs(int n,int l,vector<int> s)
{
	if(n==0)
	{
		I[s]=N++;
		C.push_back(s);
		return;
	}
	for(int i=l;i<=n;i++)
	{
		s.push_back(i); 
		dfs(n-i,i,s);
		s.pop_back();
	} 
}

void to_perm(vector<int> c,int *p)
{
	int k=1;
	for(int i=0,j,l;i<c.size();i++)
	{
		l=c[i];
		for(int j=0;j<l;j++)
			p[k+j]=k+(j+1)%l;
		k+=l;
	}
}

vector<int> get_cir(int *p)
{
	bool vis[MN];
	vector<int> res;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			int l=0;
			for(int j=i;!vis[j];j=p[j])
				vis[j]=1,l++;
			res.push_back(l);
		}
	sort(res.begin(),res.end());
	return res;
}

void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",tA+i);
	for(int i=1;i<=n;i++)
		scanf("%d",tB+i),rB[tB[i]]=i;
	for(int i=1;i<=n;i++)
		A[i]=tA[rB[i]],B[i]=tB[rB[i]];
	dfs(n,1,vector<int>(0,0));
	int total=(LL)n*(n-1)*(n-2)*fpw(3,M-2)%M,pr;
	pr=fpw(total,M-2);
	X[0][0]=1;
	vector<int> cr;
	for(int a,b,c,d,t,i=1;i<N;i++)
	{
		to_perm(C[i],P);
		for(a=1;a<=n;a++)
			for(b=a+1;b<=n;b++)
				for(c=b+1;c<=n;c++)
					for(d=0;d<2;d++,swap(a,c))
					{
						t=P[a],P[a]=P[b],P[b]=P[c],P[c]=t;
						cr=get_cir(P);
						(X[i][I[cr]]+=pr)%=M;
						t=P[c],P[c]=P[b],P[b]=P[a],P[a]=t;
					}
	}
}

void work()
{
	for(int i=0;i<N;i++)
		F[i][i]=1;
	for(int b=m;b;b>>=1,mult(X,X,X))
		if(b&1)mult(F,X,F);
	int k=I[get_cir(A)];
	int ans=F[k][0];
	ans=(ans%M+M)%M;
	printf("%d\n",ans);
}

int main()
{
	freopen("goodbye.in","r",stdin);
	freopen("goodbye.out","w",stdout);
	init();
	work();
	return 0;
}

