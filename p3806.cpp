#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
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

using namespace std;
struct edge{
    int v, w, nxt;
}e[maxn];
int n, m, cnt, q[maxn], rt, tot, Minf, siz[maxn];
void add(int u, int v, int w){
    e[++cnt].v = v; e[cnt].w = w; 
    e[cnt].nxt = h[u]; h[u] = cnt;
}
void getrt(int x, int fa){
    int f = 0, siz[x] = 0;
    
}
signed main(){
    read(n); read(m);
    int u, v, w;
    for(int i=1; i<=n-1; i++){
        scanf("%d%d%d", u, v, w);
        add(u, v, w); add(v, u, w);
    }
    for(int i=1; i<=m; i++) read(q[i]);
    rt = 0; tot = n;
    Minf = n+1;
    getrt(1, 0);
    return 0;
}
