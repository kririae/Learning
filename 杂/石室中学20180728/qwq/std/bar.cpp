#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define LL long long

int n,m,c,ans;
int num[105];

struct Matrix{
	int x[55][55];
	Matrix operator * (const Matrix &b) const {
        Matrix ret;
		memset(ret.x,0,sizeof(ret.x));
        for(int i=0;i<c;i++) 
            for(int j=0;j<c;j++)
                for(int k=0;k<c;k++) 
                    ret.x[i][k]=(ret.x[i][k]+(LL) x[i][j]*b.x[j][k])%MOD;
        return ret;
    }
}pw[35],st;
int now[55],t[55];

void Merge(int k) {
	memset(t,0,sizeof(t));
	for(int i=0;i<c;i++) 
		for(int j=0;j<c;j++) 
			t[i]=(t[i]+(LL) now[j]*pw[k].x[i][j])%MOD;
	for(int i=0;i<c;i++) now[i]=t[i];
}

int fpow(int a,int b) {
	LL t=a,ret=1;
	while(b) {
		if(b&1) ret=ret*t%MOD;
		b>>=1;t=t*t%MOD;
	}
	return ret;
}

int main() {
	
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	 
	scanf("%d%d%d",&n,&m,&c);
	for(int l,r,k,i=1;i<=m;i++) {
		scanf("%d%d%d",&l,&r,&k);
		num[r+1]-=k;num[l]+=k;
	}
	for(int i=1;i<=n;i++) num[i]+=num[i-1];
	LL rev_2=fpow(2,MOD-2),rev_c=fpow(c,MOD-2);
	for(int to,i=0;i<c;i++) {
		for(int j=0;j<c;j++) {
			to=i*j%c;
			st.x[i][to]=(st.x[i][to]+rev_2*rev_c)%MOD;
		}
		st.x[i][i]=(st.x[i][i]+rev_2)%MOD;
	}
	pw[0]=st;
	for(int i=1;i<=30;i++) pw[i]=pw[i-1]*pw[i-1];
	for(int i=1;i<=n;i++) {
		memset(now,0,sizeof(now));
		now[1]=1;
		for(int j=0;j<=30;j++) if(num[i]>>j&1) Merge(j);
		for(int j=0;j<c;j++) 
			ans=(ans+(LL)now[j]*j)%MOD;
	}
	printf("%d\n",ans);
	return 0;
}
