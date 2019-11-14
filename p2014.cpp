#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
#define int long long
const int maxn = 1e3+10;
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
int n, k, siz[maxn], fa[maxn], v[maxn], f[maxn][maxn];
vector<int> e[maxn];
void dfs(int x){
    siz[x] = 1; f[x][1] = v[x];
    for(int i=0; i<e[x].size(); i++){
        int v = e[x][i];
        dfs(v); siz[x] += siz[v];
        for(int j=siz[x]; j>=2; j--)
            for(int k=1; k<=mmin(j-1, siz[v]); k++)
                f[x][j] = mmax(f[x][j], f[x][j-k] + f[v][k]);
    }
}
signed main(){
    read(n); read(k);
    for(int i=1; i<=n; i++){
        read(fa[i]); read(v[i]);
        e[fa[i]].push_back(i);
    }
    v[0] = 0;
    dfs(0);
    printf("%lld", f[0][k+1]);
    return 0;
}
