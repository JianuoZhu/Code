#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
#define int long long
const int maxn = 1e4+10, maxm = 2e3+10;
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
int f[maxn][maxm], top[maxn], bot[maxn], n, m, k, up[maxn], down[maxn];
bool is_t[maxn];
signed main(){
    read(n); read(m); read(k);
    for(int i=0; i<n; i++){
        read(up[i]); read(down[i]);
        top[i] = m+1; bot[i] = 0;
    }
    top[n]=m+1; bot[n]=0;
    int pos, t, b;
    for(int i=1; i<=k; i++){
        read(pos); read(b); read(t);
        is_t[pos]=1;
        top[pos] = t; bot[pos] = b;
    }
    for(int i=1; i<=n; i++) for(int j=0; j<=m; j++) f[i][j] = inf;
    for(int i=1; i<=m; i++) f[0][i] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            //if(j >= top[i] || j <= bot[i]) continue;
            if(j > up[i-1]){
                if(j-up[i-1] > bot[i-1] && j-up[i-1] < top[i-1])f[i][j] = mmin(f[i][j], f[i-1][j-up[i-1]]+1);
                f[i][j] = mmin(f[i][j], f[i][j-up[i-1]]+1);    
            }
            if(j == m){
                for(int k=m-up[i-1]; k<=m; k++){
                     if(bot[i-1]<k || top[i-1]>k) f[i][j] = mmin(f[i][j], f[i-1][k]+1);
                    f[i][j] = mmin(f[i][j], f[i][k]+1);
                }
            }
        }
        for(int j=top[i]-1; j>bot[i]; j--){
            if(j+down[i-1] < top[i-1] && j+down[i-1] > bot[i-1]) f[i][j] = mmin(f[i][j], f[i-1][j+down[i-1]]);
        }
    }
    /*for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            printf("%lld ", f[i][j]);
        }
        printf("\n");
    }*/
    bool flag, ff=0;
    int tt = 0;
    for(int i=1; i<=n; i++){
        flag = 0;
        for(int j=1; j<=m; j++){
            if(f[i][j] < inf && j>bot[i] && j<top[i]) flag=1;
        }
        if(!flag) {ff = 1; tt=i; break;}
    }
    int ans = inf, tans = 0;
    if(!ff){
        for(int i=0; i<=m; i++) ans = mmin(ans, f[n][i]);
        printf("1\n%lld", ans);
    }
    else{
        for(int i=1; i<tt; i++) tans += is_t[i];
        printf("0\n%lld", tans);
    }
    return 0;
}
