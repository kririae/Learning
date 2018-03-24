#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("data2.txt", "r", stdin);
	char a[1000];
	char b[1000];
	for (int i = 0; i < 68; ++i)
	{
		cin >> a[i + 1];
	}
	for (int i = 0; i < 68; ++i)
	{
		cin >> b[i + 1];
	}
	for (int i = 1; i <= 68; ++i)
	{
		if(a[i] != b[i])
		{
			cout << "wrong on: " << i << " " << a[i] << " " << b[i] << endl;
		}
	}
}
