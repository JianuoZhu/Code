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
const int maxn = 1e5+10, maxm = 1e6+10;
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
struct node{
    int dis, pos;
    friend bool operator <(node x, node y){
        return x.dis > y.dis;
    }
};
using namespace std;
int n, m, s, h[maxn], cnt, dis[maxn];
bool vis[maxn];
priority_queue<node> q;
void add(int u, int v, int w){
    e[++cnt].v = v; e[cnt].w = w; e[cnt].nxt = h[u]; h[u] = cnt;
}
void dijkstra(){
    dis[s] = 0;
    q.push((node){0, s});
    while(!q.empty()){
        node t = q.top(); q.pop();
        int x = t.pos; if(vis[x]) continue;
        vis[x] = 1;
        for(int i=h[x]; i; i=e[i].nxt){
            int v = e[i].v, w = e[i].w;
            dis[v] = mmin(dis[v], dis[x] + w);
            if(!vis[v]) q.push((node){dis[v], v});
        }
    }
}
signed main(){
    read(n); read(m); read(s);
    for(int i=1; i<=n; i++) dis[i] = inf;
    int u, v, w;
    for(int i=1; i<=m; i++){
        read(u); read(v); read(w);
        add(u, v, w);
    }
    dijkstra();
    for(int i=1; i<=n; i++) printf("%lld ", dis[i]);
    return 0;
}
