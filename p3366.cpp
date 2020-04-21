#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
#define int long long
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

using namespace std;
struct edge{
    int u, v, w;
}e[maxm];
int n, m, cnt, fa[maxn];
void add(int u, int v, int w){
    e[++cnt].u = u; e[cnt].v = v; e[cnt].w = w;
}
bool cmp(edge a, edge b){return a.w<b.w;}
int getf(int x){return fa[x]==x?x:fa[x]=getf(fa[x]);}
void merge(int x, int y){fa[x] = y;}
signed main(){
    read(n); read(m);
    for(int i=1; i<=n; i++) fa[i] = i;
    int u, v, w;
    for(int i=1; i<=m; i++){
        read(u); read(v); read(w); add(u, v, w);
    }
    sort(e+1, e+1+cnt, cmp);
    int ans = 0, tot = 1;
    for(int i=1; i<=cnt; i++){
        int u = e[i].u, v = e[i].v;
        if(getf(u) == getf(v)) continue;
        merge(getf(u), getf(v)); ans += e[i].w;
        tot++; if(tot == n) break;
    }
    if(tot != n) {printf("orz"); return 0;}
    printf("%lld", ans);
    return 0;
}
