#include<cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char res[50000];
int res_i[50000];
int main()
{
	memset(res_i, 0, sizeof(res_i));
	freopen("hugeint.in", "r", stdin);
	freopen("hugeint.out", "w", stdout);
	scanf("%s", res);
	int length = strlen(res);
	long long summ = 0;

	for (int i = 0; i < length; ++i) {
		res_i[i] = res[length - i - 1] - '0';
		summ += res_i[i];
	}

	for (int i = 0; i < length; ++i)
		cout << res_i[i];

	cout << endl;
	cout << summ;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
