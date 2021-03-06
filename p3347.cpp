#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
#define int long long
const int maxn = 5e5+10;
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
int tr[maxn], n, m;
int lowbit(int x){return x&(-x);}
void add(int x, int k){
    for(; x<=n; x+=lowbit(x)) tr[x]+=k;
}
int query(int x){
    int ans = 0;
    for(; x; x-=lowbit(x)) ans += tr[x];
    return ans;
}
signed main(){
    read(n); read(m);
    int opt, x, y;
    for(int i=1; i<=n; i++){
        read(x); add(i, x);  
    }
    for(int i=1; i<=m; i++){
        read(opt); read(x); read(y);
        if(opt == 1) add(x, y);
        else printf("%lld\n", query(y)-query(x-1));
    }
    return 0;
}
