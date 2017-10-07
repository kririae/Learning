#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	freopen("dp1267.in", "r", stdin);
	int m, n;
	cin >> m >> n;
	int k = 0;
	int used[500];
	int value[500];
	memset(value, 0, sizeof(value));
	memset(used, false, sizeof(used));
	used[0] = true, value[0] = 0;
	for(int w, c, i = 0; i < n; ++i)  {
		cin >> w >> c;
		for(int j = k; j >= 0; --j) {
			if(used[j] && j + w <= m) {
				cout << w << " " << c << " " << k << endl;
				if(used[j + w]) 
					if(value[j + w] < value[j] + c) value[j + w] = value[j] + c;
				else 
					used[j + w] = true, value[j + w] = value[j] + c;
				if(j + w > k) k = j + w;
			}
		}	
	}
	int result = 0;
	for(int i = 0; i < k; ++i) {
		cout << value[i];
		if(used[i] && value[i] > result) result = value[i];
	}
	cout << endl;
	for(int i = 0; i < k; ++i) {
		cout << used[i];
	}
	//cout << result;
	fclose(stdin);
	return 0;
}
