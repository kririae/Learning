#include <bits/stdc++.h>
using namespace std;
int n, degree[105], value;
vector<int> son[105];
queue<int> proc;
bool graph[105][105];
int main() {
	cin >> n;

	for (int value, i = 1; i <= n; ++i) {
		cin >> value;

		while(value != 0) {
			son[i].push_back(value);
			++degree[value];
			graph[i][value] = true;
			cin >> value;
		}
	}

	for (int i = 1; i <= n; ++i) {
		if(degree[i] == 0) proc.push(i);
	}

	while(!proc.empty()) {
		int curr = proc.front();
		proc.pop();
		cout << curr << " ";

		for (int i = 1; i <= 105; ++i) {
			if(graph[curr][i]) {
				--degree[i];

				if(degree[i] == 0)
					proc.push(i);
			}
		}
	}
}