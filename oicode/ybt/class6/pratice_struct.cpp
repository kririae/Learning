#include<iostream>
#include<cstdio>
using namespace std;
struct name1 {
	int chinese, math;
	int total;
} a[3];
int main()
{
	name1 a[3];

	for (int i = 0; i < 3; ++i) {
		scanf("%d%d", &a[i].chinese, &a[i].math);
		a[i].total = a[i].chinese + a[i].math;
	}

	for (int i = 0; i < 3; ++i) {
		cout << a[i].total << endl;
	}

	return 0;
}