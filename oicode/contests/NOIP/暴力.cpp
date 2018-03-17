#include<cstdio>
using namespace std;
int n,k,a[15],ans,maxn=-1;
void x1(int v)
{
	if(v==k+1)
	{
		if(ans%3==0&&ans>maxn&&ans!=0) maxn=ans;return;
	}
	ans*=10;
	for(int i=1;i<=n;++i) {
		ans+=a[i];
		x1(v+1);
		ans-=a[i];
	}
	ans/=10;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	x1(1);
	printf("%d",maxn);
	return 0;
}
