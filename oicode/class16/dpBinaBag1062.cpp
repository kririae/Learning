#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
bool board[1605][1605];
int n, data[45], sum = 0;
double result = 0;
void getSqu(int a, int b) {
	int c = sum - a - b;
	if(a + b <= c || b + c <= a || a + c <= b) return;
	double p = (a + b + c)/2.0;
	double res = sqrt(p * (p - a) * (p - b) * (p - c));
	if(res > result) result = res;
	// cout << res << " " << sum << endl;
}
int main() {
	// freopen("noi1062.in", "r", stdin);
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> data[i];
		sum += data[i];
	}
	int fmax = 0, smax = 0;
	board[0][0] = true;
	for(int i = 0; i < n; ++i)  {
		for(int j = fmax; j >= 0; --j) {
			for(int k = smax; k >= 0; --k) {
				// cout << "execute" << endl;
				if(board[j][k]) {	
					board[j + data[i]][k] = true;
					board[j][k + data[i]] = true;
					if(j + data[i] > fmax) fmax = j + data[i];
					if(k + data[i] > smax) smax = k + data[i];
				}
			}
		}
	}
	for(int j = fmax; j >= 0; --j) {
			for(int k = smax; k >= 0; --k) {
				if(board[j][k]) {
					//cout << j << " " << k;
					getSqu(j, k);
				}
			}
		}
	if(result == 0) cout << -1;
	else cout << (int)(result * 100);
	// fclose(stdin);
	return 0;
}
