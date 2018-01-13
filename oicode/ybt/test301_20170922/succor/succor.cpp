#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct classroom {
	int index = 0;
	int people = 0;
};
classroom list[100005];
bool compare(const classroom& a, const classroom& b)
{
	if(a.people > b.people) return true;

	if(a.people == b.people) return a.index < b.index;

	return false;
}
int main()
{
	freopen("succor.in", "r", stdin);
	freopen("succor.out", "w", stdout);
	int all = 0;
	int m;
	cin >> m;

	for(int i = 0; i < m; ++i) {
		int value;
		cin >> value;
		list[value].index = value;
		list[value].people += 1;
		++all;
	}

	sort(list, list + 100001, compare);
	cout << list[0].index;

	for(int i = 1; i < all; ++i)
		if(list[i].index != 0 && list[i].people != 0) cout << "->" << list[i].index;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
