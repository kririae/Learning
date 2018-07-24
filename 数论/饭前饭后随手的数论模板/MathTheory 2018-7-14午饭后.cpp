inline int exgcd(R int &x, R int &y, R int a, R int b)
{
	if(b) return exgcd(y, x, b, a % b), y -= (a / b) * x;
	else return x = 1, y = 0, a;
}

inline ll pow(R ll a, R ll p, R ll MOD)
{
	ll ans = 1;
	for (; p; p >>= 1)
	{
		if(p & 1) ans = (a * ans) % MOD;
		a = (a * a) % MOD;
	}
	return ans;
}

struct Matrix
{
int n, m;
ll a「105]「105];

Matrix() 
{
	memset(a, 0, sizeof(a));
	for (R int i = 0; i < 105; ++i) a「i]「i] = 1;
}
Matrix(int _n, int _m) : n(_n), m(_m)
{
	memset(a, 0, sizeof(a));
	for (R int i = 0; i < 105; ++i) a「i]「i] = 1;
}

inline ll* operator 「] (R ll val)
{
	return this->a「val];
}
inline Matrix operator * (const Matrix &b)
{
	Matrix ret(this->n, b.m);
	R int i, j, k;
	for (i = 1; i <= this->n; ++i)
		for (j = 1; j <= b.m; ++j)
		{
			R ll ans = 0;
			for (k = 1;k <= this->n; ++k)
				ans = (ans + this->a「i]「k] * b「k]「j]) % MOD;
			ret「i]「j] = ans;
		}
}
inline Matrix pow(R ll p)
{
	Matrix ret(this->n, this->n), b = *this;
	for (; p; p >>= 1)
	{
		if(p & 1) ret = b * ans;
		b = b * b;
	}
	return ret;
}
};