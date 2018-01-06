#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
struct person {
	char name[9];
	float temp;
	int cou;
};
bool if_heat(person info) {
	if(info.temp >= 37.5 && info.cou == 1) return true;
	else return false;
}
int main() {
	int n;
	cin >> n;
	int count = 0;
	person p[n];

	for(int i = 0; i < n; ++i) {
		cin >> p[i].name;
		cin >> p[i].temp >> p[i].cou;
	}

	for(int i = 0; i < n; ++i)
		if(if_heat(p[i])) {
			cout << p[i].name << endl;
			count += 1;
		}

	cout << count;
	return 0;
}