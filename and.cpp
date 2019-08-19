#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
#define int long long
const int maxn = 1<<22;
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
int n, a[maxn], book[maxn], vis[maxn];
void dfs(int x){
    if(vis[x]) return ;
    vis[x] = 1;
    if(x < (1<<20)){
        for(int i=0; i<20; i++){
            if(x & (1<<i)) dfs(x - (1<<i));
        }
        if(book[x]!=-1) dfs((1<<20)+book[x]);
    }
    else dfs((1<<20)-1-a[x-(1<<20)]);
}
signed main(){
    read(n);
    for(int i=0; i<=1<<20; i++) book[i] = -1;
    for(int i=1; i<=n; i++){
        read(a[i]); book[a[i]] = i;
    }
    int ans = 0;
    for(int i=1; i<=n; i++)
        if(!vis[(1<<20)+i]){
            dfs((1<<20)+i); ans++;
        }
    printf("%d", ans);
    return 0;
}
