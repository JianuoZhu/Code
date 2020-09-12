#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
#define int long long
const int maxn = 3e3+10, maxm = 1e6+10;;
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
using namespace std;
int n, m, cnt, h[maxn], f[maxn][maxn], sum[maxn], ans, v[maxn];
void add(int u, int v, int w){
    e[++cnt].v = v; e[cnt].w = w; e[cnt].nxt = h[u]; h[u] = cnt;
}
void dfs(int x){
    if(x>n-m) f[x][1] = v[x-(n-m)], sum[x]=1;
    for(int i=h[x]; i; i=e[i].nxt){
        int v = e[i].v; dfs(v); sum[x] += sum[v];
        for(int siz=sum[x]; siz>=1; siz--){
            for(int k=1; k<=mmin(siz, sum[v]); k++){
                f[x][siz] = mmax(f[x][siz], f[x][siz-k]+f[v][k]-e[i].w);
            }
        }
    }
}
signed main(){
    read(n); read(m);
    int k, t, cost;
    for(int i=1; i<=n-m; i++){
        read(k);
        while(k--){
            read(t); read(cost); add(i, t, cost);
        }
    }
    for(int i=1; i<=m; i++){
        read(v[i]);
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) f[i][j] = -inf;
    dfs(1);
    for(int i=1; i<=sum[1]; i++) if(f[1][i]>=0) ans = i;
    printf("%lld", ans);
    return 0;
}
