// kriaeth
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;
int n;
int *res, *v, *input, *check;
void generate(int length);
bool ascend(int *a, int times) {
	for(int i = 1; i < times; ++i) 
		if(a[i] <= a[i - 1]) return false;
	return true;
}
int main() {
	srand(time(NULL));
	cin >> n;
	input = new int[n];
	check = new int[n];
	memcpy(check, input, sizeof(int) * n);
	for(int i = 0; i < n; ++i) 
		cin >> input[i];
	while(!ascend(check, n)) {
		generate(n);
		for(int i = 0; i < n; ++i) 
			check[res[i]] = input[i];
	}
	for(int i = 0; i < n; ++i) 
		cout << check[i] << " ";
	return 0;
}
void generate(int length) {
	res = new int[length + 2];
	v = new int[length + 2];
	int size_v = length, curr_index_res = 0;
	for(int i = 0; i < length; ++i) 
		v[i] = i;
	for(int i = 0; i < length; ++i) {
		int cur_index = rand() % size_v;
		res[curr_index_res] = v[cur_index];
		v[cur_index] = v[size_v - 1];
		delete &v[size_v - 1];
		--size_v;
		++curr_index_res;
	}
}
