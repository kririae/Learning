#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
struct posi {
	int v;
	int a;
	int b;
};
vector<int> res;
posi v[20005];
int main() {
	freopen("test.in", "r", stdin);
	freopen("output2.txt", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> v[i].v;
		v[i].a = 1;
		v[i].b = 0;
	}
	for(int i = 1; i <= n; ++i) {
		int maxn = 0;
		for(int j = i - 1; j >= 1; --j) {
			if(v[i].v >= v[j].v && v[j].a > maxn) {
				maxn = v[j].a;
				v[i].b = j;
			}
		}
		v[i].a = maxn + 1;
	}
	int result = 0;
	int max_index = 0;
	for(int i = 1; i <= n; ++i) 
		if(v[i].a > result) {
			result = v[i].a;
			max_index = i;
		}
	cout << "maxn=" << result << endl;
	while(max_index >= 1) {
		res.push_back(v[max_index].v);
		max_index = v[max_index].b;
	}
	for(int i = res.size() - 1; i >= 0; --i) 
		cout << res[i] << " ";
	fclose(stdin);
	return 0;
}
