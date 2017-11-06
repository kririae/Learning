#include <iostream>
#include <cstdio>
using namespace std;
int n;
int *p;
struct po {
	int __index__;
	int value;
	bool operator < (const po &a) const
	{if((this -> value) < a.value) return false;return true;}
	bool operator > (const po &a) const {return *(this) < a;}
};
po *temp;
void move(int i) {
	if(i == 0) {
		
	}
}
int main() {
	cin >> n;
	p = new int[n + 5];
	temp = new po[n + 5];
	int sumn;
	for(int i = 0; i < n; ++i) {
		cin >> p[i];
		sumn += p[i];
	}
	int arr = sumn / n;
	for(int i = 0; i < n; ++i) {
		temp[i].__index__ = i;
		temp[i].value = p[i] - arr;
	}
	sort(temp, temp + n);
	// give up...
	return 0;
}
