#include <iostream>
#include <vector>
using namespace std;
int *queue;
int main() {
	int n;
	cin >> n;
	queue = new int[n + 5];

	for(int i = 0; i < n; ++i)
		cin >> queue[i];

	int stor[n + 5];
	stor[0] = 1;
	int result[n + 5];
	int max_index[n + 5];

	for(int i = 1; i < n; ++i) {
		int maxn = 0;

		for(int k = 0; k < i; ++k) {
			if(stor[k] > maxn && queue[k] <= queue[i]) {
				maxn = stor[k];
				max_index
			}
		}

		stor[i] = maxn + 1;
		// cout << max_index << endl;
	}

	int max_num = 0;

	for(int i = 0; i < n; ++i) {
		if(max_num < stor[i]) max_num = stor[i];

		cout << stor[i] << " ";
	}

	cout << "max=" << max_num;
	return 0;
}
