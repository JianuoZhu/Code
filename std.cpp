#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
const int maxn = 2e5+10;
inline int mmax(int a, int b){return a>b?a:b;}
inline int mmin(int a, int b){return a<b?a:b;}
inline int aabs(int a){return a>0?a:-a;}
inline void read(int &x){
     x = 0; char c = getchar(); int w = 1;
     while(c < '0' || c > '9'){if(c == '-') w = -1; c = getchar();}
     while(c >= '0' && c <= '9') x = x*10+c-'0', c = getchar();
     x *= w;
}
struct node{
    int l, r, sum, ls, rs;
}tr[maxn];
using namespace std;
vector<int> e[maxn], ee[maxn];
int n, m, _q, stack[maxn], top, ins[maxn], dfn[maxn], low[maxn];
int cnt, tot, belong[maxn], a[maxn], rt[maxn], in[maxn];
queue<int> q;
void tarjan(int x){
    stack[++top] = x; ins[x] = true;
    dfn[x] = low[x] = ++cnt;
    for(int i=0; i<e[x].size(); i++){
        int v = e[x][i];
        if(!dfn[v]) tarjan(v), low[x] = min(low[x], low[v]);
        else if(ins[v]) low[x] = min(low[x], dfn[v]);
    }
    if(dfn[x] == low[x]){
        tot++;
        while(stack[top+1] != x){
            belong[stack[top]] = tot;
            ins[stack[top]] = false; top--;
        }
    }
}
int build(int l, int r){
    int x = ++cnt;
    tr[x].l = l; tr[x].r = r;
    if(l == r) return x;
    int mid = (l+r)/2;
    tr[x].ls = build(l, mid); tr[x].rs = build(mid+1, r);
    return x;
}
void add(int x, int v){
    if(tr[x].l == tr[x].r) {tr[x].sum++; return;}
    int mid = (tr[x].l+tr[x].r)/2;
    if(v <= mid) add(tr[x].ls, v);
    else add(tr[x].rs, v);
    tr[x].sum = tr[tr[x].ls].sum + tr[tr[x].rs].sum;
}
int merge(int x, int y){
    if(!x || !y) return x+y;
    if(tr[x].l == tr[x].r){
        tr[x].sum = max(tr[x].sum, tr[y].sum); return x;
    }
    tr[x].ls = merge(tr[x].ls, tr[y].ls);
    tr[x].rs = merge(tr[x].rs, tr[y].rs);
    tr[x].sum = tr[tr[x].ls].sum + tr[tr[x].rs].sum;
    return x;
}
int query(int x, int l, int r){
    if(tr[x].l >= l && tr[x].r <= r){
        return tr[x].sum;
    }
    int mid = (tr[x].l + tr[x].r) / 2, ans = 0;
    if(l <= mid) ans += query(tr[x].ls, l, r);
    if(r >  mid) ans += query(tr[x].rs, l, r);
    return ans;
}
signed main(){
    read(n); read(m); read(_q);
    for(int i=1; i<=n; i++) read(a[i]);
    int u, v;
    for(int i=1; i<=m; i++){
        read(u); read(v); e[u].push_back(v);
    }
    tarjan(1);
    for(int i=1; i<=n; i++){
        for(int j=0; j<e[i].size(); j++){
            ee[belong[e[i][j]]].push_back(belong[i]); in[belong[i]]++;
        }
    }
    cnt = 0;
    for(int i=1; i<=tot; i++){
        rt[i] = build(1, n);
    }
    for(int i=1; i<=n; i++) add(rt[belong[i]], a[i]);
    for(int i=1; i<=tot; i++) if(!in[i]) q.push(i);
    //for(int i=1; i<=n; i++) printf("belong[%d] = %d\n", i, belong[i]);
    //for(int i=0; i<=tot; i++) printf("in[%d]=%d\n", i, in[i]);
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i=0; i<ee[x].size(); i++){
            int v = ee[x][i];
            merge(rt[v], rt[x]); in[v]--;
            if(!in[v]) q.push(v);
        }
    }
    int x, l, r;
    for(int i=1; i<=_q; i++){
        read(x); read(l); read(r);
        printf("%d\n", query(rt[belong[x]], l, r));
    }
    return 0;
}
