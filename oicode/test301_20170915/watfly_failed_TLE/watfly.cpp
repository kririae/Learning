#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n ,x=0 , y = 0, maxn = 0;
int res[10005];
int summary(int start, int end) {
	long long sumn = 0;
	for(int i = start; i <= end; ++i) 
		sumn += res[i];
	return sumn;
}
int main() {
	freopen("watfly.in", "r", stdin);
 	freopen("watfly.out", "w", stdout);
	cin>>n;
	bool if_minus = true;
	for(int i = 0; i < n; ++i) {
		cin>>res[i];
		if(res[i] >= 0) if_minus = false;
	}
	if(if_minus) cout<<"0";
	else {
		if(n == 1 || n == 0) {
			cout<<0;
			return 0;
		}
		if(n == 2) {
			cout<<"1"<<" "<<"2"<<endl;
			cout<<res[0] + res[1];
			return 0;
		} 
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				int all = summary(i, j);
				if(maxn < all) {
					maxn = all; 
					x = i + 1;
					y = j + 1;
				}
			}
		}
	}
	cout<<x<<" "<<y<<endl;
	cout<<maxn;
	fclose(stdin);fclose(stdout);
	return 0;
}
