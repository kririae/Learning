#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
stack<char> s;
int main() {
	char c;
	while(!isspace(c = getchar())) {
		if(c == '(') s.push('(');
		if(c == ')') s.pop();
	}
	if(s.size() == 0) cout << "YES";
	else cout << "NO";
	return 0;
}
