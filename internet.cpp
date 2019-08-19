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
struct edge{
    int v, nxt, w;
}e[maxn];
using namespace std;
int n, m, h[maxn], inq[maxn], dis[maxn], cnt;
void add(int u, int v, int w){
    e[++cnt].v = v; e[cnt].w = w;
    e[cnt].nxt = h[u]; h[u] = cnt;
}
int T, w[maxn], mid;
void spfa(){
    queue<int> q;
    for(int i=1; i<=n; i++) dis[i] = inf;
    if(w[1] > mid) return;
    dis[1] = 0; q.push(1); inq[1] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        inq[u] = false;
        for(int i=h[u]; i; i=e[i].nxt){
            int v = e[i].v; if(w[v] > mid) continue;
            if(dis[v] > dis[u] + e[i].w){
                dis[v] = dis[u] + e[i].w;
                if(!inq[v]) q.push(v), inq[v]=true;
            }
        }
    }
}
signed main(){
    int ans = inf;
    read(n); read(m); read(T);
    for(int i=1; i<=n; i++) read(w[i]);
    int u, v, k;
    for(int i=1; i<=m; i++){
        read(u); read(v); read(k);
        add(u, v, k); add(v, u, k);
    }
    int l = 1, r = 1000000000;
    while(l <= r){
        mid = (l+r)/2; spfa();
        if(dis[n] <= T) r = mid-1, ans = mid;
        else l = mid+1;
    }
    printf("%lld", ans);
    return 0;
}