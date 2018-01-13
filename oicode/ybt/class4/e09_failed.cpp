#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool z(int x);
int main()
{
	int n, res = 0;

	cin >> n;

	for(int i = 1; i <= n; ++i) {
		bool if_mod7 = false, if_in7 = false;
		int x = i;

		if(n % 7 == 0) if_mod7 = true;

		while(x >= 1) {
			if(x % 10 == 7) {
				if_in7 = true;
				break;
			} else {
				x /= 10;
			}
		}

		if(!if_mod7 && !if_in7) {
			res += i * i;
		}
	}

	cout << res;
	return 0;
}