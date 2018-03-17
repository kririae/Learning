#include<cstdio>
#include<ctime>
#include<cstring>
#include<windows.h>
#include<cmath>
using namespace std;
bool a[10001];
bool x1(int v)
{
	int l=sqrt(v);
	for(int i=2;i<=l;++i) if(v%i==0) return false;return true;
}
int main()
{
	srand(time(0));
	printf("%d\n",2);
	for(int ii=1;ii<=2;++ii)
	{
		memset(a,0,sizeof(a));
		int n=rand()%500+500,m=rand()%20+1;
		printf("%d %d\n",n,m);
		for(int i=1;i<=m;++i) {
			int k=rand()%n+1;
			if(x1(k)&&!a[k]&&k!=1){
				a[k]=true;
				printf("%d ",k);
			}
			else {i--;continue;}
		}printf("\n");
	}
	return 0;
}
