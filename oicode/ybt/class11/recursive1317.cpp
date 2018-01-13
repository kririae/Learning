#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int m, n;
int res[100];
bool used[100];
void printOut()
{
	for(int i = 1; i <= n; ++i) {
		if(i != n) cout << res[i] << " ";
		else cout << res[i];
	}

	cout << endl;
}
void search(int index)
{
	if(index > n) {
		printOut();
		return;
	}

	for(int i = res[index - 1]; i <= m; ++i) {
		if(!used[i]) {
			used[i] = true;
			res[index] = i;
			search(index + 1);
			used[i] = false;
		}
	}
}
int main()
{
	memset(used, false, sizeof(used));
	cin >> m >> n;
	res[0] = 1;
	search(1);
	return 0;
}