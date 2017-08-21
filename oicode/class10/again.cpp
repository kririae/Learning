#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

int res[25],num_length,m; bool used_value[25];

void printOut() {
	int result = 1;
	for (int i = 1; i <= m; ++i)
		result *= res[i];
	cout<<endl;
}

void insert(int index){
	if(index > m) {
		printOut();
		return;
	}
	for (int i = res[index-1]+1; i <= num_length; ++i) {
			res[index] = i;
			insert(index + 1);
	}
}
int main(){
	memset(used_value,false,sizeof(used_value));
	res[0] = 0;
	num_length = 5;
	m = 3;
	insert(1);
	return 0;
}
