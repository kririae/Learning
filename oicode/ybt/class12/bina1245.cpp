#include <iostream>
#include <cstdio>
#include <set>

using namespace std;
set<int> s;
int main()
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i) {
		int num;
		scanf("%d", &num);
		s.insert(num);
	}

	for(set<int>::iterator it = s.begin(); it != s.end(); ++it) {
		cout << *it << " ";
	}

	return 0;
}
