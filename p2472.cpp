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
const int maxn = 600, maxm = 3e5+10;
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
    int v, nxt, c, f;
}e[maxm];
using namespace std;
int n, m, d, map[maxn][maxn], _map[maxn][maxn], s, t;
int h[maxn*maxn], cnt=-1, tot, lev[maxn*maxn];
queue<int> q;
inline int id(int x, int y){return (x-1)*m+y;}
void add(int u, int v, int w){
    e[++cnt].v = v; e[cnt].c = w;
    e[cnt].nxt = h[u]; h[u] = cnt;
    e[++cnt].v = u; e[cnt].c = 0;
    e[cnt].nxt = h[v]; h[v] = cnt;
}
int bfs(){
    memset(lev, 0, sizeof(lev));
    lev[s] = 1; q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i=h[u]; ~i; i=e[i].nxt){
            int v = e[i].v;
            //printf("v = %lld\n", v);
            if(!lev[v] && e[i].c > e[i].f) lev[v] = lev[u]+1, q.push(v);
        }
    }
    return lev[t];
}
int dfs(int x, int flow){
    int af = 0;
    if(x == t) return flow;
    for(int i=h[x]; ~i; i=e[i].nxt){
        int v = e[i].v; if(lev[v] != lev[x]+1) continue;
        int maxf = dfs(v, mmin(e[i].c-e[i].f, flow-af));
        e[i].f += maxf; e[i^1].f -= maxf;
        af += maxf; if(flow == af) break;
    }
    return af;
}
int dinic(){
    int maxflow = 0;
    while(bfs()) maxflow += dfs(s, inf);
    return maxflow;
}
signed main(){
    read(n); read(m); read(d);
    t = 2*n*m+1;
    memset(h, -1, sizeof(h));
    char _s[maxn];
    for(int i=1; i<=n; i++){
        scanf("%s", _s+1);
        for(int j=1; j<=m; j++) map[i][j] = _s[j] - '0';
    }
    for(int i=1; i<=n; i++){
        scanf("%s", _s+1);
        for(int j=1; j<=m; j++) _map[i][j] = (_s[j] == 'L');
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            add(id(i,j), id(i,j)+n*m, map[i][j]);
            if(_map[i][j]) add(s, id(i,j), 1), tot++;
            if(i <= d || i >= n - d + 1 || j <= d || j >= m - d + 1)
                add(id(i,j)+n*m, t, inf);
        }
    //DEBUG;
    for(int dx = -d;dx <= d;dx ++)
        for(int dy = -d;dy <= d;dy ++){
            if(dx * dx + dy * dy > d * d) continue;
            for(int i = 1;i <= n;i ++)
                for(int j = 1;j <= m;j ++){
                    int x = i + dx, y = j + dy;
                    if(x >= 1 && x <= n && y >= 1 && y <= m && map[x][y])
                        add(id(i,j)+n*m, id(x,y), inf);
                }
        }
    //DEBUG;
    int ans = dinic();
    //printf("tot = %lld, ans = %lld\n", tot, ans);
    printf("%lld", tot-ans);
    return 0;
}
