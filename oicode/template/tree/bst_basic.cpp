#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
namespace BST {
    const int maxn = 1e5 + 5;
    struct node {
        int val, lson, rson, father, size, rtag, son[2]; // remove tag
        node() : val(0), father(0), size(0) {}
    };
    node t[maxn];
    vector<int> templ;
    int cnt = 1, root = 1;
    inline void print(int k, bool typ) {
        if (t[k].son[0]) print(t[k].son[0], typ);
        // if (!typ) cout << t[k].val << " ";
        if(!typ) cout << t[t[k].father].val << " " <<t[k].size << " " << t[k].val << endl;
        else templ.push_back(t[k].val);
        if (t[k].son[1]) print(t[k].son[1], typ);
    }
    inline void pushup(int k) {
        t[k].size = t[t[k].son[0]].size + t[t[k].son[1]].size + 1;
    }
    inline void insert(int k, int val) {
        // root -> k = 0
        if (cnt == 1) {
            t[cnt++].val = val; t[cnt].size = 1; t[cnt].father = 0;
            pushup(k); return;
        }
        node &curr = t[k];
        int proc = val > curr.val;
        if(curr.son[proc] == 0) {
            t[cnt].val = val, curr.son[proc] = cnt, t[cnt].father = k, t[cnt].size = 1;
            ++cnt;
        } else insert(curr.son[proc], val);
        pushup(k);
    }
    inline void subreb(int &k, int l, int r) {
        if (l > r) return;
        int mid = (l + r) >> 1;
        k = ++cnt;
        t[k].val = templ[mid];
        subreb(t[k].son[0], l, mid - 1);
        subreb(t[k].son[1], mid + 1, r);
        t[t[k].son[0]].father = t[t[k].son[1]].father = k; // 自己儿子的父亲是自己(重置)
        pushup(k);
    }
    inline void rebuild(int k) {
        templ.clear();
        print(k, true); // init the lst k
        subreb(k, 0, templ.size() - 1);
    }
    inline int find(int k, int val) {
        if(t[k].val == val) return k;
        if(val <= t[k].val && t[k].son[0]) return find(t[k].son[0], val);
        else if(t[k].son[1]) return find(t[k].son[1], val);
    }
    inline int getkth(int k, int val) {
        // by LittleRewriter
        if(val > cnt) return 0; 
        if(t[t[k].son[0]].size + 1 == val) return t[k].val;
        else if(t[k].son[0] && val <= t[t[k].son[0]].size) 
            return getkth(t[k].son[0], val);
        else if(t[k].son[1] && val >= t[t[k].son[0]].size + 2) 
            return getkth(t[k].son[1], val - t[t[k].son[0]].size - 1);
    }
    inline int subgetrank(int k, int val, int cnt) {
        // by LittleRewriter
        if(t[k].val == val) return cnt + t[t[k].son[0]].size + 1;
        else if(t[k].son[0] && t[k].val > val) return subgetrank(t[k].son[0], val, cnt);
        else if(t[k].son[1] && t[k].val < val) return subgetrank(t[k].son[1], val, cnt + t[t[k].son[0]].size + 1);
    }
    // 因为特判的原因 不能直接调用 所以加了一个子函数
    inline int getrank(int k, int val) {
        if(!find(k, val)) return 0;
        return subgetrank(k, val, 0);
    }
}
int main() {
    using namespace BST;
    int n;
    cin >> n;
    for (int k, i = 0; i < n; ++i) {
        cin >> k;
        insert(root, k);
    }
    /*
    for (int i = 1; i < cnt; ++i) {
        cout << t[t[i].father].val << " " <<t[i].size << " " << t[i].val << endl;
    }*/
    //print(root, false);
    cout << endl;
    cout << getkth(root, 3) << endl;
    cout << getrank(root, 9);
    cout << endl;
    int curr = cnt;
    rebuild(root);
    // print(curr + 1, false);
    cout << endl;
    cout << getkth(root, 3) << endl;
    cout << getrank(root, 9);
    cout << endl;
}
/*
6
2 8 9 6 4 1
*/
