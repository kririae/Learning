#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int k;
struct BigInteger {
	int length, s[205];
	//³õÊ¼»¯sÎª0
	BigInteger() {memset(this->s,0,sizeof(s));length = 0;}
};
void init(BigInteger& input) {
	char n[205];
	scanf("%s",n);
	int length = strlen(n);
	for(int i = length - 1; i >= 0; --i)
		input.s[length - i - 1] = n[i] - '0';
	input.length = length;
}
int doubled(BigInteger value) {
	if(value.length == 1 && value.s[0] == 1) return 2011;
	bool if_odd = false;
	if((value.s[0] % 2) != 0) {
		if_odd = true;
		value.s[0] += 1;
	}
	for(int i = 0; i < value.length; ++i) {
		value.s[i] *= 5;
	}
	for(int i = 0; i < value.length; ++i) {
		value.s[i + 1] += (value.s[i]-(value.s[i] % 10)) / 10;
		value.s[i] %= 10;
	}
	for(int i = 0; i < value.length; ++i)
		value.s[i] = value.s[i + 1];
	for(int i = value.length - 1; i >= 0; --i){
		if(value.s[i] > 0) {
			value.length = i + 1;
			break;
		}
	}
	int result = doubled(value);
	int s = (result*result) % 10000;
	if(if_odd) s = (s * 2011) % 10000;
	return s;
}
int main() {
	BigInteger a;
	init(a);
	cout<<doubled(a);
}


