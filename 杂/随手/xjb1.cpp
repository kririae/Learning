for (R int i = 2; i <= n; ++i)
{
	if(!vis[i]) prm[++cnt] = i;
	for (R int j = 1; j <= cnt; ++j)
	{
		if(i * prm[j] > n) break;
		vis[i * prm[j]] = 1;
		if(i % prm[j] == 0) break;
	}
}

inline ll pow(ll a, ll p)
{
	ll ans = 1; a %= mod;
	for (; p; p >>= 1)
	{
		if(p & 1) ans = (a * ans) % mod;
		a = (a * a) % mod;
	}
	return ans;
}

class Matrix
{
ll n, m, a[105][105];
inline Matrix() 
{
	memset(a, 0, sizeof(a));
	for (R int i = 0; i < 105; ++i)
		a[i][i] = 1;
}
inline Matrix(int _n, int _m) : n(_n), m(_m) 
{
	memset(a, 0, sizeof(a));
	for (R int i = 0; i < 105; ++i)
		a[i][i] = 1;
}

inline ll* operator [] (ll val)
{
	return this->a[val];
}

inline Matrix operator * (const Matrix &x)
{
	Matrix ret(this->n, x.m);
	for (R int i = 1; i <= this->n; ++i)
		for (R int j = 1; j <= x.m; ++j)
		{
			ll ans = 0;
			for (R int k = 1; k <= this->n; ++k)
				ans = (ans + this->a[i][k] * x[k][j]) % mod;
			ret[i][j] = ans;
		}
	return ret;
}
inline Matrix pow(ll p)
{
	Matrix ans(this->n, this->n), b = *this;
	if(this-> n != this-> m) return ans;
	for (; p; p >>= 1)
	{
		if(p & ans) ans = b * ans;
		b = b * b;
	}
	return ans;
}
};

inline int exgcd(int &x, int &y, int a, int b)
{
	if(b) return exgcd(y, x, b, a % b), y -= x * (a / b) * y;
	else return x = 1, y = 0, a;
}

inline void tarjan(int x)
{
	low[x] = dfn[x] = ++cnt;
	s.push(x), vis[x] = 1;
	for (R int i = 0; i < edges[x].size(); ++i)
	{
		int to = edges[x][i];
		if(!dfn[i])
		{
			tarjan(to);
			low[x] = min(low[x], low[to]);
		} else if(vis[to]) {
			low[x] = min(low[x], dfn[to]);
		}
	}
	if(low[x] == dfn[x])
	{
		for (; ; )
		{
			int now = s.top();
			s.pop();
			vis[now] = 0;
			if(now == x) break;
		}
	}
}