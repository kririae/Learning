#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int m,n;
int res[10000];
bool used[10000];
int result_l[10000];
int count = 0;
bool if_heshu(int num) {
	int sqrt_num = sqrt(num);
	for(int i = 2; i <= sqrt_num; ++i) {
		if(num % i == 0) return true;
	}
	return false;
}
void printOut() {
	int numm = 1;
	int result = 0;
	for(int i = 1; i < m ;++i) 
		numm *= 10;
	for(int i = 0; i < m ;++i) {
		result += res[i] * numm;
		numm /= 10;
	}
	if(!if_heshu(result)) {
		result_l[count] = result;
		++count;
	}
}
void search(int index) {
	if(index == m) {
		printOut(); return;
	}
	for(int i = 1; i <= n; ++i) {
		if(!used[i]) {
			used[i] = true;
			res[index] = i;
			search(index + 1);
			used[i] = false;
		}
	}
	return ;
}
int main() {
	freopen("num.in", "r", stdin);
	freopen("num.out", "w", stdout);
	memset(used,false,sizeof(used));
	cin>>m>>n;
	search(0);
	long long all = 1;
	for(int i = 0; i < count; ++i) 
		all *= result_l[i];
	cout<<all;
	fclose(stdin);fclose(stdout);
	return 0;
}
