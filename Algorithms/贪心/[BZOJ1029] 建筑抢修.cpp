/*
很强的替换性贪心
 */
#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 150005;

struct C
{
	int t1, t2;
	C() {}
	bool operator < (const C &val) const 
	{ return t2 == val.t2 ? t1 < val.t1 : t2 < val.t2; }
} a[maxn];

int n, curr, cnt;
priority_queue<int> q;
int main()
{
	scanf("%d", &n);
	for (R int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].t1, &a[i].t2);	
	sort(a + 1, a + 1 + n);
	for (R int i = 1; i <= n; ++i)
	{
		if(curr + a[i].t1 <= a[i].t2) 
			q.push(a[i].t1), ++cnt, curr += a[i].t1;
		else if(a[i].t1 < q.top())
			curr -= q.top(), q.pop(), q.push(a[i].t1), curr += a[i].t1;
	}
	printf("%d", cnt);
	return 0;
}