#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
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
    int v, nxt;
}e[maxm];
using namespace std;
int n, h[maxn], cnt, f[maxn][2];
void add(int u, int v){
    e[++cnt].v = v; e[cnt].nxt = h[u]; h[u] = cnt;
}
void dfs(int x, int fa){
    f[x][0] = 0; f[x][1] = 1;
    for(int i=h[x]; i; i=e[i].nxt){
        int v = e[i].v; if(v == fa) continue;
        dfs(v, x);
        f[x][0] += f[v][1];
        f[x][1] += mmin(f[v][0], f[v][1]);
    }
}
signed main(){
    read(n);
    int k, m, t;
    for(int i=1; i<=n; i++){
        read(k); k++; read(m);
        for(int i=1; i<=m; i++){
            read(t);  t++; add(k, t); add(t, k);
        }
    }
    //for(int i=1; i<=n; i++) f[i][0] = f[i][1] = inf;
    dfs(1, 0);
    printf("%lld", mmin(f[1][0], f[1][1]));
    return 0;
}
