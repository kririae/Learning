#include<bits/stdc++.h>

#define LL long long
const int mod = 1e9 + 7;
using namespace std;

inline char read()
{
    static const int IN_LEN = 1000000;
    static char buf[IN_LEN], *s, *t;
    s == t ? t = (s = buf) +
                 fread(buf, 1, IN_LEN, stdin) : 0;
    return s == t ? -1 : *s++;
}

template <typename T>
inline void read(T &x)
{
    static char c;
    static bool iosig;
    for (c = read(), iosig = false;
            !isdigit(c); c = read())
    {
        if (c == -1) return;
        c == '-' ? iosig = true : 0;
    }
    for (x = 0; isdigit(c);
            c = read())
        x = (x + (x << 2) << 1) + (c ^ '0');
    iosig ? x = -x : 0;
}

//----------ͼ?----------------
struct medge
{
#define M 1000005
#define N 100005
    struct edge
    {
        int t, next;
    } e[M];
    int ecnt, head[N];
    void addedge(int f, int t)
    {
        e[++ecnt] = (edge)
        {
            t, head[f]
        };
        head[f] = ecnt;
        e[++ecnt] = (edge)
        {
            f, head[t]
        };
        head[t] = ecnt;
    }
    medge()
    {
        memset(head, 0, sizeof(head));
        ecnt = 0;
    }
#undef N
#undef M
};
//--????--
namespace Dinic
{
#define N 100005
#define M 300005
#define INF 0x3f3f3f3f
    struct edge
    {
        int flow, t, next;
    } e[M];
    int ecnt, head[N];
    void addedge(int f, int t, int fl)
    {
        e[++ecnt] = (edge)
        {
            fl, t, head[f]
        };
        head[f] = ecnt;
        e[++ecnt] = (edge)
        {
            0, f, head[t]
        };
        head[t] = ecnt;
    }
    //----------------
    int S, T;
    int dis[N], cur[N];
    bool BFS()
    {
        memset(dis, 0x3f, sizeof(dis));
        dis[S] = 0;
        queue<int> que;
        que.push(S);
        while(!que.empty())
        {
            int u = que.front();
            que.pop();
            for(int i = head[u]; i; i = e[i].next)
            {
                if(e[i].flow != 0 && dis[e[i].t] == 0x3f3f3f3f)
                {
                    dis[e[i].t] = dis[u] + 1, que.push(e[i].t);
                }
            }
        }
        return dis[T] != INF;
    }

    int DFS(int u, int a)
    {
        if(u == T || a == 0) return a;
        int ret = 0;
        for(int &i = cur[u]; i; i = e[i].next)
        {
            if(e[i].flow == 0 || dis[e[i].t] != dis[u] + 1) continue;
            int f = DFS(e[i].t, a < e[i].flow ? a : e[i].flow);
            if(f)
            {
                e[i].flow -= f;
                e[i ^ 1].flow += f;
                ret += f;
                a -= f;
                if(a == 0) return ret;
            }
        }
        return ret;
    }
    int work(int S1, int T1)
    {
        S = S1, T = T1;
        int ret = 0;
        while(BFS())
        {
            memcpy(cur, head, sizeof(cur));
            ret += DFS(S1, INF);
        }
        return ret;
    }
    void initialize()
    {
        ecnt = 1;
        memset(head, 0, sizeof(head));
    }
#undef N
#undef M
#undef INF
}
//------????--------
struct MincostFlow
{
#define N 1005
#define M 20505
#define INF 0x3f3f3f3f
    struct edge
    {
        int cost, flow, f, t, next;
    } e[M];
    int ecnt, head[N];
    void addedge(int f, int t, int flow, int cost)
    {
        e[++ecnt] = (edge)
        {
            cost, flow, f, t, head[f]
        };
        head[f] = ecnt;
        e[++ecnt] = (edge)
        {
            -cost, 0, t, f, head[t]
        };
        head[t] = ecnt;
    }
    int total_cost, inq[N], S, T, dis[N], fr[N];
    int SPFA(int mxf)
    {
        memset(dis, 0x3f, sizeof(dis));
        dis[S] = 0;
        queue<int> q;
        q.push(S);
        inq[S] = 1;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for(int i = head[u]; i; i = e[i].next)
            {
                if(e[i].flow > 0 && dis[e[i].t] > dis[u] + e[i].cost)
                {
                    dis[e[i].t] = dis[u] + e[i].cost;
                    fr[e[i].t] = i;
                    if(!inq[e[i].t]) inq[e[i].t] = 1, q.push(e[i].t);
                }
            }
        }
        if(dis[T] == 0x3f3f3f3f) return -1;
        int mx = mxf, p = T;
        while(fr[p]) mx = min(mx, e[fr[p]].flow), p = e[fr[p]].f;
        total_cost += dis[T] * mx;
        p = T;
        while(fr[p]) e[fr[p]].flow -= mx, e[fr[p] ^ 1].flow += mx, p = e[fr[p]].f;
        return mx;
    }
    int getCost(int maxflow, int S1, int T1)
    {
        S = S1, T = T1;
        total_cost = 0;
        while(maxflow)
        {
            int t = SPFA(maxflow);
            if(t == -1) break;
            maxflow -= t;
        }
        return total_cost;
    }
    MincostFlow()
    {
        ecnt = 1;
        memset(head, 0, sizeof(head));
        memset(inq, 0, sizeof(inq));
    }
#undef N
#undef M
#undef INF
};
//------------????---
namespace Dijkastra
{
    struct edge
    {
        int t, dis, next;
    } e[M * 2];
    int ecnt, head[N];
    void addedge(int f, int t, int dis)
    {
        e[++ecnt] = (edge)
        {
            t, dis, head[f]
        };
        head[f] = ecnt;
        e[++ecnt] = (edge)
        {
            f, dis, head[t]
        };
        head[t] = ecnt;
    }
    int dis[N], vis[N];
    struct pr
    {
        int t, dis;
        bool operator<(const pr &b)const
        {
            return dis > b.dis;
        }
    };
    priority_queue<pr> pq;
    void work(int S)
    {
        pq.push((pr)
        {
            S, 0
        });
        memset(dis, 0x3f, sizeof(dis));
        int tcnt = 0;
        dis[S] = 0;
        while(!pq.empty())
        {
            int u = pq.top().t, d = pq.top().dis;
            pq.pop();
            if(d != dis[u]) continue;
            for(int i = head[u]; i; i = e[i].next)
            {
                if(dis[e[i].t] > dis[u] + e[i].dis)
                {
                    dis[e[i].t] = dis[u] + e[i].dis;
                    pq.push((pr)
                    {
                        e[i].t, dis[e[i].t]
                    });
                }
            }
        }
    }
    void init()
    {
        ecnt = 1;
        memset(head, 0, sizeof(head));
    }
#undef N
#undef M
#undef INF
}
namespace SPFA //one-way road
{
#define N 200005
#define M 500005
#define INF 0x3f3f3f3f
    struct edge
    {
        int t, d, next;
    } e[M];
    int ecnt, head[N];
    void addedge(int f, int t, int d)
    {
        e[++ecnt] = (edge)
        {
            t, d, head[f]
        };
        head[f] = ecnt;
    }

    int dis[N], inq[N];
    deque<int> q;
    void SPFA(int S)
    {
        memset(dis, 0x3f, sizeof(dis));
        dis[S] = 0;
        q.push_back(S);
        inq[S] = 1;
        while(!q.empty())
        {
            int u = q.front();
            q.pop_front();
            inq[u] = 0;
            for(int i = head[u]; i; i = e[i].next)
                if(dis[e[i].t] > dis[u] + e[i].d)
                {
                    dis[e[i].t] = dis[u] + e[i].d;
                    if(!inq[e[i].t])
                    {
                        inq[e[i].t] = 1;
                        if(!q.empty() && dis[q.front()] > dis[e[i].t]) q.push_front(e[i].t);
                        else q.push_back(e[i].t);
                    }
                }
        }
    }
    void ini()
    {
        memset(head, 0, sizeof(head));
        ecnt = 0;
    }
#undef N
#undef M
#undef INF
};

//------֧??
namespace Domination_Tree
{
#define N 1000005
    struct edge
    {
        int t, next;
    } e[N * 4];
    int ecnt, head[N], head2[N];
    void addedge(int f, int t) //directional edge
    {
        e[++ecnt] = (edge)
        {
            t, head[f]
        };
        head[f] = ecnt;
        e[++ecnt] = (edge)
        {
            f, head2[t]
        };
        head2[t] = ecnt;
    }

    int idom[N], hfdom[N], st[N], DFSx[N], dcnt, fa[N]; //hfdom semi's dfs id
    vector<int> solve[N];
    void DFS(int u, int fr)
    {
        DFSx[st[u] = ++dcnt] = u;
        fa[u] = fr;
        for(int i = head[u]; i; i = e[i].next)
            if(st[e[i].t] == 0) DFS(e[i].t, u);
    }

    int bcj[N], mn[N];
    int ff(int x)
    {
        if(bcj[x] == x) return x;
        int t0 = bcj[x];
        bcj[x] = ff(t0);
        if(hfdom[mn[x]] > hfdom[mn[t0]]) mn[x] = mn[t0];
        return bcj[x];
    }

    void build_tree(int S, int n)
    {
        DFS(S, -1);
        for(int i = 1; i <= n; i++) bcj[i] = i, mn[i] = i, hfdom[i] = st[i];
        for(int k = dcnt; k >= 1; k--)
        {
            int u = DFSx[k];
            if(fa[u] == 0) continue;
            //find semi
            for(int i = head2[u]; i; i = e[i].next)
            {
                if(st[e[i].t] == 0) continue;
                if(st[e[i].t] > k)
                {
                    ff(e[i].t);
                    hfdom[u] = min(hfdom[u], hfdom[mn[e[i].t]]);
                }
                else
                {
                    hfdom[u] = min(hfdom[u], st[e[i].t]);
                }
            }
            solve[DFSx[hfdom[u]]].push_back(u);

            //find idom
            for(int i = 0; i < solve[u].size(); i++)
            {
                int v = solve[u][i];
                ff(v);
                if(mn[v] == v) idom[v] = v;
                else idom[v] = mn[v];
            }

            //update sons
            for(int i = head[u]; i; i = e[i].next)
            {
                if(fa[e[i].t] == u)
                {
                    bcj[e[i].t] = u;
                }
            }
        }
        idom[S] = 0;
        for(int i = 2; i <= n; i++)
        {
            int u = DFSx[i];
            if(idom[u] == u) idom[u] = DFSx[hfdom[u]];
            else idom[u] = idom[idom[u]];
        }
        for(int i = 1; i <= n; i++) if(fa[i] == 0) idom[i] = 0;
    }
#undef N
}
//---------2-SAT--------------
namespace SAT2
{
#define N1 3000005
#define M 12000005
    struct edge
    {
        int t, next;
    } e[M];
    int ecnt, head[N1], head_[N1]; //head_ reverse edge
    void addedge(int f, int t)
    {
        e[++ecnt] = (edge)
        {
            t, head[f]
        };
        head[f] = ecnt;
        e[++ecnt] = (edge)
        {
            f ^ 1, head[t ^ 1]
        };
        head[t ^ 1] = ecnt;
        e[++ecnt] = (edge)
        {
            f, head_[t]
        };
        head_[t] = ecnt;
        e[++ecnt] = (edge)
        {
            t ^ 1, head_[f ^ 1]
        };
        head_[f ^ 1] = ecnt;
    }
    int tp[N1], sta[N1], tp2[N1];
    int tcnt, ltcnt;
    void DFS1(int u, int col, int *h, const int &fl, const int &lim)
    {
        sta[u] = col;
        for(int i = h[u]; i; i = e[i].next)
        {
            if(sta[e[i].t] == lim) DFS1(e[i].t, col, h, fl, lim);
        }
        if(fl) tp[++tcnt] = u;
    }
    bool DFS2(int u, int col, int *h)
    {
        if(sta[u] == (col ^ 1)) return false;
        sta[u] = col;
        for(int i = h[u]; i; i = e[i].next)
        {
            if((sta[e[i].t]^col) == 1) return false;
            if(sta[e[i].t] != col)
                if(!DFS2(e[i].t, col, h)) return false;
        }
        return true;
    }
    bool solve(int n) //0-1  2-3
    {
        tcnt = 0;
        for(int i = 0; i < n * 2; i++)
            if(sta[i] == 0) DFS1(i, 1, head, 1, 0);
        for(int i = tcnt; i >= 1; i--)
            if(sta[tp[i]] == 1) DFS1(tp[i], -tp[i], head_, 0, 1), tp2[++ltcnt] = tp[i];
        for(int i = 0; i < n * 2; i += 2) if(sta[i] == sta[i ^ 1]) return false;
        for(int i = ltcnt; i >= 1; i--)
        {
            if(sta[tp2[i]] > 0) continue;
            DFS2(tp2[i], 2, head);
            if(!DFS2(tp2[i] ^ 1, 3, head_)) return false;
        }

        return true;
    }
#undef N1
#undef M
}
//------------???--------------
namespace Point_Divide_Tree
{
#define N 100005
    struct edge
    {
        int t, next;
    } e[N * 2];
    int ecnt, head[N];
    void addedge(int f, int t)
    {
        e[++ecnt] = (edge)
        {
            t, head[f]
        };
        head[f] = ecnt;
        e[++ecnt] = (edge)
        {
            f, head[t]
        };
        head[t] = ecnt;
    }
    int sz[N], c, vis[N], root;

    void findc(int u, int fr, int mxsz)
    {
        sz[u] = 1;
        int mxs = 0;
        for(int i = head[u]; i; i = e[i].next)
        {
            if(e[i].t != fr && vis[e[i].t] == 0)
            {
                findc(e[i].t, u, mxsz);
                mxs = max(mxs, sz[e[i].t]);
                sz[u] += sz[e[i].t];
            }
        }
        if(mxsz / 2 >= max(mxs, mxsz - sz[u])) c = u;
    }

    int fa[N], deep[N];

    void solve(int u, int size, int level)
    {
        vis[u] = 1;
        deep[u] = level;
        //-----solve your self
        for(int i = head[u]; i; i = e[i].next)
        {
            if(vis[e[i].t] == 0)
            {
                //work
            }
        }
        //-----solve your sons
        for(int i = head[u]; i; i = e[i].next)
        {
            if(vis[e[i].t] == 0)
            {
                int x = sz[e[i].t] >= sz[u] ? size - sz[u] : sz[e[i].t];
                findc(e[i].t, u, sz[e[i].t]);
                fa[c] = u;
                //do sth
                solve(c, x, level + 1);
            }
        }
    }

    void work(int n)
    {
        findc(1, 0, n);
        root = c;
        solve(c, n, 0);
    }
#undef N
}
//-----LCT--------
namespace LCT
{
#define N 100000
    const int L = 0, R = 1;
    struct node
    {
        int son[2];
        int rv, fa;
    } a[N];
#define nottop(x) (a[a[x].fa].son[L]==x||a[a[x].fa].son[R]==x)
    void pushdown(int k)
    {
        if(a[k].rv)
        {
            swap(a[k].son[R], a[k].son[L]);
            a[k].rv = 0;
            a[a[k].son[L]].rv ^= 1;
            a[a[k].son[R]].rv ^= 1;
        }
    }
    void rotate(const int &k, int &top)
    {
        int y = a[k].fa, z = a[y].fa, s = a[y].son[R] == k;
        a[y].son[s] = a[k].son[s ^ 1];
        a[a[k].son[s ^ 1]].fa = y;
        a[k].son[s ^ 1] = y;
        a[y].fa = k;
        a[k].fa = z;
        y == top ? top = k : a[z].son[a[z].son[R] == y] = k;
        //update(y);
    }
    void splay(const int &k, int &to) //Ҫ??֤aim????????
    {
        int aim = to;
        while(k != aim)
        {
            int y = a[k].fa, z = a[y].fa;
            pushdown(z);
            pushdown(y);
            pushdown(k);
            if(y != aim)
            {
                if((a[y].son[R] == k) ^ (a[z].son[R] == y)) rotate(k, aim);
                else rotate(y, aim);
            }
            rotate(k, aim);
        }
        to = k; //update(k);
    }
    inline void chg(int k, int rs) //change right son ??֮?????
    {
        int u = k;
        while(nottop(u)) u = a[u].fa;
        splay(k, u);
        pushdown(k);
        a[k].son[R] = rs; //update(k);
    }
    inline int access(int k) //return root
    {
        for(chg(k, 0); a[k].fa;)
        {
            chg(a[k].fa, k), k = a[k].fa;
        }//update(k);}
        int x = k;
        for(; pushdown(k), a[k].son[L] != 0; k = a[k].son[L]);
        return splay(k, x), k;
    }
    //#define cut(u,v) (a[access(u)].rv^=1,cut_right(u),a[v].fa=0) ->wrong
    inline void link(int x, int y)
    {
        a[y = access(y)].rv ^= 1, a[y].fa = x;
    }
    inline void cut(int x, int y)
    {
        chg(x, 0), chg(y, 0), a[y].fa == x ? a[y].fa = 0 : a[x].fa = 0;
    }
    inline bool iscon(int x, int y)
    {
        return access(x) == access(y);
    }
#undef N
}

//----------????-----------
namespace segtree
{
    struct msg
    {
        msg()
        {
        }
        msg operator +(const msg &b)
        {
            msg ret;
            return ret;
        }
        void pushdown(msg &son) //????ĸ??
        {
        }
    };
#define N 100005
    const int L = 0, R = 1;
    msg ini[N];
    struct xds
    {
        int son[2];
        msg x;
    } a[N * 2];
    int cnt;
    void build(int &k, int l, int r)
    {
        k = ++cnt;
        if(l == r)
        {
            a[k].x = ini[l];
        }
        else
        {
            int mid = (l + r) >> 1;
            build(a[k].son[L], l, mid);
            build(a[k].son[R], mid + 1, r);
            a[k].x = a[a[k].son[L]].x + a[a[k].son[R]].x;
        }
    }
    msg modify(int k, int l, int r, int ql, int qr, msg val)
    {
        if(ql == l && r == qr) return val.pushdown(a[k].x), a[k].x;
        else
        {
            a[k].x.pushdown(a[a[k].son[L]].x);
            a[k].x.pushdown(a[a[k].son[R]].x);
            int mid = (l + r) >> 1;
            msg ret;
            if(qr <= mid) ret = modify(a[k].son[L], l, mid, ql, qr, val);
            else if(ql > mid) ret = modify(a[k].son[R], mid + 1, r, ql, qr, val);
            else ret = modify(a[k].son[L], l, mid, ql, mid, val) + modify(a[k].son[R], mid + 1, r, mid + 1, qr, val);
            a[k].x = a[a[k].son[L]].x + a[a[k].son[R]].x;
            return ret;
        }
    }
#undef N
}

//----------?????------------
namespace GraphMatch
{
    //n=500 m=1e5 time:6ms
#define M 250010
    char inp[33554432], *inpch = inp;
    int Head[M], Next[M], Go[M], Pre[510], Nxt[510], F[510], S[510], Q[510], Vis[510],
        *Top = Q, Cnt = 0, Tim = 0, n, m, x, y;
    inline void addedge(int x, int y)
    {
        Go[++Cnt] = y;
        Next[Cnt] = Head[x];
        Head[x] = Cnt;
    }

    int find(int x)
    {
        return x == F[x] ? x : F[x] = find(F[x]);
    }

    int lca(int x, int y)
    {
        for(Tim++, x = find(x), y = find(y); ; x ^= y ^= x ^= y)
            if(x)
            {
                if(Vis[x] == Tim) return x;
                Vis[x] = Tim;
                x = find(Pre[Nxt[x]]);
            }
    }

    void blossom(int x, int y, int l)
    {
        while(find(x) != l)
        {
            Pre[x] = y, y = Nxt[x];
            if(S[y] == 1) S[*Top = y] = 0, *Top++;
            if(F[x] == x) F[x] = l;
            if(F[y] == y) F[y] = l;
            x = Pre[y];
        }
    }

    int Match(int x)
    {
        for(int i = 1; i <= n; i++) F[i] = i;
        memset(S, -1, sizeof (int) * (n + 5));
        S[*(Top = Q) = x] = 0, Top++;
        for(int *i = Q; i != Top; *i++)
            for(int T = Head[*i]; T; T = Next[T])
            {
                int g = Go[T];
                if(S[g] == -1)
                {
                    Pre[g] = *i, S[g] = 1;
                    if(!Nxt[g])
                    {
                        for(int u = g, v = *i, lst; v; u = lst, v = Pre[u])
                            lst = Nxt[v], Nxt[v] = u, Nxt[u] = v;
                        return 1;
                    }
                    S[*Top = Nxt[g]] = 0, *Top++;
                }
                else if(!S[g] && find(g) != find(*i))
                {
                    int l = lca(g, *i);
                    blossom(g, *i, l);
                    blossom(*i, g, l);
                }
            }
        return 0;
    }

    inline void Read(int &x)
    {
        x = 0;
        while(*inpch < '0') *inpch++;
        while(*inpch >= '0') x = x * 10 + *inpch++ - '0';
    }

    int solve()
    {
        fread(inp, 1, 33554432, stdin);
        Read(n), Read(m);
        for(int i = 1; i <= m; i++)
        {
            Read(x), Read(y);
            addedge(x, y);
            addedge(y, x);
        }
        int ans = 0;
        for(int i = n; i >= 1; i--)
            if(!Nxt[i]) ans += Match(i);
        printf("%d\n", ans);
        for(int i = 1; i <= n; i++) printf("%d ", Nxt[i]);
        putchar('\n');
        return 0;
    }
#undef M
}
//------------һ???????ƥ?--------------
namespace maxcostMatch
{
#define INF INT_MAX
#define MAXN 400
    struct edge
    {
        int u, v, w;
        edge() {}
        edge(int u, int v, int w): u(u), v(v), w(w) {}
    };
    int n, n_x;
    edge g[MAXN * 2 + 1][MAXN * 2 + 1];
    int lab[MAXN * 2 + 1];
    int match[MAXN * 2 + 1], slack[MAXN * 2 + 1], st[MAXN * 2 + 1], pa[MAXN * 2 + 1];
    int flower_from[MAXN * 2 + 1][MAXN + 1], S[MAXN * 2 + 1], vis[MAXN * 2 + 1];
    vector<int> flower[MAXN * 2 + 1];
    queue<int> q;
    inline int e_delta(const edge &e)  // does not work inside blossoms
    {
        return lab[e.u] + lab[e.v] - g[e.u][e.v].w * 2;
    }
    inline void update_slack(int u, int x)
    {
        if(!slack[x] || e_delta(g[u][x]) < e_delta(g[slack[x]][x]))slack[x] = u;
    }
    inline void set_slack(int x)
    {
        slack[x] = 0;
        for(int u = 1; u <= n; ++u)
            if(g[u][x].w > 0 && st[u] != x && S[st[u]] == 0)update_slack(u, x);
    }
    void q_push(int x)
    {
        if(x <= n)q.push(x);
        else for(size_t i = 0; i < flower[x].size(); i++)q_push(flower[x][i]);
    }
    inline void set_st(int x, int b)
    {
        st[x] = b;
        if(x > n)for(size_t i = 0; i < flower[x].size(); ++i)
                set_st(flower[x][i], b);
    }
    inline int get_pr(int b, int xr)
    {
        int pr = find(flower[b].begin(), flower[b].end(), xr) - flower[b].begin();
        if(pr % 2 == 1) //?z????ǰһ?ӈD???c߀?ż?c
        {
            reverse(flower[b].begin() + 1, flower[b].end());
            return (int)flower[b].size() - pr;
        }
        else return pr;
    }
    inline void set_match(int u, int v)
    {
        match[u] = g[u][v].v;
        if(u > n)
        {
            edge e = g[u][v];
            int xr = flower_from[u][e.u], pr = get_pr(u, xr);
            for(int i = 0; i < pr; ++i)set_match(flower[u][i], flower[u][i ^ 1]);
            set_match(xr, v);
            rotate(flower[u].begin(), flower[u].begin() + pr, flower[u].end());
        }
    }
    inline void augment(int u, int v)
    {
        for(;;)
        {
            int xnv = st[match[u]];
            set_match(u, v);
            if(!xnv)return;
            set_match(xnv, st[pa[xnv]]);
            u = st[pa[xnv]], v = xnv;
        }
    }
    inline int get_lca(int u, int v)
    {
        static int t = 0;
        for(++t; u || v; swap(u, v))
        {
            if(u == 0)continue;
            if(vis[u] == t)return u;
            vis[u] = t; //??N??????Բ???????
            u = st[match[u]];
            if(u)u = st[pa[u]];
        }
        return 0;
    }
    inline void add_blossom(int u, int lca, int v)
    {
        int b = n + 1;
        while(b <= n_x && st[b])++b;
        if(b > n_x)++n_x;
        lab[b] = 0, S[b] = 0;
        match[b] = match[lca];
        flower[b].clear();
        flower[b].push_back(lca);
        for(int x = u, y; x != lca; x = st[pa[y]])
            flower[b].push_back(x), flower[b].push_back(y = st[match[x]]), q_push(y);
        reverse(flower[b].begin() + 1, flower[b].end());
        for(int x = v, y; x != lca; x = st[pa[y]])
            flower[b].push_back(x), flower[b].push_back(y = st[match[x]]), q_push(y);
        set_st(b, b);
        for(int x = 1; x <= n_x; ++x)g[b][x].w = g[x][b].w = 0;
        for(int x = 1; x <= n; ++x)flower_from[b][x] = 0;
        for(size_t i = 0; i < flower[b].size(); ++i)
        {
            int xs = flower[b][i];
            for(int x = 1; x <= n_x; ++x)
                if(g[b][x].w == 0 || e_delta(g[xs][x]) < e_delta(g[b][x]))
                    g[b][x] = g[xs][x], g[x][b] = g[x][xs];
            for(int x = 1; x <= n; ++x)
                if(flower_from[xs][x])flower_from[b][x] = xs;
        }
        set_slack(b);
    }
    inline void expand_blossom(int b)  // S[b] == 1
    {
        for(size_t i = 0; i < flower[b].size(); ++i)
            set_st(flower[b][i], flower[b][i]);
        int xr = flower_from[b][g[b][pa[b]].u], pr = get_pr(b, xr);
        for(int i = 0; i < pr; i += 2)
        {
            int xs = flower[b][i], xns = flower[b][i + 1];
            pa[xs] = g[xns][xs].u;
            S[xs] = 1, S[xns] = 0;
            slack[xs] = 0, set_slack(xns);
            q_push(xns);
        }
        S[xr] = 1, pa[xr] = pa[b];
        for(size_t i = pr + 1; i < flower[b].size(); ++i)
        {
            int xs = flower[b][i];
            S[xs] = -1, set_slack(xs);
        }
        st[b] = 0;
    }
    inline bool on_found_edge(const edge &e)
    {
        int u = st[e.u], v = st[e.v];
        if(S[v] == -1)
        {
            pa[v] = e.u, S[v] = 1;
            int nu = st[match[v]];
            slack[v] = slack[nu] = 0;
            S[nu] = 0, q_push(nu);
        }
        else if(S[v] == 0)
        {
            int lca = get_lca(u, v);
            if(!lca)return augment(u, v), augment(v, u), true;
            else add_blossom(u, lca, v);
        }
        return false;
    }
    inline bool matching()
    {
        memset(S + 1, -1, sizeof(int)*n_x);
        memset(slack + 1, 0, sizeof(int)*n_x);
        q = queue<int>();
        for(int x = 1; x <= n_x; ++x)
            if(st[x] == x && !match[x])pa[x] = 0, S[x] = 0, q_push(x);
        if(q.empty())return false;
        for(;;)
        {
            while(q.size())
            {
                int u = q.front();
                q.pop();
                if(S[st[u]] == 1)continue;
                for(int v = 1; v <= n; ++v)
                    if(g[u][v].w > 0 && st[u] != st[v])
                    {
                        if(e_delta(g[u][v]) == 0)
                        {
                            if(on_found_edge(g[u][v]))return true;
                        }
                        else update_slack(u, st[v]);
                    }
            }
            int d = INF;
            for(int b = n + 1; b <= n_x; ++b)
                if(st[b] == b && S[b] == 1)d = min(d, lab[b] / 2);
            for(int x = 1; x <= n_x; ++x)
                if(st[x] == x && slack[x])
                {
                    if(S[x] == -1)d = min(d, e_delta(g[slack[x]][x]));
                    else if(S[x] == 0)d = min(d, e_delta(g[slack[x]][x]) / 2);
                }
            for(int u = 1; u <= n; ++u)
            {
                if(S[st[u]] == 0)
                {
                    if(lab[u] <= d)return 0;
                    lab[u] -= d;
                }
                else if(S[st[u]] == 1)lab[u] += d;
            }
            for(int b = n + 1; b <= n_x; ++b)
                if(st[b] == b)
                {
                    if(S[st[b]] == 0)lab[b] += d * 2;
                    else if(S[st[b]] == 1)lab[b] -= d * 2;
                }
            q = queue<int>();
            for(int x = 1; x <= n_x; ++x)
                if(st[x] == x && slack[x] && st[slack[x]] != x && e_delta(g[slack[x]][x]) == 0)
                    if(on_found_edge(g[slack[x]][x]))return true;
            for(int b = n + 1; b <= n_x; ++b)
                if(st[b] == b && S[b] == 1 && lab[b] == 0)expand_blossom(b);
        }
        return false;
    }
    inline pair<long long, int> weight_blossom()
    {
        memset(match + 1, 0, sizeof(int)*n);
        n_x = n;
        int n_matches = 0;
        long long tot_weight = 0;
        for(int u = 0; u <= n; ++u)st[u] = u, flower[u].clear();
        int w_max = 0;
        for(int u = 1; u <= n; ++u)
            for(int v = 1; v <= n; ++v)
            {
                flower_from[u][v] = (u == v ? u : 0);
                w_max = max(w_max, g[u][v].w);
            }
        for(int u = 1; u <= n; ++u)lab[u] = w_max;
        while(matching())++n_matches;
        for(int u = 1; u <= n; ++u)
            if(match[u] && match[u] < u)
                tot_weight += g[u][match[u]].w;
        return make_pair(tot_weight, n_matches);
    }
    inline void init_weight_graph()
    {
        for(int u = 1; u <= n; ++u)
            for(int v = 1; v <= n; ++v)
                g[u][v] = edge(u, v, 0);
    }
    int solve()
    {
        int m;
        scanf("%d%d", &n, &m);
        init_weight_graph();
        for(int i = 0; i < m; ++i)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            g[u][v].w = g[v][u].w = w;
        }
        printf("%lld\n", weight_blossom().first);
        for(int u = 1; u <= n; ++u)printf("%d ", match[u]);
        puts("");
        return 0;
    }
}
//--------?ѧ???-----------
namespace ex_gcd
{
    int exgcd(int a0, int a1, int x0, int x1)
    {
        if(x0 == 1) return a0;
        if(x1 == 1) return a1;
        int t = x1 / x0;
        return exgcd(a1 - t * a0, a0, x1 - t * x0, x0);
    }
    int get_rv(int k, int mods)
    {
        return (exgcd(1, 0, k, mods) % mods + mods) % mods;
    }
};
struct Combin
{
#define N 1000005
    int fac[N], rv[N], facrv[N];
    Combin()
    {
        fac[0] = rv[1] = facrv[0] = 1;
        for(int i = 2; i < N; i++) rv[i] = ((-(mod / i) * 1LL * rv[mod % i] % mod) + mod) % mod;
        for(int i = 1; i < N; i++) fac[i] = 1LL * fac[i - 1] * i % mod;
        for(int i = 1; i < N; i++) facrv[i] = 1LL * facrv[i - 1] * rv[i] % mod;
    }
    int C(int r1, int n1)
    {
        if(r1 > n1) return 0;
        return fac[n1] * 1LL * facrv[r1] % mod * facrv[n1 - r1] % mod;
    }
#undef N
};
#define M 2
struct matrix
{
    int a[M][M];
    matrix()
    {
        memset(a, 0, sizeof(a));
    }
    matrix(int v[M][M])
    {
        memcpy(a, v, sizeof(a));
    }
    int *operator [](int id)
    {
        return a[id];
    }
    matrix one()
    {
        matrix ret;
        for(int i = 0; i < M; i++) ret.a[i][i] = 1;
        return ret;
    }
    matrix operator *(const matrix &b)
    {
        matrix ret;
        for(int i = 0; i < M; i++)
            for(int j = 0; j < M; j++)
                for(int k = 0; k < M; k++)
                    ret.a[i][k] = (ret.a[i][k] + a[i][j] * 1LL * b.a[j][k]) % mod;
        return ret;
    }
    matrix operator ^(int k)
    {
        matrix ret = one(), t = *this;
        while(k)
        {
            if(k & 1) ret = ret * t;
            t = t * t;
            k >>= 1;
        }
        return ret;
    }
};
#undef M
#define N 1005
struct bi_matrix
{
    bitset<N> a[N];
    bi_matrix()
    {
        memset(a, 0, sizeof(a));
    }
    int *operator [](int id)
    {
        return a[id];
    }
    bi_matrix E()
    {
        bi_matrix ret;
        for(int i = 0; i < N; i++) ret.a[i][i] = 1;
        return ret;
    }
    bi_matrix getrev()
    {
        bi_matrix ret = ret.E(), t = *this;
        for(int i = 0; i < N; i++)
        {
            int now = 0;
            for(int j = i; j < N; j++)
                if(t.a[j][i] != 0)
                {
                    now = j;
                    break;
                }
            if(i != now) swap(t.a[i], t.a[now]), swap(ret.a[i], ret.a[now]);
            for(int j = 0; j < N; j++)
                if(t.a[j][i] && j != i)
                    t.a[j] ^= t.a[i], ret.a[j] ^= ret.a[i];
        }
        return ret;
    }
};
#undef N
int fastpow(int x, int a)
{
    int ret = 1;
    while(a)
    {
        if(a & 1) ret = 1LL * ret * x % mod;
        x = 1LL * x * x % mod;
        a >>= 1;
    }
    return ret;
}
#define rev(x) (fastpow((x)%mod,mod-2))

template <typename T>
T fastpow(T initial, T x, LL power)
{
    while(power)
    {
        if(power & 1) initial = initial * x;
        x = x * x;
        power >>= 1;
    }
    return initial;
}

int miu(int x)
{
    if(x == 1) return 1;
    int cnt = 0;
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
        {
            x /= i;
            cnt++;
            if(x % i == 0) return 0;
        }
    }
    if(x != 1) cnt++;
    return cnt & 1 ? -1 : 1;
}
struct pre_miu
{
#define N 1000005
    int miu[N], prime[N], check[N], pcnt;
    void prework()
    {
        miu[1] = 1;
        for(int i = 2; i < N; i++)
        {
            if(check[i] == 0) prime[++pcnt] = i, miu[i] = -1;
            for(int j = 1, t; j <= pcnt && (t = prime[j] * i) < N; j++)
            {
                miu[t] = -miu[i];
                check[t] = 1;
                if(i % prime[j] == 0)
                {
                    miu[t] = 0;
                    break;
                }
            }
        }
    }
#undef N
};

//1e5*1e5 -> 25ms
namespace myyFFT
{
#define N ((1<<17)+1)
    const double pi = acos(-1.0);
    struct cp
    {
        double a, b;
        cp operator +(const cp &o)const
        {
            return (cp)
            {
                a + o.a, b + o.b
            };
        }
        cp operator -(const cp &o)const
        {
            return (cp)
            {
                a - o.a, b - o.b
            };
        }
        cp operator *(const cp &o)const
        {
            return (cp)
            {
                a *o.a - b *o.b, b *o.a + a *o.b
            };
        }
        cp operator *(const double &o)const
        {
            return (cp)
            {
                a *o, b *o
            };
        }
        cp operator !()const
        {
            return (cp)
            {
                a, -b
            };
        }
    } x[N], y[N], z[N], w[N];
    void fft(cp x[], int k, int v)
    {
        for(int i = 0, j = 0; i < k; i++)
        {
            if(i > j)swap(x[i], x[j]);
            for(int l = k >> 1; (j ^= l) < l; l >>= 1);
        }
        w[0] = (cp)
        {
            1, 0
        };
        for(int i = 2; i <= k; i <<= 1)
        {
            cp g = (cp)
            {
                cos(2 * pi / i), (v ? -1 : 1)*sin(2 * pi / i)
            };
            for(int j = (i >> 1); j >= 0; j -= 2)w[j] = w[j >> 1];
            for(int j = 1; j<i >> 1; j += 2)w[j] = w[j - 1] * g;
            for(int j = 0; j < k; j += i)
            {
                cp *a = x + j, *b = a + (i >> 1);
                for(int l = 0; l<i >> 1; l++)
                {
                    cp o = b[l] * w[l];
                    b[l] = a[l] - o;
                    a[l] = a[l] + o;
                }
            }
        }
        if(v)for(int i = 0; i < k; i++)x[i] = (cp)
            {
                x[i].a / k, x[i].b / k
            };
    }

    void solve(vector<int> a, vector<int> b, vector<int> &c)
    {
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        int sz = (a.size() + b.size() - 1);
        for(int i = 0; i < a.size(); i++)(i & 1 ? x[i >> 1].b : x[i >> 1].a) = a[i];
        for(int i = 0; i < b.size(); i++)(i & 1 ? y[i >> 1].b : y[i >> 1].a) = b[i];
        int K;
        for(K = 1; K <= (sz - 1) >> 1; K <<= 1);
        fft(x, K, 0);
        fft(y, K, 0);
        for(int i = 0; i < K; i++)
        {
            int j = K - 1 & K - i;
            z[i] = (x[i] * y[i] * 4 - (x[i] - !x[j]) * (y[i] - !y[j]) *
                    (((i & K >> 1) ? (cp)
            {
                1, 0
            } -w[i ^ K >> 1]: w[i] + (cp)
            {
                1, 0
            }))) * 0.25;
        }
        fft(z, K, 1);
        c.resize(sz);
        for(int i = 0; i < sz; i++)
            if(i & 1) c[i] = (int)(z[i >> 1].b + 0.1);
            else c[i] = (int)(z[i >> 1].a + 0.1);
    }
#undef N
}

namespace FFT
{
#define N ((1<<18)+3)
#define DB double
    struct cp
    {
        DB r, i;
        cp operator +(const cp &b)
        {
            return (cp)
            {
                r + b.r, i + b.i
            };
        }
        cp operator -(const cp &b)
        {
            return (cp)
            {
                r - b.r, i - b.i
            };
        }
        cp operator *(const cp &b)
        {
            return (cp)
            {
                r *b.r - i *b.i, r *b.i + i *b.r
            };
        }
    };
    int len, rv[N];
    cp wnx[N * 2], *wn;
    void FFT(cp *x, int f)
    {
        for(int i = 1; i < len; i++) if(i < rv[i]) swap(x[i], x[rv[i]]);
        for(int i = 2; i <= len; i <<= 1)
        {
            int hf = i / 2, d = len / i * f;
            for(int j = 0; j < len; j += i)
            {
                for(int k = j, p = 0; k < j + hf; k++, p += d)
                {
                    cp u = x[k], v = x[k + hf] * wn[p];
                    x[k] = u + v;
                    x[k + hf] = u - v;
                }
            }
        }
    }

    void pre(int size) // x^size
    {
        len = 1;
        while(len < size) len <<= 1;
        for(int i = 1; i < len; i++) rv[i] = (rv[i >> 1] >> 1) + (i & 1) * len / 2;
        DB pi = acos(-1);
        cp w = (cp)
        {
            cos(pi * 2 / len), sin(pi * 2 / len)
        };
        wn = wnx + N;
        wn[0] = (cp)
        {
            1, 0
        };
        for(int i = 1; i < len; i++) wn[i - len] = wn[i] = wn[i - 1] * w;
    }

    cp A[N], B[N];
    void solve(vector<int> a, vector<int> b, vector<int> &c)
    {
        memset(A, 0, sizeof(A)), memset(B, 0, sizeof(B));
        for(int i = 0; i < a.size(); i++) A[i].r = a[i];
        for(int i = 0; i < b.size(); i++) B[i].r = b[i];
        int sz = (a.size() + b.size() - 1);
        if(sz > len || sz * 2 < len) pre(sz);
        FFT(A, 1);
        FFT(B, 1);
        for(int i = 0; i < len; i++) A[i] = A[i] * B[i];
        FFT(A, -1);
        c.resize(sz);
        for(int i = 0; i < sz; i++) c[i] = (A[i].r / len + 0.5);
    }
#undef DB
#undef N
};
namespace NTT
{
#define N ((1<<18)+3)
    const int mod = 998244353;
    const int base = 3;
    int wn[N + N];
    int rv[N];
    int len;
    int fastpow(int w, int x)
    {
        int ret = 1;
        while(x)
        {
            if(x & 1) ret = ret * 1LL * w % mod;
            w = w * 1LL * w % mod;
            x >>= 1;
        }
        return ret;
    }
    void NTT(vector<int> &x, int len, int f)
    {
        for(int i = 0; i < len; i++) if(i < rv[i]) swap(x[i], x[rv[i]]);
        for(int i = 2, d = (len >> 1) * f; i <= len; i <<= 1, d /= 2)
        {
            for(int j = 0; j < len; j += i)
            {
                int *x1 = &x[0] + j, *x2 = &x[0] + j + (i >> 1), *w = wn + N;
                long long t1;
                for(int p = 0, t = i >> 1; p < t; p++, w += d)
                {
                    x2[p] = (x1[p] - (t1 = (1LL * x2[p] * (*w)))) % mod;
                    x1[p] = (x1[p] + t1) % mod;
                }
            }
        }
    }

    void pre(int tot) //??????????+1??
    {
        len = 1;
        while((1 << len) < tot) len++;
        for(int i = 1; i < (1 << len); i++) rv[i] = (rv[i >> 1] >> 1) | ((i & 1) << (len - 1));
        wn[N] = 1;
        int w = fastpow(base, (mod - 1) >> len);
        len = 1 << len;
        int rv = fastpow(w, mod - 2);
        for(int i = 1; i < len; i++) wn[N + i] = (1LL * wn[N + i - 1] * w) % mod;
        for(int i = N - 1; i >= N - len; i--) wn[i] = (1LL * wn[i + 1] * rv) % mod;
    }
    void solve(vector<int> a, vector<int> b, vector<int> &c)
    {
        int sz = a.size() + b.size() - 1;
        if(len < sz || sz * 2 < len) pre(sz);
        a.resize(len), b.resize(len);
        NTT(a, len, 1);
        NTT(b, len, 1);
        for(int i = 0; i < len; i++) a[i] = (1LL * a[i] * b[i]) % mod;
        NTT(a, len, -1);
        int rl = fastpow(len, mod - 2);
        c.resize(sz);
        for(int i = 0; i < sz; i++) c[i] = ((a[i] * 1LL * rl) % mod + mod) % mod;

    }
#undef N
}

struct poly
{
    vector<int> a;
    poly() {}
    poly(int size)
    {
        a.resize(size + 1, 0);
    }
    inline int &operator [](int id)
    {
        return a[id];
    }
    int size()
    {
        return a.size() - 1;
    }
    void pop0()
    {
        int p = size();
        while(p >= 0 && !a[p])p--;
        a.resize(p + 1);
    }
};
poly operator * (const poly &a, const poly &b)
{
    poly ret;
    NTT::solve(a.a, b.a, ret.a);
    return ret;
}

//--Simplex-------------------
namespace Simplex
{
#define N 55
#define eps 1e-8
#define LD double

    LD A[N][N];
    int Base[N];//1-m
    int out[N];
    int n, m, T;

    //-----------------------------------------
    void pivot(int h, int x) //???????????
    {
        Base[h] = x;
        LD t = A[h][x];
        for(int i = 0; i <= n; i++) A[h][i] /= t;
        for(int i = 0; i <= m; i++)
        {
            if((A[i][x] < eps && A[i][x] > -eps) || i == h) continue;
            t = A[i][x];
            for(int j = 0; j <= n; j++) A[i][j] -= A[h][j] * t;
        }
    }
    bool Initial()
    {
        int h, x;
        LD t;
        while(1)
        {
            h = 0, x = 0;
            t = eps;
            for(int i = 1; i <= m; i++) if(A[i][0] > t) t = A[h = i][0];
            if(h == 0) return true;
            t = -eps; //??ʼ??000
            for(int j = 1; j <= n; j++) if(A[h][j] < t)
                {
                    t = A[h][x = j];
                    if(rand() % 3)break;
                }
            if(x == 0) return false; //because xi>=0
            pivot(h, x);
        }
    }
    bool Simplex()
    {
        int h, x;
        LD t;
        while(1)
        {
            h = x = 0;
            t = 1e10; //????randһ?
            for(int i = 1; i <= n; i++) if(A[0][i] > eps)
                {
                    x = i;
                    break;
                }
            if(x == 0) return true;
            for(int i = 1; i <= m; i++) if(A[i][x] > eps && -A[i][0] / A[i][x] < t) t = -A[i][0] / A[h = i][x];
            if(h == 0) return false;
            pivot(h, x);
        }
    }
    //-----------------------------------------
    void read()
    {
        scanf("%d%d%d", &n, &m, &T);
        for(int i = 1, t; i <= n; i++) scanf("%d", &t), A[0][i] = t;
        for(int i = 1, t; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                scanf("%d", &t);
                A[i][j] = t;
            }
            scanf("%d", &t);
            A[i][0] = -t;
        }
        for(int i = n + 1; i <= n + m; i++) A[i - n][i] = 1;
        for(int i = 1; i <= m; i++) Base[i] = i + n;
        n = n + m;
    }
    int main()
    {
        read();
        if(!Initial()) return puts("Infeasible"), 0;
        if(!Simplex()) return puts("Unbounded"), 0;
        printf("%.8lf\n", A[0][0]);
        if(T)
        {
            for(int i = 1; i <= m; i++) out[Base[i]] = i;
            for(int i = 1; i <= n - m; i++)
                printf("%.8lf ", (out[i] == 0 ? 0 : -A[out[i]][0]));
        }
        return 0;
    }
#undef N
#undef eps
#undef LD
}
//-----------?????-----------
struct Suffix_Automation
{

};
namespace Suffix_Array
{
#define IL inline
#define REP(a,b,c) for(a=b;a<=c;a++)
    const int BufS = 1200000;
    const int N = 100005, SN = N << 1, NL = 26, NC = 256;
    char buf[BufS], *out = buf, s[N];
    int n;
    int subtr[SN], broSubtr[SN];
    IL void pt(int a)
    {
        int num[10], top = 0;
        if(!a)
        {
            *out++ += '0';
            *out++ = ' ';
            return;
        }
        else
        {
            while(a)num[top++] = a % 10, a /= 10;
            while(top--)*out++ = num[top] + '0';
            *out++ = ' ';
        }
    }
    IL void addEdge(int u, int v)
    {
        broSubtr[v] = subtr[u], subtr[u] = v;
    }
    int last = 1, tail = 1, next[SN][NL], len[SN], pos[SN], right[SN], fail[SN];
    IL void sa_extend(int c, int r)
    {
        int p = last, np = last = ++tail;
        right[np] = len[np] = len[p] + 1, pos[np] = r;
        while(p && !next[p][c])
            next[p][c] = np, p = fail[p];
        if(!p)fail[np] = 1;
        else
        {
            int q = next[p][c];
            if(len[q] == len[p] + 1)fail[np] = q;
            else
            {
                int nq = ++tail;
                len[nq] = len[p] + 1, right[nq] = right[q]; //the distinguish betweern right and len
                memcpy(next[nq], next[q], sizeof(next[q]));
                fail[nq] = fail[q], fail[q] = fail[np] = nq;
                while(next[p][c] == q)
                    next[p][c] = nq, p = fail[p];
            }
        }
    }
    int sa_n, sa[N], rank[N], height[N], up[N], w[NC], ver[SN];
    IL void dfs(int x)
    {
        if(pos[x])sa[++sa_n] = pos[x];
        int v;
        for(v = subtr[x]; v; v = broSubtr[v])
            dfs(v);
    }
    IL void sa_init()
    {
        int i, j, h = 0;
        for(i = n; i; i--) //reverse and insert
            sa_extend(s[i] - 'a', i);
        REP(i, 1, tail)
        {
            up[i] = s[n + 1 - right[i] + len[fail[i]]];
            ++w[up[i]];
        }
        REP(i, 1, 'z')
        w[i] += w[i - 1];
        for(i = tail; i; i--) //rnak
            ver[w[up[i]]--] = i;
        for(i = tail; i >= 2; i--)
            addEdge(fail[ver[i]], ver[i]);
        dfs(1);//getsa
        REP(i, 1, n) //getrank
        rank[sa[i]] = i;
        REP(i, 1, n) //getheight
        {
            if(h)--h;//at most decrease
            j = sa[rank[i] - 1];
            while(s[i + h] == s[j + h])++h;
            height[rank[i]] = h;
        }
        REP(i, 1, n)pt(sa[i]);
        *out++ = '\n';
        REP(i, 2, n)pt(height[i]);
    }
    int main()
    {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        sa_init();
        fwrite(buf, 1, out - buf, stdout);
        return 0;
    }
}
//------------??�??-------
#define db double
#define eps 1e-8
struct point
{
    db x, y;
};
point operator +(point a, point b)
{
    return (point)
    {
        a.x + b.x, a.y + b.y
    };
}
point operator -(point a, point b)
{
    return (point)
    {
        a.x - b.x, a.y - b.y
    };
}
bool operator <(const point &a, const point &b)
{
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}
db operator *(point a, point b)
{
    return a.x * b.y - b.x * a.y;
}
point operator *(point a, db x)
{
    return (point)
    {
        a.x *x, a.y *x
    };
}
point operator /(point a, db x)
{
    return (point)
    {
        a.x / x, a.y / x
    };
}
bool a_onleft(point a, point b)
{
    return a * b < -eps;
}
db area(point a, point b, point c)
{
    return abs((a - c) * (b - c) / 2.0);
}
point inter(point a1, point a2, point b1, point b2)
{
    double s1 = area(b1, b2, a1), s2 = area(b1, b2, a2);
    return (a1 - a2) / (s1 + s2) * s2 + a2;
}
double dis(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
#undef db
#undef eps
// -------defimal---------
#include <string>
class Decimal
{
public:
    Decimal();
    Decimal(const std::string &s);
    Decimal(const char *s);
    Decimal(int x);
    Decimal(long long x);
    Decimal(double x);

    bool is_zero() const;

    // p (p > 0) is the number of digits after the decimal point
    std::string to_string(int p) const;
    double to_double() const;

    friend Decimal operator+(const Decimal &a, const Decimal &b);
    friend Decimal operator+(const Decimal &a, int x);
    friend Decimal operator+(int x, const Decimal &a);
    friend Decimal operator+(const Decimal &a, long long x);
    friend Decimal operator+(long long x, const Decimal &a);
    friend Decimal operator+(const Decimal &a, double x);
    friend Decimal operator+(double x, const Decimal &a);

    friend Decimal operator-(const Decimal &a, const Decimal &b);
    friend Decimal operator-(const Decimal &a, int x);
    friend Decimal operator-(int x, const Decimal &a);
    friend Decimal operator-(const Decimal &a, long long x);
    friend Decimal operator-(long long x, const Decimal &a);
    friend Decimal operator-(const Decimal &a, double x);
    friend Decimal operator-(double x, const Decimal &a);

    friend Decimal operator*(const Decimal &a, int x);
    friend Decimal operator*(int x, const Decimal &a);

    friend Decimal operator/(const Decimal &a, int x);

    friend bool operator<(const Decimal &a, const Decimal &b);
    friend bool operator>(const Decimal &a, const Decimal &b);
    friend bool operator<=(const Decimal &a, const Decimal &b);
    friend bool operator>=(const Decimal &a, const Decimal &b);
    friend bool operator==(const Decimal &a, const Decimal &b);
    friend bool operator!=(const Decimal &a, const Decimal &b);

    Decimal &operator+=(int x);
    Decimal &operator+=(long long x);
    Decimal &operator+=(double x);
    Decimal &operator+=(const Decimal &b);

    Decimal &operator-=(int x);
    Decimal &operator-=(long long x);
    Decimal &operator-=(double x);
    Decimal &operator-=(const Decimal &b);

    Decimal &operator*=(int x);

    Decimal &operator/=(int x);

    friend Decimal operator-(const Decimal &a);

    // These can't be called
    friend Decimal operator*(const Decimal &a, double x);
    friend Decimal operator*(double x, const Decimal &a);
    friend Decimal operator/(const Decimal &a, double x);
    Decimal &operator*=(double x);
    Decimal &operator/=(double x);

private:
    static const int len = PREC / 9 + 1;
    static const int mo = 1000000000;

    static void append_to_string(std::string &s, long long x);

    bool is_neg;
    long long integer;
    int data[len];

    void init_zero();
    void init(const char *s);
};

Decimal::Decimal()
{
    this->init_zero();
}

Decimal::Decimal(const char *s)
{
    this->init(s);
}

Decimal::Decimal(const std::string &s)
{
    this->init(s.c_str());
}

Decimal::Decimal(int x)
{
    this->init_zero();

    if (x < 0)
    {
        is_neg = true;
        x = -x;
    }

    integer = x;
}

Decimal::Decimal(long long x)
{
    this->init_zero();

    if (x < 0)
    {
        is_neg = true;
        x = -x;
    }

    integer = x;
}

Decimal::Decimal(double x)
{
    this->init_zero();

    if (x < 0)
    {
        is_neg = true;
        x = -x;
    }

    integer = (long long)x;
    x -= integer;

    for (int i = 0; i < len; i++)
    {
        x *= mo;
        if (x < 0)
            x = 0;
        data[i] = (int)x;
        x -= data[i];
    }
}

void Decimal::init_zero()
{
    is_neg = false;
    integer = 0;
    memset(data, 0, len * sizeof(int));
}

bool Decimal::is_zero() const
{
    if (integer)
        return false;
    for (int i = 0; i < len; i++)
    {
        if (data[i])
            return false;
    }
    return true;
}

void Decimal::init(const char *s)
{
    this->init_zero();

    is_neg = false;
    integer = 0;

    // find the first digit or the negative sign
    while (*s != 0)
    {
        if (*s == '-')
        {
            is_neg = true;
            ++s;
            break;
        }
        else if (*s >= 48 && *s <= 57)
        {
            break;
        }
        ++s;
    }

    // read the integer part
    while (*s >= 48 && *s <= 57)
    {
        integer = integer * 10 + *s - 48;
        ++s;
    }

    // read the decimal part
    if (*s == '.')
    {
        int pos = 0;
        int x = mo / 10;

        ++s;
        while (pos < len && *s >= 48 && *s <= 57)
        {
            data[pos] += (*s - 48) * x;
            ++s;
            x /= 10;
            if (x == 0)
            {
                ++pos;
                x = mo / 10;
            }
        }
    }
}

void Decimal::append_to_string(std::string &s, long long x)
{
    if (x == 0)
    {
        s.append(1, 48);
        return;
    }

    char _[30];
    int cnt = 0;
    while (x)
    {
        _[cnt++] = x % 10;
        x /= 10;
    }
    while (cnt--)
    {
        s.append(1, _[cnt] + 48);
    }
}

std::string Decimal::to_string(int p) const
{
    std::string ret;

    if (is_neg && !this->is_zero())
    {
        ret = "-";
    }

    append_to_string(ret, this->integer);

    ret.append(1, '.');

    for (int i = 0; i < len; i++)
    {
        // append data[i] as "%09d"
        int x = mo / 10;
        int tmp = data[i];
        while (x)
        {
            ret.append(1, 48 + tmp / x);
            tmp %= x;
            x /= 10;
            if (--p == 0)
            {
                break;
            }
        }
        if (p == 0)
            break;
    }

    if (p > 0)
    {
        ret.append(p, '0');
    }

    return ret;
}

double Decimal::to_double() const
{
    double ret = integer;

    double k = 1.0;
    for (int i = 0; i < len; i++)
    {
        k /= mo;
        ret += k * data[i];
    }

    if (is_neg)
    {
        ret = -ret;
    }

    return ret;
}

bool operator<(const Decimal &a, const Decimal &b)
{
    if (a.is_neg != b.is_neg)
    {
        return a.is_neg && (!a.is_zero() || !b.is_zero());
    }
    else if (!a.is_neg)
    {
        // a, b >= 0
        if (a.integer != b.integer)
        {
            return a.integer < b.integer;
        }
        for (int i = 0; i < Decimal::len; i++)
        {
            if (a.data[i] != b.data[i])
            {
                return a.data[i] < b.data[i];
            }
        }
        return false;
    }
    else
    {
        // a, b <= 0
        if (a.integer != b.integer)
        {
            return a.integer > b.integer;
        }
        for (int i = 0; i < Decimal::len; i++)
        {
            if (a.data[i] != b.data[i])
            {
                return a.data[i] > b.data[i];
            }
        }
        return false;
    }
}

bool operator>(const Decimal &a, const Decimal &b)
{
    if (a.is_neg != b.is_neg)
    {
        return !a.is_neg && (!a.is_zero() || !b.is_zero());
    }
    else if (!a.is_neg)
    {
        // a, b >= 0
        if (a.integer != b.integer)
        {
            return a.integer > b.integer;
        }
        for (int i = 0; i < Decimal::len; i++)
        {
            if (a.data[i] != b.data[i])
            {
                return a.data[i] > b.data[i];
            }
        }
        return false;
    }
    else
    {
        // a, b <= 0
        if (a.integer != b.integer)
        {
            return a.integer < b.integer;
        }
        for (int i = 0; i < Decimal::len; i++)
        {
            if (a.data[i] != b.data[i])
            {
                return a.data[i] < b.data[i];
            }
        }
        return false;
    }
}

bool operator<=(const Decimal &a, const Decimal &b)
{
    if (a.is_neg != b.is_neg)
    {
        return a.is_neg || (a.is_zero() && b.is_zero());
    }
    else if (!a.is_neg)
    {
        // a, b >= 0
        if (a.integer != b.integer)
        {
            return a.integer < b.integer;
        }
        for (int i = 0; i < Decimal::len; i++)
        {
            if (a.data[i] != b.data[i])
            {
                return a.data[i] < b.data[i];
            }
        }
        return true;
    }
    else
    {
        // a, b <= 0
        if (a.integer != b.integer)
        {
            return a.integer > b.integer;
        }
        for (int i = 0; i < Decimal::len; i++)
        {
            if (a.data[i] != b.data[i])
            {
                return a.data[i] > b.data[i];
            }
        }
        return true;
    }
}

bool operator>=(const Decimal &a, const Decimal &b)
{
    if (a.is_neg != b.is_neg)
    {
        return !a.is_neg || (a.is_zero() && b.is_zero());
    }
    else if (!a.is_neg)
    {
        // a, b >= 0
        if (a.integer != b.integer)
        {
            return a.integer > b.integer;
        }
        for (int i = 0; i < Decimal::len; i++)
        {
            if (a.data[i] != b.data[i])
            {
                return a.data[i] > b.data[i];
            }
        }
        return true;
    }
    else
    {
        // a, b <= 0
        if (a.integer != b.integer)
        {
            return a.integer < b.integer;
        }
        for (int i = 0; i < Decimal::len; i++)
        {
            if (a.data[i] != b.data[i])
            {
                return a.data[i] < b.data[i];
            }
        }
        return true;
    }
}

bool operator==(const Decimal &a, const Decimal &b)
{
    if (a.is_zero() && b.is_zero())
        return true;
    if (a.is_neg != b.is_neg)
        return false;
    if (a.integer != b.integer)
        return false;
    for (int i = 0; i < Decimal::len; i++)
    {
        if (a.data[i] != b.data[i])
            return false;
    }
    return true;
}

bool operator!=(const Decimal &a, const Decimal &b)
{
    return !(a == b);
}

Decimal &Decimal::operator+=(long long x)
{
    if (!is_neg)
    {
        if (integer + x >= 0)
        {
            integer += x;
        }
        else
        {
            bool last = false;
            for (int i = len - 1; i >= 0; i--)
            {
                if (last || data[i])
                {
                    data[i] = mo - data[i] - last;
                    last = true;
                }
                else
                {
                    last = false;
                }
            }
            integer = -x - integer - last;
            is_neg = true;
        }
    }
    else
    {
        if (integer - x >= 0)
        {
            integer -= x;
        }
        else
        {
            bool last = false;
            for (int i = len - 1; i >= 0; i--)
            {
                if (last || data[i])
                {
                    data[i] = mo - data[i] - last;
                    last = true;
                }
                else
                {
                    last = false;
                }
            }
            integer = x - integer - last;
            is_neg = false;
        }
    }
    return *this;
}

Decimal &Decimal::operator+=(int x)
{
    return *this += (long long)x;
}

Decimal &Decimal::operator-=(int x)
{
    return *this += (long long) - x;
}

Decimal &Decimal::operator-=(long long x)
{
    return *this += -x;
}

Decimal &Decimal::operator/=(int x)
{
    if (x < 0)
    {
        is_neg ^= 1;
        x = -x;
    }

    int last = integer % x;
    integer /= x;

    for (int i = 0; i < len; i++)
    {
        long long tmp = 1LL * last * mo + data[i];
        data[i] = tmp / x;
        last = tmp - 1LL * data[i] * x;
    }

    if (is_neg && integer == 0)
    {
        int i;
        for (i = 0; i < len; i++)
        {
            if (data[i] != 0)
            {
                break;
            }
        }
        if (i == len)
        {
            is_neg = false;
        }
    }

    return *this;
}

Decimal &Decimal::operator*=(int x)
{
    if (x < 0)
    {
        is_neg ^= 1;
        x = -x;
    }
    else if (x == 0)
    {
        init_zero();
        return *this;
    }

    int last = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        long long tmp = 1LL * data[i] * x + last;
        last = tmp / mo;
        data[i] = tmp - 1LL * last * mo;
    }
    integer = integer * x + last;

    return *this;
}

Decimal operator-(const Decimal &a)
{
    Decimal ret = a;
    // -0 = 0
    if (!ret.is_neg && ret.integer == 0)
    {
        int i;
        for (i = 0; i < Decimal::len; i++)
        {
            if (ret.data[i] != 0)
                break;
        }
        if (i < Decimal::len)
        {
            ret.is_neg = true;
        }
    }
    else
    {
        ret.is_neg ^= 1;
    }
    return ret;
}

Decimal operator+(const Decimal &a, int x)
{
    Decimal ret = a;
    return ret += x;
}

Decimal operator+(int x, const Decimal &a)
{
    Decimal ret = a;
    return ret += x;
}

Decimal operator+(const Decimal &a, long long x)
{
    Decimal ret = a;
    return ret += x;
}

Decimal operator+(long long x, const Decimal &a)
{
    Decimal ret = a;
    return ret += x;
}

Decimal operator-(const Decimal &a, int x)
{
    Decimal ret = a;
    return ret -= x;
}

Decimal operator-(int x, const Decimal &a)
{
    return -(a - x);
}

Decimal operator-(const Decimal &a, long long x)
{
    Decimal ret = a;
    return ret -= x;
}

Decimal operator-(long long x, const Decimal &a)
{
    return -(a - x);
}

Decimal operator*(const Decimal &a, int x)
{
    Decimal ret = a;
    return ret *= x;
}

Decimal operator*(int x, const Decimal &a)
{
    Decimal ret = a;
    return ret *= x;
}

Decimal operator/(const Decimal &a, int x)
{
    Decimal ret = a;
    return ret /= x;
}

Decimal operator+(const Decimal &a, const Decimal &b)
{
    if (a.is_neg == b.is_neg)
    {
        Decimal ret = a;
        bool last = false;
        for (int i = Decimal::len - 1; i >= 0; i--)
        {
            ret.data[i] += b.data[i] + last;
            if (ret.data[i] >= Decimal::mo)
            {
                ret.data[i] -= Decimal::mo;
                last = true;
            }
            else
            {
                last = false;
            }
        }
        ret.integer += b.integer + last;
        return ret;
    }
    else if (!a.is_neg)
    {
        // a - |b|
        return a - -b;
    }
    else
    {
        // b - |a|
        return b - -a;
    }
}

Decimal operator-(const Decimal &a, const Decimal &b)
{
    if (!a.is_neg && !b.is_neg)
    {
        if (a >= b)
        {
            Decimal ret = a;
            bool last = false;
            for (int i = Decimal::len - 1; i >= 0; i--)
            {
                ret.data[i] -= b.data[i] + last;
                if (ret.data[i] < 0)
                {
                    ret.data[i] += Decimal::mo;
                    last = true;
                }
                else
                {
                    last = false;
                }
            }
            ret.integer -= b.integer + last;
            return ret;
        }
        else
        {
            Decimal ret = b;
            bool last = false;
            for (int i = Decimal::len - 1; i >= 0; i--)
            {
                ret.data[i] -= a.data[i] + last;
                if (ret.data[i] < 0)
                {
                    ret.data[i] += Decimal::mo;
                    last = true;
                }
                else
                {
                    last = false;
                }
            }
            ret.integer -= a.integer + last;
            ret.is_neg = true;
            return ret;
        }
    }
    else if (a.is_neg && b.is_neg)
    {
        // a - b = (-b) - (-a)
        return -b - -a;
    }
    else if (a.is_neg)
    {
        // -|a| - b
        return -(-a + b);
    }
    else
    {
        // a - -|b|
        return a + -b;
    }
}

Decimal operator+(const Decimal &a, double x)
{
    return a + Decimal(x);
}

Decimal operator+(double x, const Decimal &a)
{
    return Decimal(x) + a;
}

Decimal operator-(const Decimal &a, double x)
{
    return a - Decimal(x);
}

Decimal operator-(double x, const Decimal &a)
{
    return Decimal(x) - a;
}

Decimal &Decimal::operator+=(double x)
{
    *this = *this + Decimal(x);
    return *this;
}

Decimal &Decimal::operator-=(double x)
{
    *this = *this - Decimal(x);
    return *this;
}

Decimal &Decimal::operator+=(const Decimal &b)
{
    *this = *this + b;
    return *this;
}

Decimal &Decimal::operator-=(const Decimal &b)
{
    *this = *this - b;
    return *this;
}
// ---end---decimal---
//----------------------------
int main()
{

    return 0;
}