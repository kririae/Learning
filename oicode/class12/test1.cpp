#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
using namespace std;
 
int main() {
	string res;
	getline(cin,res);
	stringstream ss(res);
	int integer, sum = 0;
	while(ss >> integer) sum += integer;
	cout<<sum;
	return 0;
}
