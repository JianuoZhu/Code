#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
#define int long long
#define Pair pair<int, int>
const int maxn = 1e5+10, maxm = 2e5+10;
inline int mmax(int a, int b){return a>b?a:b;}
inline int mmin(int a, int b){return a<b?a:b;}
inline int aabs(int a){return a>0?a:-a;}
inline void read(int &x){
     x = 0; char c = getchar(); int w = 1;
     while(c < '0' || c > '9'){if(c == '-') w = -1; c = getchar();}
     while(c >= '0' && c <= '9') x = x*10+c-'0', c = getchar();
     x *= w;
}
struct edge{
    int v, w, nxt;
}e[maxm];
using namespace std;
priority_queue<Pair, vector<Pair>, greater<Pair > > q;
int n, m, k, h[maxn], cnt, dis[maxn];
void add(int u, int v, int w){
    e[++cnt].v = v; e[cnt].w = w;
    e[cnt].nxt = h[u]; h[u] = cnt;
}
void dij(){
    dis[1] = 0;
    q.push(Pair{0, 1});
    while(!q.empty()){
        Pair p = q.top(); q.pop();
        int d = p.first, u = p.second;
        if(d > dis[u]) continue;
        for(int i=h[u]; i; i=e[i].nxt){
            int v = e[i].v;
            if(dis[v] > dis[u] + e[i].w){
                dis[v] = dis[u] + e[i].w;
                q.push(Pair{dis[v], v});
            }
        }
    }
}
signed main(){
    read(n); read(m); read(k);
    int u, v, w;
    for(int i=1; i<=m; i++){
        read(u); read(v); read(w);
        add(u, v, w); add(v, u, w);
    }
    for(int u=1; u<=n; u++){
        for(int i=h[u]; i; i=e[i].nxt){
            int v = e[i].v; w = e[i].w;
            for(int s=0; s<=k; s++){
                if(s>0)add(n*s+u, n*s+v, w);
                if(s < k)add(n*s+u, n*(s+1)+v, w/2);
            }
        }
    }
    for(int i=1; i<=n*(k+1); i++) dis[i] = inf;
    dij();
    int ans = inf;
    for(int i=0; i<=k; i++){
        ans = mmin(dis[n*i+n], ans);
    }
    printf("%d", ans);
    return 0;
}
