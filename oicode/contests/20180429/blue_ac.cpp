#include <bits/stdc++.h>

using namespace std;

int n, m, d, l, a, t;
deque<int> q;
int main()
{
	freopen("blue.in", "r", stdin);
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> t;
	while(t--)
	{
		q.clear();
		cin >> n >> m >> d >> l;
		
		q.push_back(0);
		
		for (int i = 1; i <= n; ++i)
		{
			cin >> a;
			while(!q.empty() && a - q.front() > d) q.pop_front();
			q.push_back(a);	
		}
		
		while(!q.empty() && l - q.front() > d) q.pop_front();
		q.push_back(l);
		
		if(q.size() >= m) cout << "Excited" << " " << q.size() << endl;
		else cout << q.size() << endl;
	}
}
