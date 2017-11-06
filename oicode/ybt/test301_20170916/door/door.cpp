//#define DEBUGGING
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int w, h, max_deep = 0;
int spacew, spaceh;
char roads[25][25];
bool wented[25][25];
#ifdef DEBUGGING
void printOut() {
	for(int i = 0; i < h; ++i) {
			for(int j = 0; j < w; ++j) 
				cout<<wented[i][j]<<" ";
			cout<<endl;
		}
}
#endif
void search(int x, int y, int deepth) {
	//x表示纵列上的位置，y表示横列上的位置
	//简单来说， x -> h; y -> w; 
	if(x > h - 1 || y > w - 1) return;
	max_deep = max(max_deep, deepth);
	if(x >= 1 && roads[x - 1][y] != '#') {
		roads[x][y] = '#';
		wented[x - 1][y] = true;
		search(x - 1, y, deepth + 1);
		roads[x][y] = '.';
	} 
	if(x < h - 1 && roads[x + 1][y] != '#') {
		roads[x][y] = '#';
		wented[x + 1][y] = true;
		search(x + 1, y, deepth + 1);
		roads[x][y] = '.';
	} 
	if(y >= 1 && roads[x][y - 1] != '#') {
		roads[x][y] = '#';
		wented[x][y - 1] = true;
		search(x, y - 1, deepth + 1);
		roads[x][y] = '.';
	} 
	if(y < w - 1 && roads[x][y + 1] != '#') {
		roads[x][y] = '#';
		wented[x][y + 1] = true;
		search(x, y + 1, deepth + 1);
		roads[x][y] = '.';
	} 
	return ;
}
int main() {
	freopen("door.in", "r", stdin);
	freopen("door.out", "w", stdout);
	cin >> w >> h;
	for(int i = 0; i < h; ++i) {
		scanf("%s",roads[i]);
		for(int j = 0; j < w; ++j) 
			if(roads[i][j] == '@') {
				spacew = i; spaceh = j;
			}
	}	
	for(int i = 0; i < 25; ++i) 
		for(int j = 0; j < 25; ++j) 
			wented[i][j]  = false;
	wented[spacew][spaceh] = true;
	#ifdef DEBUGGING
		cout<<"start space:"<<endl;
		printOut();
		cout<<endl;
	#endif
	search(spacew, spaceh, 1);
	int summ = 0;
	for(int i = 0; i < 25; ++i) 
		for(int j = 0; j < 25; ++j) 
			if(wented[i][j]) ++summ;
	#ifdef DEBUGGING
		cout<<"current:"<<endl;
		printOut();
		cout<<endl;
		cout<<"result:"<<endl;
	#endif
	cout<<summ;
	fclose(stdin);fclose(stdout);
	return 0;
}
