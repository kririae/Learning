#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;

namespace File
{
int n, cnt = 1;
string tmp;
vector<string> qwq;

struct file_node
{
string name;
vector<int> son_index;
file_node() {}
file_node(string a) : name(a) {}

inline bool is_leaf()
{
  return son_index.size() == 0;
}
inline void add_node(int index)
{
  son_index.push_back(index);
}
} t[maxn];

inline int find_son_index(int index, string a)
{
  for (R int i = 0; i < t[index].son_index.size(); ++i)
    if(t[t[index].son_index[i]].name == a) return t[index].son_index[i];
  return -1;
}

bool cmp(int a, int b)
{
  return t[a].name < t[b].name;
}

inline void sort_son(int index)
{
  sort(t[index].son_index.begin(), t[index].son_index.end(), cmp);
}

inline void split(string a, vector<string>& ret)
{
  ret.clear();
  string tmp;
  for (R int i = 0; i < a.length(); ++i)
  {
    if(i == a.length() - 1) tmp += a[i], ret.push_back(tmp);
    if(a[i] == '/') ret.push_back(tmp), tmp.clear();
    else tmp += a[i];
  }
}

inline void add_node(vector<string> &a)
{
  int curr = 1;
  for (R int i = 1; i < a.size(); ++i)
  {
    int next = find_son_index(curr, a[i]);
    if(next == -1) 
      t[++cnt].name = a[i], t[curr].add_node(cnt), curr = cnt;
    else curr = next;
  }
}

inline void print(int k, int lay)
{
  if(k == 0) return;
  for (R int i = 1; i <= lay; ++i)
  {
    if(i != lay) cout << "|    ";
    else cout << "|";
  }
  if(k == 1) cout << t[k].name << endl;
  else cout << "----" << t[k].name << endl;
  sort_son(k);
  for (R int i = 0; i < t[k].son_index.size(); ++i)
    print(t[k].son_index[i], lay + 1);
}

inline void solve()
{
  freopen("file.in", "r", stdin);
  freopen("file.out", "w", stdout);
  cin.tie(0);
  cin >> n;
  for (R int i = 1; i <= n; ++i)
  {
    cin >> tmp;
    split(tmp, qwq);
    if(i == 1) t[1].name = qwq[0];
    add_node(qwq);
  }
  print(1, 0);
}
}

int main()
{
  return File::solve(), 0;
}
