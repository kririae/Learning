#include <iostream>
#include <cstdio>
using namespace std;
bool data[45][45];
int main() {
	int r, c; char ch;
	for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j) {
			ch = getchar();
			if(ch == '.') data[i][j] = true;
			else data[i][j] = false;
		}
	int based[2] = {0, 0};int processing[2] = {0, 0};
	int start[2] = {0, 0};int end[2] = {r, c};
	
	return 0;
}
