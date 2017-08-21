#include "cstdio"
#include "iostream"
#include "cstring"
using namespace std;
int main(){
	char char_array[101];bool if_first = true;
	gets(char_array);
	int length = strlen(char_array);
	int array[101];
	for (int i = 0; i < length; ++i)
		array[i] = char_array[i] - '0';
	int r = 0;
	for (int i = 0; i < length; ++i)
	{
		array[i] += 10 * r;
		if (!if_first) cout<<array[i]/13;
		if(array[i] > 0) if_first = false;	
		r = array[i] % 13;
	}
	cout<<endl<<r;
}