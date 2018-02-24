#include <bits/stdc++.h>
using namespace std;
deque<int> dq;
int n, d;	
int cnt = 0;
int a[maxn];
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> d;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i < n; ++i)
		dq.push_back(a[i + 1] - a[i]);
	int dis = a[n] - a[1];
	while(dis > d)
	{
	    if(*(dq.begin()) > *(dq.end() - 1)) {
	        dis -= *(dq.begin());
	        dq.pop_front();
	    }
	    else {
	        dis -= *(dq.end() - 1);
	        dq.pop_back();
	    }
	    ++cnt;
	}
	cout << cnt << endl;
	return 0;
}