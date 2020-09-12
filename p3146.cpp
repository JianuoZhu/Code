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
int n, v[maxn], f[1000][1000];
signed main(){
    read(n);
    for(int i=1; i<=n; i++) read(v[i]);
    for(int i=1; i<=n; i++) f[i][i] = v[i];
    for(int len=2; len<=n; len++){
        for(int s=1; s+len-1<=n; s++){
            for(int k=s; k<s+len-1; k++){
                if((f[s][k] && f[k+1][s+len-1]) && f[s][k]==f[k+1][s+len-1])
                    f[s][s+len-1] = mmax(f[s][s+len-1], f[s][k]+1);
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++) ans = mmax(ans, f[i][j]);
    }
    printf("%lld", ans);
}
