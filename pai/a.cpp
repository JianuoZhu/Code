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
int n, m, del1[maxn], del2[maxn];
inline int lowbit(int x){return x&(-x);}
void add(int *tr, int x, int k){for(;x<=n;x+=lowbit(x)) tr[x]+=k;}
int query(int *tr, int x){
    int ans = 0;
    for(; x; x-=lowbit(x)){
        ans += tr[x];
    }
    return ans;
}
signed main(){
    freopen("in", "r", stdin);
    int opt, x, y, k;
    read(n); read(m);
    for(int i=1; i<=n; i++){
        read(x); add(del1, i, x); add(del1, i+1, -x); add(del2, i, x*i); add(del2, i+1, -x*(i+1));
    }
    for(int i=1; i<=m; i++){
        read(opt);
        if(opt == 1){
            read(x); read(y); read(k);
            add(del1, x, k); add(del1, y+1, -k); add(del2, x, x*k); add(del2, y+1, -k*(y+1));
        }
        else{
            read(x); read(y);
            int suml = query(del1, x-1)*x - query(del2, x-1);
            int sumr = query(del1, y)*(y+1) - query(del2, y);
            printf("%lld\n", sumr-suml);
        }
    }
    return 0;
}