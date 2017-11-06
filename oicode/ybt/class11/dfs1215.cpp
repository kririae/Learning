#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 105;
int n;
char res[MAXN][MAXN];
bool if_true = false;
int ha,la,hb,lb;
void goPosition(int x, int y) {
	if(x > n || y > n || x < 0 || y < 0) return ;
	res[x][y] = '#';
	if(x == hb && y == lb){
		if_true = true;
	}
	if(!if_true){	
		if(res[x+1][y] == '.') goPosition(x+1,y);
		if(res[x][y+1] == '.') goPosition(x,y+1);
		if(x >= 1 && res[x-1][y] == '.') goPosition(x-1,y);	
		if(y >= 1 && res[x][y-1] == '.') goPosition(x,y-1);
		return ;
	}
	else return;
}
int main(){
	int times;
	cin>>times;
	for(int i = 0; i < times; ++i) {
		cin>>n;
		for(int x = 0; x < n; ++x) 
		scanf("%s",res[x]);
		cin>>ha>>la>>hb>>lb;
		if(res[ha][la]=='#' || res[hb][lb]=='#') cout<<"NO"<<endl;		
		else{
			goPosition(ha,la);
			if(if_true) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
			if_true = false;
		}
	}
	return 0;
}
