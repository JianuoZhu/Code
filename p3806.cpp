#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
const int maxn = 1e5+10;
inline int mmax(int a, int b){return a>b?a:b;}
inline int mmin(int a, int b){return a<b?a:b;}
inline int aabs(int a){return a>0?a:-a;}
inline void read(int &x){
     x = 0; char c = getchar(); int w = 1;
     while(c < '0' || c > '9'){if(c == '-') w = -1; c = getchar();}
     while(c >= '0' && c <= '9') x = x*10+c-'0', c = getchar();
     x *= w;
}

using namespace std;
struct edge{
    int v, w, nxt;
}e[maxn];
set<int> st;
int n, m, cnt, q[maxn], rt, tot, Minf, siz[maxn], h[maxn], dis[maxn];
int vis[maxn], nd[maxn], ans[maxn];
void add(int u, int v, int w){
    e[++cnt].v = v; e[cnt].w = w; 
    e[cnt].nxt = h[u]; h[u] = cnt;
}
void getrt(int x, int fa){
    int f = 0;
    siz[x] = 1;
    for(int i=h[x]; i; i=e[i].nxt){
        int v = e[i].v; if(v == fa || vis[v]) continue;
        getrt(v, x); siz[x] += siz[v];
        f = mmax(f, siz[v]);
    }
    f = mmax(tot-siz[x], f);
    if(f < Minf) Minf = f, rt = x;
}
void dfs(int x, int fa){
    nd[++cnt] = x;
    for(int i=h[x]; i; i=e[i].nxt){
        int v = e[i].v; if(v == fa || vis[v]) continue;
        dis[v] = dis[x] + e[i].w; dfs(v, x);
    }
}
void query(int x){
    for(int i=1; i<=m; i++){
        if(!ans[i]) ans[i] = (*st.lower_bound(q[i]-dis[x])==q[i]-dis[x]);
    }
}
void solve(int x){
    vis[x] = 1; st.clear(); st.insert(0);
    for(int i=h[x]; i; i=e[i].nxt){
        int v = e[i].v; if(vis[v]) continue;
        cnt = 0; dis[v] = e[i].w; dfs(v, x);
        for(int i=1; i<=cnt; i++) query(nd[i]);
        for(int i=1; i<=cnt; i++) st.insert(dis[nd[i]]);
    }
    for(int i=h[x]; i; i=e[i].nxt){
        int v = e[i].v; if(vis[v]) continue;
        rt = 0; tot = siz[v]; Minf = n+1;
        getrt(v, 0); solve(rt);
    }
}
signed main(){
    read(n); read(m);
    int u, v, w;
    for(int i=1; i<=n-1; i++){
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w); add(v, u, w);
    }
    for(int i=1; i<=m; i++) read(q[i]);
    rt = 0; tot = n;
    Minf = n+1;
    getrt(1, 0); solve(rt);
    for(int i=1; i<=m; i++){
        if(ans[i]) puts("AYE");
        else puts("NAY");   
    }
    return 0;
}
