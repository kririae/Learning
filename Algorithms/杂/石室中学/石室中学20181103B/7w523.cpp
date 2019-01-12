#include <bits/stdc++.h>
using namespace std;

const int N = 60;
struct Card {
  int typ, v;
  Card() {}
  Card(int _t, int _v) : typ(_t), v(_v) {}
  // typ = 1 -> 单牌
  // typ = 2 -> 对子
  // typ = 3 -> 炸弹
  // typ = 4 -> 氢弹
  // typ = 5 -> 王炸
  // typ = 6 -> 碰后牌
  // typ = -1 -> 要不起
};
int n, pos, len, tot[5], rev[500], card[5][20], ans[5];  // 每个玩家有哪些牌
// pos -> 现在取到哪里了
char _s[N];
vector<int> order;
inline void addCard(int id, char type) { ++card[id][rev[type]]; }
inline char getTop() {
  if (pos >= len + 1)
    return -1;
  else
    return _s[++pos];
}
inline Card outFirst(int id) {
  for (int i = 0; i <= 11; ++i)
    if (card[id][i] == 2)
      return Card(2, i);
  for (int i = 0; i <= 11; ++i)
    if (card[id][i] == 1)
      return Card(1, i);
  if (card[id][12] && card[id][13]) {
    for (int i = 0; i <= 11; ++i)
      if (card[id][i] == 1)
        return Card(1, i);
    if (card[id][14] == 1)
      return Card(1, 14);
  } else {
    for (int i = 0; i <= 14; ++i)
      if (card[id][i] == 1)
        return Card(1, i);
  }
  if (card[id][7] == 2)
    return Card(2, 7);
  for (int i = 0; i <= 13; ++i)
    if (card[id][i] == 3)
      return Card(3, i);
  if (card[id][12] && card[id][13])
    return Card(5, 0);
  if (card[id][14] == 3)
    return Card(3, 14);
  for (int i = 0; i <= 14; ++i)
    if (card[id][i] == 4)
      return Card(4, i);
  return Card(-1, 0);
}
inline void erase(int x, Card y) {
  if (y.typ == 1)
    --card[x][y.v], --tot[x];
  if (y.typ == 2)
    card[x][y.v] -= 2, tot[x] -= 2;
  if (y.typ == 3)
    card[x][y.v] -= 3, tot[x] -= 3;
  if (y.typ == 4)
    card[x][y.v] -= 4, tot[x] -= 4;
  if (y.typ == 5)
    --card[x][12], --card[x][13], tot[x] -= 2;
}
inline Card follow(int id, Card pre) {
  // 第i个人要跟第pre张牌
  if (pre.typ == 6) {
    // 只能跟炸弹什么的
    for (int i = 0; i <= 11; ++i)
      if (card[id][i] == 3)
        return Card(3, i);
    if (card[id][12] && card[id][13])
      return Card(5, 0);
    if (card[id][14] == 3)
      return Card(3, 14);
    for (int i = 0; i <= 14; ++i)
      if (card[id][i] == 4)
        return Card(4, i);
    return Card(-1, 0);
  }
  if (pre.typ == 1) {
    for (int i = pre.v + 1; i <= 11; ++i)
      if (card[id][i] == 1)
        return Card(1, i);
    if (!(card[id][12] && card[id][13]))
      if (card[id][12] == 1)
        return Card(1, 12);
      else
        return Card(1, 13);
    if (card[id][14] == 1)
      return Card(1, 14);
    for (int i = 0; i <= 14; ++i)
      if (card[id][i] == 2)
        return Card(2, i);
    for (int i = 0; i <= 11; ++i)
      if (card[id][i] == 3)
        return Card(3, i);
    if (card[id][12] && card[id][13])
      return Card(5, 0);
    if (card[id][14] == 3)
      return Card(3, 14);
    for (int i = 0; i <= 14; ++i)
      if (card[id][i] == 4)
        return Card(4, i);
    return Card(-1, 0);
  }
  if (pre.typ == 2) {
    for (int i = pre.v + 1; i <= 14; ++i)
      if (card[id][i] == 2)
        return Card(2, i);
    for (int i = 0; i <= 11; ++i)
      if (card[id][i] == 3)
        return Card(3, i);
    if (card[id][12] && card[id][13])
      return Card(5, 0);
    if (card[id][14] == 3)
      return Card(3, 14);
    for (int i = 0; i <= 14; ++i)
      if (card[id][i] == 4)
        return Card(4, i);
    return Card(-1, 0);
  }
  if (pre.typ == 3) {
    for (int i = pre.v + 1; i <= 11; ++i)
      if (card[id][i] == 3)
        return Card(3, i);
    if (card[id][12] && card[id][13])
      return Card(5, 0);
    if (card[id][14] == 3)
      return Card(3, 14);
    for (int i = 0; i <= 14; ++i)
      if (card[id][i] == 4)
        return Card(4, i);
    return Card(-1, 0);
  }
  if (pre.typ == 4) {
    for (int i = pre.v; i <= 14; ++i)
      if (card[id][i] == 4)
        return Card(4, i);
    return Card(-1, 0);
  }
}
inline int check(char typ) {
  // 检查是否有能碰的
  for (int i = 1; i <= n; ++i)
    if (card[i][typ] == 2)
      return i;
  return -1;
}
inline void outputStatus() {
	for (int i = 1; i <= n; ++i) {
		printf("id: %d -> ", i);
		for (int j = 0; j <= 14; ++j)
			printf("%d ", card[i][j]);
		cout << endl;
	}
}
inline int work(int x) {
  // x -> 最先出牌
  printf("%d work the first\n", x);
  order.clear();
  for (int i = x; i <= n; ++i)
    order.push_back(i);
  for (int i = 1; i < x; ++i)
    order.push_back(i);
  Card pre = outFirst(x);
  printf("%d output %d with %d\n", x, pre.typ, pre.v);
  int preo = -1;  // 上次谁出
  erase(x, pre);
  int fflg = 1, fg = 0, curr = 0, cnt = 0;
  if (pre.typ == 1)
    ++cnt;
  else if (pre.typ == 2)
    cnt += 2;
  else if (pre.typ == 3)
    cnt += 3;
  else if (pre.typ == 3)
    cnt += 4;
  else if (pre.typ == 5)
    cnt += 2;
  else if (pre.typ == 6)
    cnt += 2;
  while (true) {
  	getchar();
    int tmp = 0;
    if (curr == n - 1)
      curr = 0;
    else
      ++curr;
    if (curr == preo) {
      // preo胜利了
      ans[order[curr]] += cnt;
      return order[curr];
    }
    if (pre.typ == 1 && ~check(pre.v)) {
      cnt += 2;
      tmp = check(pre.v);
      erase(tmp, Card(2, pre.v));
      printf("%d peng the card with type: %d, val: %d\n", tmp, 6, pre.v);
      if (tot[tmp] == 0 && pos == len + 1) {
        for (int i = 1; i <= n; ++i)
          for (int j = 0; j <= 14; ++j)
            ans[tmp] += card[i][j];
        return -1;
      }
      pre = Card(6, pre.v);
      preo = tmp;
    }
    if (fflg == 1) {
      fflg = 0;
      continue;
    }
    if (curr == preo) {
      // preo胜利了
      ans[order[curr]] += cnt;
      for (int i = 1; i <= n; ++i)
        for (int j = 1, x; j <= 5 - tot[i]; ++j) {
          ++tot[i];
          x = getTop();
          if (x == -1)
            continue;
          addCard(i, x);
        }
      return order[curr];
    }
    int id = order[curr];
    Card fl = follow(id, pre);
    if (~fl.typ) {
      printf("%d succeed in follow the card with typ: %d, val: %d\n", id, fl.typ, fl.v); 
      if (fl.typ == 1)
        ++cnt;
      else if (fl.typ == 2)
        cnt += 2;
      else if (fl.typ == 3)
        cnt += 3;
      else if (fl.typ == 3)
        cnt += 4;
      else if (fl.typ == 5)
        cnt += 2;
      else if (fl.typ == 6)
        cnt += 2;
      erase(id, fl);
      if (pos == len + 1 && tot[id] == 0) {
        // 结算
        for (int i = 1; i <= n; ++i)
          for (int j = 0; j <= 14; ++j)
            ans[id] += card[i][j];
        return -1;
      }
      pre = fl;
      preo = curr;
    }
  }
}
int main() {
  // freopen("7w523.in", "r", stdin);
  rev['4'] = 0;
  rev['6'] = 1;
  rev['8'] = 2;
  rev['9'] = 3;
  rev['X'] = 4;
  rev['J'] = 5;
  rev['Q'] = 6;
  rev['K'] = 7;
  rev['A'] = 8;
  rev['3'] = 9;
  rev['2'] = 10;
  rev['5'] = 11;
  rev['F'] = 12;
  rev['G'] = 13;
  rev['7'] = 14;
  scanf("%d%s", &n, _s + 1);
  len = strlen(_s + 1);
  // 牌型编号
  for (int i = 1; i <= 6; ++i)
    addCard(1, getTop());
  tot[1] = 6;
  for (int i = 2; i <= n; ++i) {
    tot[i] = 5;
    for (int j = 1; j <= 5; ++j)
      addCard(i, getTop());
  }
  cout << "AddCard Finished" << endl;
  outputStatus();
  int lst = 1;
  while (lst = ~work(lst)) getchar();
  for (int i = 1; i <= n; ++i)
    cout << ans[i] << endl;
}
