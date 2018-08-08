#include <bits/stdc++.h>
#define ll long long
using namespace std;

int cnt = 1;
double p, last, w, s, lim = 1;
/*
last是上次不暴击的概率
w是这次暴击的概率
期望次数 = 每次都暴击的期望 * 当前的次数。
 */
int main()
{ 
  cin >> p; w = p; last = 1;
  while(w < lim) {
    s += last * w * cnt;
    last *= (1 - w), w += p;
    ++cnt;
  } s += last * cnt;
  cout << 1 / s << endl;
}