#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int *firstList;
int n, count = 0;
void printFirst(int curr) {
	if(firstList[curr] != 0 && firstList[curr] != 1) cout<<firstList[curr]; 
}
void printX(int curr) {
	if(curr != 0 && curr != 1) cout<<"^"<<curr;
}
void printOne(int curr) {
	//打印系数 
	printFirst(curr);		
	if(n - curr != 0){
		cout<<"a";
		//打印次数 
		printX(n - curr); 
	}
	if(curr != 0) {
		cout<<"b";
		//打印次数
		printX(curr);
	}		
}
int main() {
	freopen("power.in", "r", stdin);
	freopen("power.out", "w", stdout);
	cin >> n;
	firstList = new int[n + 5];
	int index = 0;
	for(int i = 0; i <= n / 2; ++i) {
		firstList[i] = n * (i);++index;
	}
	firstList[0] = 1;
	int index2 = index - 1;
	if(n % 2 == 0) index2 = index - 2;
	for(int i = 0; i < (n + 1) / 2; ++i) {
		firstList[index + i] = firstList[index2 - i];		
	}
	cout<<"(a+b)^"<<n<<"=";
	printOne(0);
	for(int i = 1; i < n + 1; ++i) {
		cout<<"+";
		printOne(i);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
