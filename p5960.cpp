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
const int maxn = 1e5+10, maxm = 1e5+10;
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
    int v, nxt, w;
}e[maxm];
struct node{
    int dis, pos;
    friend bool operator <(node x, node y){
        return x.dis > y.dis;
    }
};
using namespace std;
int n, m, cnt, h[maxn], ccnt[maxn], dis[maxn];
priority_queue<node> q;
bool vis[maxn], flag;
void add(int u, int v, int w){
    e[++cnt].v = v; e[cnt].w = w; e[cnt].nxt = h[u]; h[u] = cnt;
}
void dij(){
    dis[0] = 0;
    q.push((node){0, 0});
    while(!q.empty()){
        node t = q.top(); q.pop();
        int x = t.pos; if(vis[x]) continue;
        vis[x] = 1; ccnt[x]++;
        if(ccnt[x] > n){
            flag = 1; return;
        }
        for(int i=h[x]; i; i=e[i].nxt){
            int v = e[i].v, w = e[i].w;
            if(dis[v] > dis[x]+w){
                dis[v] = dis[x]+w;
                if(!vis[v]) q.push(node{dis[v], v});
            }
        }
        vis[x] = 0;
    }
}
signed main(){
    read(n); read(m);
    for(int i=1; i<=n; i++) dis[i] = inf;
    for(int i=1; i<=n; i++) add(0, i, 0);
    int u, v, w;
    for(int i=1; i<=m; i++){
        read(u);  read(v); read(w);
        add(v, u, w);
    }
    dij();
    if(flag){printf("NO"); return 0;}
    for(int i=1; i<=n; i++) printf("%lld ", dis[i]);
    return 0;
}
