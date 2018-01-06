#include <bits/stdc++.h>
using namespace std;
struct cloud {
	int price, value;
}; // clouds
cloud l[10005];
struct summ {
	int sump, sumv;
};
summ suml[10005]; // used to describe the costs to buy a cloud( suml[i].price is
// the cost of price ...and so on
int father[10005]; // union find set
int stor[10005];   // bag problem
bool can[10005];   // used?
inline int find(int v) {
	if (father[v] != v)
		father[v] = find(father[v]);
	else
		return father[v];
}
inline void unionn(int t1, int t2) {
	int uir = find(t1), vir = find(t2);
	father[uir] = vir; // cloud r1 must be related to r2(the same as r2)
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m, w;
	cin >> n >> m >> w;

	for (int ci, di, i = 1; i <= n; ++i) {
		cin >> ci >> di;
		cloud a;
		a.price = ci, a.value = di;
		l[i] = a;
	}

	// ufs processing
	for (int i = 1; i <= n; ++i)
		father[i] = i;

	for (int ui, vi, i = 1; i <= m; ++i) {
		cin >> ui >> vi;
		unionn(ui, vi);
	}

	for (int i = 1; i <= n; ++i) {
		int root = find(i);
		cout << root << " " << i << ": ";

		for (int j = 1; j <= n; ++j) {
			if (find(j) == root)
				cout << j << " ";
		}

		cout << endl;
	}

	// end of ufs
	// building relation ship
	// enu all the clouds
	/*
	for(int i = 1; i <= n; ++i) {
	    int root = find(i);
	    for(int j = 1; j <= n; ++j) {
	        if(find(j) == root) {
	            l[i].price += l[j].price;
	            l[i].value += l[j].value;
	        }
	    }
	}*/
	// end of building relationship
	// bag problem
	memset(can, false, sizeof(can));
	memset(stor, 0, sizeof(stor));
	stor[0] = 0;
	can[0] = true;

	for (int i = 1; i <= n; ++i) {
		int currp = l[i].price, currv = l[i].value;
		cout << i << ":" << currp << " " << currv << endl;

		if (currp != 0 && currv != 0)
			for (int j = w; j >= 0; --j) {
				if (can[j]) {
					if (j + currp >= w)
						continue;

					can[j + currp] = true;
					stor[j + currp] = max(stor[j + currp], stor[j] + currv);
				}
			}
	}

	for (int i = 0; i <= w + 1; ++i) {
		cout << stor[i] << " ";
	}

	cout << endl;
	return 0;
}
