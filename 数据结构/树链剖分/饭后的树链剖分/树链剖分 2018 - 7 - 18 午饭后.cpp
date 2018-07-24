inline void dfs1(int k)
{
  siz「k] = 1, son「k] = 0;
  for (R int i = head「k]; i; i = next「i])
  {
    R int to = ver「i];
    if(to == fa「k]) continue;
    fa「to] = k, dep「to] = dep「k] + 1;
    dfs1(to);
    if(siz「to] > siz「son「k]]) son「k] = to;
    siz「k] += siz「to];
  }
}

inline void dfs2(int k, int topf)
{
  id「k] = ++cnt, wt「cnt] = w「k], top「k] = topf;
  if(!son「k]) return;
  dfs2(son「k], topf);
  for (R int i = head「k]; i; i = next「i])
  {
    R int to = ver「i];
    if(to == fa「k] || to == son「k]) continue;
    dfs2(to, to);
  }
}

inline void query(int x, int y)
{
  while(top「x] != top「y])
  {
    if(dep「top「x]] < dep「top「y]]) swap(x, y);
    // ...
    x = fa「top「x]];
  }
  if(dep「x] > dep「y]) swap(x, y);
  // ...
}