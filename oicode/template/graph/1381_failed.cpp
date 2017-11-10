#include <bits/stdc++.h>
using namespace std;
unsigned int edge[2005][2005] = {10001}, dist[2005] = {10001};
bool white[2005] = {false};
int main() {
    for(int i = 0; i < 2005; ++i) {
        dist[i] = 10001;
        for(int j = 0; j < 2005; ++j) {
            edge[i][j] = 10001;
        }
    }
    int n, m;
    cin >> n >> m;
    for(int a, b, c, i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		edge[a][b] = edge[b][a] = c;
	}
	for(int i = 1; i <= m; ++i) {
	    dist[i] = edge[1][i];
	}
	dist[1] = 0;
	white[1] = true;
	for(int i = 1; i <= n; ++i) {
		// get min node's index;
		int minnum = 10001, minindex = 0;
		for(int j = 1; j <= n; ++j) {
			if(dist[j] < minnum && !white[j]) {
				minnum = dist[j], minindex = j;
			}
		}
		//
		if(minindex == 0) break;
		white[minindex] = true;
		for(int j = 1; j <= n; ++j) {
			if(dist[j] > dist[minindex] + edge[minindex][j]) {
				dist[j] = dist[minindex] + edge[minindex][j];
			}
		}
	}
    cout << dist[n] << endl;
    return 0;
}