#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, start, end, midd;
int *input = new int[100005];
//获取两者中的最小值
int minn(int a, int b)
{
	return a < b ? a : b;
}

void init()
{
	//初始化所有的变量
	cin >> n;

	for(int i = 0; i < n; ++i)
		scanf("%d", &input[i]);

	cin >> m;
	//将input数组排序
	sort(input, input + n);
}
bool search(int value)
{
	start = 0, end = n - 1, midd = (start + end) / 2;

	while(start <= end) {
		if(input[midd] == value) return true;

		if(input[midd] > value) end = midd - 1;
		else start = midd + 1;

		midd = (start + end) / 2;
	}

	return false;
	start = 0;
	end = n - 1;
	midd = (start + end) / 2;
}
int main()
{
	init();
	bool if_print = false;
	int minnum = input[0];

	for(int i = 0; i < n; ++i) {
		if(search(m - input[i])) {
			int res = minn(input[i], m - input[i]);

			if(res) minnum = res;

			if_print = true;
		}
	}

	if(if_print) cout << minnum << " " << m - minnum;
	else cout << "No";

	return 0;
}
