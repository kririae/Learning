#include<iostream>
#include<cstdio>
using namespace std;
int v(int p)
{
	int sum = 0;

	for(int i = 1; i < p; ++i) {
		if(p % i == 0)sum += i;
	}

	return sum;
}
int main()
{
	//cout<<v(220);
	int a = 1, b;

	while(true) {
		a++;
		b = v(a);

		if(a == v(b) && a != b)break;
	}

	cout << a << " " << b;
	//cout<<a<<" "<<v(a);
}
