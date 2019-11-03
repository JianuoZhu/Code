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
    int v, w, nxt;
}e[maxm];
using namespace std;
int n, m, k, h[maxn], cnt;
void add(int u, int v, int w){
    e[++cnt].v = v; e[cnt].w = w;
    e[cnt].nxt = h[u]; h[u] = cnt;
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
            
        }
    }
    return 0;
}
