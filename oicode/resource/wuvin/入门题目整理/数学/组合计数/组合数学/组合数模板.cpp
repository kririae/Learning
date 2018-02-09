#define N 200005
const long long mod = 1e9 + 7;
template <class T>
T exgcd(T a, T b, T &x, T &y)
{
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	T t, ret;
	ret = exgcd(b, a % b, x, y);
	t = x, x = y, y = t - a / b * y;
	return ret;
}
template <class T> T reverse(T k)
{
	T x = 1, y = 0;
	exgcd(k, mod, x, y);
	return (x % mod + mod) % mod;
}
long long fac[N];
template <class T> T C(T up, T dn) //c(n,m)
{
	return (fac[dn]) * (reverse(fac[up])) % mod * (reverse(fac[dn - up])) % mod;
}
void pre(int size)
{
	fac[0] = 1;
	for(int i = 1; i <= size; i++) fac[i] = 1LL * fac[i - 1] * i % mod;
}
