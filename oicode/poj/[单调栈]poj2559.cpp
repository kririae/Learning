#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
template<typename T>
inline void read(T &val)
{
	val = 0;
	char ch = getchar();
	int isminus = 1;
	while(!isdigit(ch)) 
	{
		if(ch == '-') isminus = -1;
		ch = getchar();
	}
	while(isdigit(ch)) 
	{
		val = val * 10 + ch - '0';
		ch = getchar();
	}
	val *= isminus;
}
int main()
{

}