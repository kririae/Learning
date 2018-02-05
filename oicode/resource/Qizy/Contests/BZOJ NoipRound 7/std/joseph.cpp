#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,k,i;
int main()
{
	freopen("joseph.in","r",stdin);
	freopen("joseph.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<n/k;i*=k);
	cout<<(n-i)/(k-1)*k<<endl;
	return 0;
}

