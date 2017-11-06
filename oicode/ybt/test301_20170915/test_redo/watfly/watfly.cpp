#include <iostream>
#include <cstdio>
using namespace std;
int *list, *list_s;
int maxn(int x, int y) {
	return x > y ? x : y;
}
int main() {
	freopen("watfly.in", "r", stdin);
	freopen("watfly.out", "w", stdout);
	int n;
	cin >> n;
	list = new int[n + 5];
	list_s = new int[n + 5];
	list_s[0] = 0;
	bool if_minus = true;
	for(int i = 0; i < n; ++i) {
		cin >> list[i];
		if(list[i] > 0) if_minus = false;
		list_s[i + 1] = list_s[i] + list[i];
	}
	if(if_minus) cout<<0;
	else {
		int best = 0, x, y;
		for(int i = 0; i < n; ++i) 
			for(int j = i; j < n; j++) 
			if(best < list_s[j + 1] - list_s[i]) {
				x = i;
				y = j;
				best = list_s[j + 1] - list_s[i];
			}
		cout<<x + 1<<" "<<y + 1<<endl;
		cout<<best;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
