#include<ctime>
#include<cstdio>
#include<windows.h>
using namespace std;
bool ok[10];
int main()
{
	srand(time(0));
	int n=rand()%10+1,k=rand()%9+1;
	printf("%d %d\n",n,k);
	for(int i=1;i<=n;++i)
	{
		int lm=rand()%10;
		if(ok[lm]) {i--;continue;}
		ok[lm]=true;printf("%d ",lm);
	}
	return 0;
}
