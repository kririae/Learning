/*
套路
有Alice和Bob的一定是%2然后判定的_(:з」∠)_
其实是考虑最终情况
 */
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

int n, a, b;
int main()
{
	scanf("%d%d%d", &n, &a, &b);
	if((b - a - 1) % 2) puts("Alice");
	else puts("Borys")
	return 0;
}