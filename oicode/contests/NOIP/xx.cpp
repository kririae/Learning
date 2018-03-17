#include<cstdio>
using namespace std;
int a[1005],ans;
int main()
{
	for(int i=1;i<=100;++i) {if(i%3==0) a[i]++;if(i%7==0) a[i]++;}
	for(int i=1;i<=100;++i) if(a[i]==1) printf("%d ",i);
	return 0;
}
