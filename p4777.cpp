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
int gcd(int a, int b){
    return(b == 0 ? a : gcd(b, a%b));
}
int n, a[maxn], b[maxn];
signed main(){
    read(n);
    for(int i=1; i<=n; i++){
        read(a[i]); read(b[i]);
    }
    m[0] = 1;
    for(int i=1; i<=n; i++) m[i] = m[i-1] * b[i];
    int x = a[1];
    for(int i=2; i<=n; i++){
        int k = 0;
        
    }
    return 0;
}
