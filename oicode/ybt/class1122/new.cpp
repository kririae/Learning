#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
const int MAXN = 1000;

struct Node {
	bool have_value;
	int value;
	Node* left, *right;
	Node(): have_value(false), value(0), left(NULL), right(NULL) {}
};

Node* root;

Node* newnode()
{
	return new Node();
}
bool addnode(int v, char* s)
{
	int length = strlen(s);
	Node* curr = root;

	for(int i = 0; i < length; ++i) {
		if(s[i] == 'L') {

		}

		if(s[i] == 'R') {

		}
	}
}
int main()
{

	return 0;
}
