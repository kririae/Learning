#include <iostream>
#include <cstdio>

using namespace std;

void loads(char array[]) {
	char *ca;
	gets(ca);
	int length = strlen(array), index1 = 0, index2 = 0;

	for(int i = 0; i < length; ++i) {
		if(ca[i] != ' ') {
			array[index1][index2] = ca[i];
			++index2;
		} else {
			index2 = 0;
			++index1;
		}
	}
}
int main() {
	char array[1000][60];
	loads(array);

}