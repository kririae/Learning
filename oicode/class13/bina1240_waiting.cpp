#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int *list, *list_rep;
int n, m;
int search(int value) {
  list_rep = new int[n + 5];
  list_rep[0] = 0;
  for(int i = 0; i < 5; ++i) {
    int res = value - list[i + 1];
    list_rep[i + 1] = res > 0 ? res : -res;
  }
  int minn = list_rep[1];
  for(int i = 0; i < 5; ++i) {
    if(list_rep[i + 1] < minn) minn = i + 1;
  }
  if(value > list[n]) return list[n];
  if(value < list[1]) return list[1];
  return list[minn];
}
int main(){
  cin >> n;
  list = new int[n + 5];
  list[0] = 0;
  for(int i = 0; i < n; ++i)
    cin >> *(list + i + 1);
  cin >> m;
  sort(list, list + n);
  for(int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    cout << search(k);
  }
  return 0;
}
