#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
typedef long long ll;
const int P=998244353,g=3,MAXN=600005;
struct Int
{
	int a;
	Int(int x=0)
	{
		a=x;
	}
	int operator=(int x)
	{
		return a=x;
	}
	Int operator+(Int x)
	{
		Int tmp;
		tmp=a+x.a;
		if(tmp.a>=P)tmp.a-=P;
		return tmp;
	}
	Int operator-(Int x)
	{
		Int tmp;
		tmp=a-x.a;
		if(tmp.a<0)tmp.a+=P;
		return tmp;
	}
	Int operator*(Int x)
	{
		Int tmp;
		tmp=(ll)(a)*x.a%P;
		return tmp;
	}
	Int Pow(int x)
	{
		Int tmp,ans;
		tmp=a;
		ans=1;
		while(x)
		{
			if(x&1)ans=ans*tmp;
			tmp=tmp*tmp;
			x>>=1;
		}
		return ans;
	}
	Int inv()
	{
		return Pow(P-2);
	}
}G,w[2][MAXN],o,f[MAXN],rf[MAXN],t,t1[MAXN],t2[MAXN],a[MAXN],b[MAXN],I[MAXN];
inline void NTT(Int X[],int k,bool v)
{
    int i,j,l;
    for(i=j=0;i<k;i++)
	{
        if(i>j)swap(X[i],X[j]);
        for(l=k>>1;(j^=l)<l;l>>=1);
    }
    for(i=2;i<=k;i<<=1)for(j=0;j<k;j+=i)for(l=0;l<i>>1;l++)
	{
        t=X[j+l+(i>>1)]*w[v][(k/i)*l];
        X[j+l+(i>>1)]=X[j+l]-t;
        X[j+l]=X[j+l]+t;
    }
    if(v)for(i=0,t=k,t=t.inv();i<k;i++)X[i]=X[i]*t;
}
inline void Pre(int k)
{
    w[0][0]=w[0][k]=w[1][0]=w[1][k]=1;
    G=g;
    G=G.Pow((P-1)/k);
    int i;
    for(i=1;i<k;i++)w[0][i]=w[0][i-1]*G;
    for(i=1;i<k;i++)w[1][i]=w[0][k-i];
}
inline void Mul(Int X[],Int Y[],int k)
{
	int i;
	k<<=1;
	Pre(k);
    for(i=0;i<k>>1;i++)t1[i]=Y[i];
    for(;i<k;i++)t1[i]=0;
    NTT(X,k,0);
    NTT(t1,k,0);
    for(i=0;i<k;i++)X[i]=X[i]*t1[i];
    NTT(X,k,1);
    k>>=1;
    for(i=k;i<k<<1;i++)X[i]=0;
}
void Inv(Int X[],Int Y[],int k)
{
	if(k==1)
	{
		Y[0]=X[0].inv();
		return;
	}
	Inv(X,Y,k>>1);
	int i;
	for(i=0;i<k;i++)t2[i]=X[i];
	for(k<<=1;i<k;i++)t2[i]=0;
	Pre(k);
	NTT(t2,k,0);
	NTT(Y,k,0);
	for(i=0;i<k;i++)Y[i]=Y[i]+Y[i]-t2[i]*Y[i]*Y[i];
	NTT(Y,k,1);
	for(i=k>>1;i<k;i++)Y[i]=0;
	k>>=1;
}
int n,i,j,k,L;
int main()
{
	freopen("tournament.in","r",stdin);
	freopen("tournament.out","w",stdout);
	cin>>n;
	for(L=1;L<=n;L<<=1);
	for(i=2,I[1]=f[1]=rf[1]=f[0]=rf[0]=1;i<=L;i++)
	{
		j=P/i;
		k=P%i;
		I[i]=Int(i)*Int(j)*Int(j)*I[k]*I[k];
		f[i]=f[i-1]*Int(i);
		rf[i]=rf[i-1]*I[i];
	}
	for(a[0]=i=1;i<L;i++)a[i]=Int(2).Pow(i-1)*a[i-1]*I[i];
	Inv(a,b,L);
	for(b[0]=0,i=1;i<L;i++)b[i]=Int(0)-b[i];
	for(i=1;i<=n;i++)
	{
		scanf("%d",&j);
		b[i]=b[i]*Int(i)*Int(j);
	}
	for(;i<L;i++)b[i]=0;
	Mul(b,a,L);
	Mul(b,a,L);
	for(i=1;i<=n;i++)printf("%d\n",(Int(2).Pow((ll)i*(i-1)/2%(P-1)).inv()*b[i]*f[i-1]).a);
	return 0;
}

