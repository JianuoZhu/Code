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
int t, n, a[maxn], k, book[maxn], d;
signed main(){
    read(t);
    while(t--){
        read(n); read(k); read(d);
        int _ans = 0, l=1, r=d, ans = 0;
        for(int i=1; i<=n; i++) read(a[i]), book[i] = 0;
        for(int i=1; i<=d; i++){
            book[a[i]]++; if(book[a[i]] == 1) ans++;
        }
        _ans = ans;
        while(r < n){
            book[a[l]]--; if(!book[a[l]]) _ans--;
            book[a[r+1]]++; if(book[a[r+1]]==1) _ans++;
            l++; r++;
            ans = mmin(ans, _ans);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
