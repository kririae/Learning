#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	char a[100];
	int length = 0;
	gets(a);

	for(int i = 0; i < 100; ++i)
		if(a[i] == '!') {
			length = i + 1;
			break;
		}

	for(int i = length - 2; i >= 0; --i)
		printf("%c", a[i]);
}