#include <bits/stdc++.h>

using namespace std;

inline int read()
{
    char c = getchar();
    int ret = 0, f = 1;
    for (; !isdigit(c); f = c == '-' ? -1 : 1, c = getchar());
    for (; isdigit(c); ret = ret * 10 + c - '0', c = getchar());
    return ret * f;
}

const int maxk = 105, maxn = 20;
int f[maxk][1 << 15];
int k, n, p[n], val, req[n];

int main()
{
	k = read(); n = read();
	for (int i = 1; i <= n; ++i)
	{
		read(p[i]); 
		while(val = read()) 
			req[i] = (req[i] | 1 << val - 1);
	} // init the value of a and required

	for (int i = k; i >= 0; --i)
		// enumerate status of binary
		for (int j = 0; j < (1 << n); ++j) 
			for (int qwq = 1; qwq <= n; ++qwq)
			{
				if((j & req[qwq]) == req[qwq]) 
					f[i][j] += max(f[i + 1][j], f[i + 1][j | (1 << k - 1)] + p[k])
				else f[i][j] += f[i + 1][j];
				f[i][j] /= n;
			}
	printf("%.6f", f[1][0]);
}