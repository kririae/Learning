#include<cstdio>
#include<iostream>
using namespace std;
//错误样例（——！）坑了我好久！！
inline int read() {
	char c = getchar();
	int ret = 0;
	int f = 1;

	while(c == ' ' || c == '\n') c = getchar();

	while((c >= '0' && c <= '9') || c == '-') {
		if(c == '-') f = -1;
		else ret = ret * 10 + c - '0';

		c = getchar();
	}

	return ret * f;
}
//正确样例
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();

	while(ch < '0' || ch > '9') {
		if(ch == '-')f = -1;

		ch = getchar();
	}

	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}

	return x * f;
}
//原因  windows换行符为'\n'（10），linux为'\r'(13)
int main() {
}
