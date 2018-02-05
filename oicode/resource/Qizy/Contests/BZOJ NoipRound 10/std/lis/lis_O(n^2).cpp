#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
int a[maxn],A,B,C,D,n;

int f[maxn],ans;
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d%d",&n,&a[1]);
	scanf("%d%d%d%d",&A,&B,&C,&D);
	for(int i=2;i<=n;++i)
		a[i]=(A*a[i-1]*a[i-1]+B*a[i-1]+C)%D;
	memset(f,0,sizeof(f)),ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<i;++j)
			if(a[j]<=a[i]) f[i]=max(f[i],f[j]);
		ans=max(ans,++f[i]);
	}
	printf("%d\n",ans);
	return 0;
}
