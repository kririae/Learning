#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	freopen("cowmult.in", "r", stdin);
	freopen("cowmult.out", "w", stdout);
	char *a = new char[100];
	char *b = new char[100];
	scanf("%s", a);
	scanf("%s", b);
	int length_a = strlen(a);
	int length_b = strlen(b);
	int result = 0;
	for(int i = 0; i < length_a; ++i) {
		for(int j = 0; j < length_b; ++j) {
			result += (a[i] - '0') * (b[j] - '0');
		}
	}
	cout<<result;
	fclose(stdin);fclose(stdout);
	return 0;
}
