#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline int readInt(int &p, string a) {
  while (!isdigit(a[p])) ++p;
  ll ans = 0;
  for (; isdigit(a[p]); ++p)
    ans = (((ans << 2) + ans) << 1) + (a[p] - '0');
  return ans;
}
struct Cpx {
  int type, v;
};
struct Work {
int n, var[1005], typ[1005], trac[1005]; Cpx cpx;
string sta[105];
inline int Init() {
  for (int i = 0; i < 105; ++i)
    sta[i].clear();
  memset(var, 0, sizeof var);
  memset(typ, 0, sizeof typ);
  cpx.type = cpx.v = 0;
  n = 0;
  getline(cin, sta[0]);
  int pos = 0;
  n = readInt(pos, sta[0]);
  if (sta[0][pos + 3] == 'n')
    cpx.type = 2, cpx.v = readInt(pos, sta[0]);
  else
    cpx.type = 1;
  for (int i = 1; i <= n; ++i)
    getline(cin, sta[i]);
  return 0;
}
inline int Proc() {
  int layers = 0, jump = -1, jump_start = -1, cnt = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (layers == 0)
      cnt = 0, jump = jump_start = -1;
    if (sta[i][0] == 'E') {
      var[sta[trac[layers]][2]] = 0;
      --layers;
      if (layers < 0)
        return -1;
      if (jump == -1 && typ[trac[layers]] == 1) 
        --cnt,
        ans = max(ans, cnt);
      continue;
    }
    ++layers;
    trac[layers] = i;
    int pos = 3, x;
    if (sta[i][4] != 'n') {
      x = readInt(pos, sta[i]);
    } else
      x = 1e9, pos += 2;
    if (sta[i][pos + 1] != 'n') {
      int y = readInt(pos, sta[i]);
      if (x > y)
        if (jump == -1)
          jump = layers,
          jump_start = i;
    } else if (jump == -1 && x != 1e9)
      typ[i] = 1,
      ++cnt,
      ans = max(ans, cnt);
    if (var[sta[i][2]])
      return -1;
    else
      var[sta[i][2]] = 1;
    if (jump == layers && i != jump_start)
      jump = jump_start = -1;
  }
  if (layers != 0)
    return -1;
  return ans;
}
inline int Judge() {
  this->Init(); 
  int ret = this->Proc();
  if (ret == -1)
    return -1;
  if (ret == 0 && cpx.type == 1)
    return 1;
  else if (cpx.type == 2 && ret == cpx.v) 
    return 1;
  return 0;
}
} a;
int t;
int main() {
  string tmp;
  cin >> t;
  getline(cin, tmp);
  while (t--) {
    int ret = a.Judge();
    if (ret == 1)
      puts("Yes");
    if (ret == 0)
      puts("No");
    if (ret == -1)
      puts("ERR");
  }
}