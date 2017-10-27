#include <set>
#include <iostream>
set<int> s;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int value;
		cin >> value;
		set.insert(value);
	}
	int a;
	cin >> a;
	cout << set.count(a) << endl;
	return 0;
}