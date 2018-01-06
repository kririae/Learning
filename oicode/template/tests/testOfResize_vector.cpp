#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
	v.resize(10);

	for (int i = 0; i < 10; ++i)
		v[i] = i;

	cout << v.size() << endl;
	v.resize(3);

	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}

	return 0;
}