#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 50005;
char s[N]; 
int n, a, b, curr; ll ans;
priority_queue<int> pq;
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '?') {
      scanf("%d%d", &a, &b);
      ans += b;
      --curr;
      pq.push(-(a - b));
    } else
      if(s[i] == '(') ++curr;
      else --curr;
    if (curr < 0) {
      if (pq.empty()) 
        return puts("-1"), 0;
      ans -= pq.top();
      pq.pop();
      curr += 2;
    }
  }
  if (curr > 0) 
    return puts("-1"), 0;
  printf("%d", ans);
}