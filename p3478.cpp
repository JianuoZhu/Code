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
struct edge{
    int v, nxt;
}e[maxm];
using namespace std;
int n, h[maxn], cnt, siz[maxn], dep[maxn], f[maxn];
void add(int u, int v){
    e[++cnt].v = v; e[cnt].nxt = h[u]; h[u] = cnt;
}
void dfs1(int x, int fa){
    dep[x] = dep[fa]+1; siz[x] = 1;
    for(int i=h[x]; i; i=e[i].nxt){
        
    }
}
signed main(){
    read(n);
    int u, v;
    for(int i=1; i<=n; i++){
        read(u); read(v); add(u, v);
    }
    dep[0] = -1;
    dfs1(1, 0);
    return 0;
}
