#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int r,s;
char input[600][30];
bool used[200];
int maxn = 0;
void search(int x, int y,int m){
	cout<<x<<" "<<y<<endl;
	if(m > maxn) maxn = m;
	if(x >= r || y >= s || x < 0 || y < 0) return;
	if(x < r  && y < s && x >= 0 && y >= 0){
		if(x < r - 1 && !used[input[x + 1][y]]) {
			used[input[x + 1][y]] = true;
			search(x + 1,y,m + 1);
			used[input[x + 1][y]] = false;
		}
		if(y < s - 1 && !used[input[x][y + 1]]){
			used[input[x][y + 1]] = true;
		 	search(x, y + 1,m + 1);
		 	used[input[x][y + 1]] = false;
		}
		if(x >= 1 && !used[input[x - 1][y]]) {
			used[input[x - 1][y]] = true;
			search(x - 1, y,m + 1);
			used[input[x - 1][y]] = false;
		}
		if(y >= 1 && !used[input[x][y - 1]]) {
			used[input[x][y - 1]] = true;
			search(x, y - 1,m + 1);
			used[input[x][y - 1]] = false;
		}
	}
	return ;
}
int main(){
	memset(used,false,sizeof(used));
	cin>>r>>s;
	for(int i = 0; i < r; ++i)
		scanf("%s",input[i]);
	search(0,0,0);
	cout<<maxn;
	return 0;
}