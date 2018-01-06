/*今天智商欠费，只好来学习*/
#include<cstdio>
#include<map>
#include<iostream>
#define LL long long
#define N 5000005
using namespace std;
const int mod = 1e9 + 7;
LL phi[N];
bool check[N];
int prime[N];
int pcnt;
void pre() { //改改就是phi函数
	phi[1] = 1;

	for(int i = 2; i < N; i++) {
		if(check[i] == 0)	phi[i] = i - 1, prime[++pcnt] = i;

		for(int j = 1; i * prime[j] < N && j <= pcnt; j++) {
			phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			check[i * prime[j]] = 1;

			if(i % prime[j] == 0) phi[i * prime[j]] = phi[i] * prime[j];
		}
	}

	for(int i = 2; i < N; i++) (phi[i] += phi[i - 1]) %= mod;
}
//---记忆化------
map<LL, LL> mp;
map<LL, LL>::iterator itr;
LL F(LL x) {
	if(x < N) return phi[x];

	if((itr = mp.find(x)) != mp.end()) return (*itr).second;

	LL ret = (x % mod) * ((x + 1) % mod) % mod * 500000004 % mod, ne;

	for(LL i = 2, t; i <= x; i = ne + 1) {
		ne = x / (t = x / i);
		ret -= (ne - i + 1) % mod * F(t);

		if(ret < 0) ret += 2LL * mod * mod;
	}

	ret %= mod;
	mp[x] = ret;
	return ret;
}
int main() {
	pre();
	LL a;
	cin >> a;
	cout << F(a) << endl;
	return 0;
}
