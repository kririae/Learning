#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool is_upper(char st)
{
	bool isu = false;

	for (int i = 65; i < 91; ++i)
		if(st == i) {
			isu = true;
			break;
		}

	return isu;
}
char comb(char st1, char st2)
{
	bool is_upper_st1 = is_upper(st1);
	int int_st1 = is_upper(st1) ? st1 - 65 : st1 - 97;
	int int_st2 = is_upper(st2) ? st2 - 65 : st2 - 97;
	char res = is_upper_st1 ? (int_st1 + int_st2) % 26 + 65 : (int_st1 + int_st2) % 26 + 97;
	return res;
}
int main()
{
	char a[1001], b[101];
	cin >> b >> a;

	for (int i = 0; i < strlen(a); ++i) {
		cout << comb(a[i], b[i % strlen(b)]);
	}
}