/*
 * by kriaeth 2017/11/9
 * SPFA
 */
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
typedef long long ll;
ll start, end, n, m;
struct edge {
	int length;
	int to;
	edge(ll a, ll b)
	{
		to = a, length = b
	};
} vector<edge> v[maxn];
queue<ll> q;
void add_edge(ll from, ll to, ll value);
void SPFA();
int main() {}
void add_edge(ll from, ll to, ll value)
{
	v[from].push_back(edge(to, value));
}
void SPFA() {}
