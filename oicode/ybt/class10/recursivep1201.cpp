#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
struct precise {
	int length;
	int value[10000];
	precise(){memset(value,0,sizeof(value));}
};
precise split(int value) {
	precise result;
	int length = 0;
	while(value > 0){
		result.value[length] = value%10;
		++length;
		value /= 10;
	}
	result.length = length;
	return result;
}
int pell(int index){
	if(index == 1) return 1;
	if(index == 2) return 2;
	return 2 * pell(index - 1) + pell(index - 2);
}
int main(){
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i) {
		int r;
		scanf("%d",&r);
		cout<<pell(r) % 32767 <<endl;
	}
	return 0;
}