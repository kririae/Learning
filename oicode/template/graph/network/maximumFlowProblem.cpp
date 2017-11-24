#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std;
typedef long long ll;
struct cube {
	ll x;
	ll y;
	ll z;
} p[1005];
ll n, h, r;
double dist[2005][2005];
bool res_dist[2005][2005];
bool if_true = false;
inline void floyed () {
	for(register int k = 1; k <= n; ++k) {
		for(register int i = 1; i <= n; ++i) {
			for(register int j = 1; j <= n; ++j) {
				res_dist[i][j] = res_dist[i][j] || (res_dist[i][k] && res_dist[k][j]);
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	for(register int rp = 0; rp < t; ++rp) {
		cin >> n >> h >> r;
		//  GC
		for(int i = 1; i <= n; ++i) {
			p[i].x = p[i].y = p[i].z = 0;
			for(int j = 1; j <= n; ++j) {
				dist[i][j] = 0x7fffffff;
				res_dist[i][j] = false;
			}
		}
		if_true = false;
		for(register int i = 1; i <= n; ++i) 
			cin >> p[i].x >> p[i].y >> p[i].z;
		for(register int i = 1; i <= n; ++i) {
			for(register int j = 1; j <= n; ++j) {
				dist[i][j] = sqrt(pow(p[i].x - p[j].x, 2)
				+ pow(p[i].y - p[j].y, 2)
				+ pow(p[i].z - p[j].z, 2));
				if(dist[i][j] <= r * 2) res_dist[i][j] = true;
			}
		}
		floyed();
		for(register int i = 1; i <= n; ++i) 
		for(register int j = 1; j <= n; ++j) {
			if(abs(p[i].z) <= r && abs(p[j].z - h) <= r) {
				if(res_dist[i][j]) {
					if_true = true;
					i = n + 1, j = n + 1;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}