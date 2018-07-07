/*
嘛，简单分析一下
我们的目标，就是要求“能不能凑到sum / 2”
题意描述很蛋疼啊
不过可以bitset水一水

 */
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

int n, sum, a[10];
bitset<120005> f;
int main()
{
	for (int k = 1; ; ++k) {
		sum = 0, f.reset(), f[0] = 1;
		for (R int i = 1; i <= 6; ++i) scanf("%d", &a[i]), sum += a[i] * i;
		if(!sum) break;
		if(sum % 2) 
		{
			printf("Collection #%d:\nCan't be divided.\n\n", k);
			continue;
		}
		for (R int i = 1; i <= 6; ++i)
		{
			int tmp = a[i];
			for (int j = 1; j <= a[i]; tmp -= j, j <<= 1)
				f |= (f << j * i);
			f |= (f << tmp * i);
		}
		if(f[sum >> 1]) printf("Collection #%d:\nCan be divided.\n\n", k);
		else printf("Collection #%d:\nCan't be divided.\n\n", k);
	}
	return 0;
}