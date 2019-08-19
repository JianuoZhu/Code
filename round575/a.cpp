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
int a, b, c, q;
signed main(){
    read(q);
    while(q--){
    read(a); read(b); read(c);
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    if(a>c) swap(a,c);
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    if(a>c) swap(a,c);
    int d = b-a;
    if(c < d) printf("%I64d\n", a+c);
    else printf("%I64d\n", b+(c-d)/2);
    }
    return 0;
}