#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	double h,distance;
	cin>>h;
	distance = h;
	for (int i = 0; i < 10; ++i)
	{
		h = h/2;
		distance += 2*h;
	}
	cout<<distance-2*h<<endl<<h;
    return 0;
}
