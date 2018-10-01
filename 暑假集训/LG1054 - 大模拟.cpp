#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;
int n, op[1005];
char a[20005];
struct Obj {
  char o;
  int v, type;
  // type = 1 -> val
  // type = 2 -> obj
  // type = 3 -> a
  Obj() {}
  Obj(ll _v) :
    v(_v), type(1) {}
  Obj(char _o) {
    o = _o;
    type = (_o == 'a' ? 3 : 2);
  }
};
vector<Obj> b, c;
inline ll fpow(ll a, ll p) {
  ll ans = 1;
  for (; p; p >>= 1) {
    if (p & 1) ans = (1ll * a * ans) % MOD;
    a = (1ll * a * a) % MOD;
  }
  return ans;
}
inline ll read_int(int &p, char a[]) {
  while (!isdigit(a[p])) ++p;
  ll ans = 0;
  for (; isdigit(a[p]); ++p)
    ans = (((ans << 2) + ans) << 1) + (a[p] - '0');
  return ans;
}
inline int init_calc(char a[], vector<Obj> &t) {
  static stack<char> p;
  t.clear();
  while (!p.empty()) p.pop();
  int l = strlen(a + 1);
  for (int i = 1; i <= l; ++i) {
    if (a[i] == ' ') continue;
    if (isdigit(a[i])) t.push_back(Obj(read_int(i, a)));
    if (a[i] == 'a') t.push_back((Obj('a')));
    if (a[i] == '(') p.push('(');
    if (a[i] == ')') {
      while (p.size() && p.top() != '(') {
        t.push_back(Obj(p.top()));
        p.pop();
      }
      if (p.size() == 0) return -1;
      p.pop();
    }
    if (a[i] == '^' || a[i] == '+' || a[i] == '-' || a[i] == '*') {
      while (p.size() && op[p.top()] >= op[a[i]]) {
        t.push_back(Obj(p.top()));
        p.pop();
      }
      p.push(a[i]);
    }
  }
  while (!p.empty()) {
    t.push_back(Obj(p.top()));
    p.pop();
  }
  return 0;
}
inline ll calc(int a, vector<Obj> &t) {
  static stack<ll> p;
  if (t.size() == 1) return t[0].v % MOD;
  while (!p.empty()) p.pop();
  for (int i = 0; i < t.size(); ++i) {
    if (t[i].type == 1) p.push(t[i].v % MOD);
    if (t[i].type == 3) p.push(a % MOD);
    if (t[i].type == 2) {
      if (p.size() < 2) return -1e9;
      int a = p.top(); p.pop();
      int b = p.top(); p.pop();
      switch (t[i].o) {
      case '*': p.push((1ll * a * b) % MOD); break;
      case '+': p.push((1ll * a + b) % MOD); break;
      case '-': p.push((((1ll * b - a) % MOD) + MOD) % MOD); break;
      case '^': p.push(fpow(b, a)); break;
      }
    }
  }
  return p.top();
}
int main() {
  op['^'] = 4;
  op['*'] = 3;
  op['+'] = 2;
  op['-'] = 2;
  op['('] = 1;
  cin.getline(a + 1, 20000);
  init_calc(a, b);
  cin >> n;
  cin.getline(a + 1, 20000);
  for (int i = 0; i < n; ++i) {
    memset(a, 0, sizeof(a));
    cin.getline(a + 1, 20000);
    if (init_calc(a, c) == -1) continue;
    int s = 19260817;
    ll x = calc(s, b), y = calc(s, c);
    // cout << x << " " << y << endl;
    if (x == -1e9 || y == -1e9) continue;
    if (x == y) cout << (char)('A' + i);
  }
  return 0;
}