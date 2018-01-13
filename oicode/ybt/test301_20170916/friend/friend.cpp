#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int *weight;
bool *used;
struct result {
	int wei;
	int lig;
	int sumn;
};
result *data;
bool compare(const result& a, const result& b)
{
	if(a.sumn > b.sumn) return true;

	if(a.sumn == b.sumn) return a.wei > b.wei;

	return false;
}
int main()
{
	freopen("friend.in", "r", stdin);
	freopen("friend.out", "w", stdout);
	int n;
	cin >> n;
	weight = new int[n + 5];
	used = new bool[n + 5];
	data = new result[n + 5];

	for(int i = 0; i < n; ++i)
		cin >> weight[i];

	sort(weight, weight + n);

	for(int i = 0; i < n / 2; ++i) {
		data[i].lig = weight[i];
		data[i].wei = weight[n - i - 1];
		data[i].sumn = data[i].lig + data[i].wei;
	}

	sort(data, data + n / 2, compare);

	for(int i = 0; i < n / 2; ++i)
		printf("%d=%d+%d\n", data[i].sumn, data[i].wei, data[i].lig);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
