#include<bits/stdc++.h>
#define N ((1<<18)+3)
#define eps (0.5)
using namespace std;
const long double Pi = acos((long double) - 1);
struct vec {
	double r, i;
	vec operator +(const vec &b)
	{
		return (vec) {
			r + b.r, i + b.i
		};
	}
	vec operator -(const vec &b)
	{
		return (vec) {
			r - b.r, i - b.i
		};
	}
	vec operator *(const vec &b)
	{
		return (vec) {
			r*b.r - i*b.i, r*b.i + i*b.r
		};
	}
};
int rv[N];
bool check[N];
void fft(vec *x, int len, int fx) //2^len
{
	memset(check, 0, sizeof(check));
	for(int i = 0; i < len; i++) if(!check[i]) swap(x[i], x[rv[i]]), check[rv[i]] = true;
	for(int k = 1, lnow; (lnow = 1 << k) <= len; k++) {
		vec w0 = (vec) {cos(2 * Pi*fx / lnow), sin(2 * Pi*fx / lnow)}, w, t1, t2;
		for(int i = 0; i < len; i += lnow) {
			vec *x1 = &x[i], *x2 = &x[i + lnow / 2];
			w = (vec) {
				1, 0
			};
			for(int j = 0; j < lnow / 2; j++, w = w * w0) {
				t1 = x1[j], t2 = x2[j] * w;
				x1[j] = t1 + t2, x2[j] = t1 - t2;
			}
		}
	}
}
//---------------
vec a[N], b[N], c[N];
int n, m, len;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0, t; i <= n; i++) scanf("%d", &t), a[i].r = t;
	for(int i = 0, t; i <= m; i++) scanf("%d", &t), b[i].r = t;
	len = 1;
	while((1 << len) < n + m + 1) len++;
	for(int i = 1; i < (1 << len); i++) rv[i] = (rv[i >> 1] >> 1) | (i & 1 ? 1 << (len - 1) : 0);
	fft(a, len = 1 << len, 1);
	fft(b, len, 1);
	for(int i = 0; i < len; i++) c[i] = a[i] * b[i];
	fft(c, len, -1);
	for(int i = 0; i <= n + m; i++) printf("%d ", (int)(c[i].r / len + eps));
	return 0;
}