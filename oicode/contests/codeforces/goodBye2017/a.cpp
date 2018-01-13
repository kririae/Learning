//
// Created by AliceMargatroid on 2017/12/29.
//

#include <bits/stdc++.h>
using namespace std;
char c[55], lst[5] {'a', 'e', 'i', 'o', 'u'};
int summ = 0;
inline bool isvowel(char c)
{
	for (int i = 0; i <= 4; ++i)
		if(c == lst[i]) return true;

	return false;
}
inline bool isthdigit(int val)
{
	return val % 2 != 0;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> c;
	auto c_size = strlen(c);

	for (auto a : c) {
		if(isdigit(a) && isthdigit(a - '0'))
			++summ;
		else if(isvowel(a)) {
			++summ;
		}
	}

	cout << summ << endl;
	return 0;
}