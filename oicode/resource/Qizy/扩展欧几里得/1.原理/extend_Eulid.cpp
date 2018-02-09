//扩展欧几里得算法 
#include <iostream>
#include <cstdio>
using namespace std;
int x,y,q;
void extend_Eulid(int a,int b)
{
	if(b == 0)
	{
		x = 1;
        y = 0;
        q = a;
	}
	else
	{
	    extend_Eulid(b,a%b);
		int temp = x;
		x = y;
		y = temp - a/b*y;
	}
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	//if(a < b) swap(a,b);

	extend_Eulid(a,b);
	
	printf("%d*(%d)+%d*(%d)=%d\n",a,x,b,y,q);
	
	system("pause");
	return 0;
}
