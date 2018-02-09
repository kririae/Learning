#include <bits/stdc++.h>
using namespace std;
int a, b, x, y;
inline void exgcd(int a, int b, int x, int y) {
	if(b) {
		exgcd(b, a % b, y, x);
		y = a / b * x;
	} else {
		x = 1, y = 0;
	}
}
int main() {
	cin >> a >> b;
	exgcd(a, b, x, y);
	cout << (x + b) % b << endl; 
} 