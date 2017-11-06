#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	freopen("hugeint.in","w",stdout);
	srand(time(NULL));
	int n = rand() % 10000;
	for(int i = 0; i < n; ++i) {
		cout<<rand(); 
	}
}
