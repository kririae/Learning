#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
struct person { 
	int rp;
	string name;
	bool operator < (const person &a) const { 
		return rp<a.rp;
	} 
};
person ren[1230];
int main() { 
	srand(GetTickCount());
	ren[0].name="LLppdd";
	ren[1].name="Rockdu";
	ren[2].name="Watson";
	ren[3].name="Lvmaomao";
	ren[4].name="Zero";
	ren[5].name="Linners";
	ren[6].name="Zmy";
	for(int i=0;i<=6;++i) { 
		ren[i].rp=rand();
	} 
	sort(ren,ren+7);
	for(int i=0;i<7;++i) { 
		getchar();
		getchar();
		cout<<ren[i].name<<" "<<ren[i].rp;
		printf("\n");
	} 
	return 0;
} 
