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
int n, m, a[maxn], num, siz, bl[maxn], b[maxn];
int l[maxn], r[maxn], sum[maxn], add[maxn];
void build(){
    siz = sqrt(n); num = n/siz;
    if(n % siz) num++;
    for(int i=1; i<=n; i++) bl[i] = (i-1)/siz+1, sum[bl[i]]+=a[i];
    for(int i=1;i<=num;i++) l[i]=(i-1)*siz+1,r[i]=i*siz;
    r[num] = n;
}
void Add(int ll, int rr, int k){
    if(bl[ll] == bl[rr]){
        sum[bl[ll]] += (rr-ll+1)*k;
        for(int i=ll; i<=rr; i++) a[i] += k;
        return;
    }
    for(int i=ll; i<=r[bl[ll]]; i++) a[i] += k, sum[bl[i]] += k;
    for(int i=bl[ll]+1; i<bl[rr]; i++) add[i] += k;
    for(int i=l[bl[rr]]; i<=rr; i++) a[i] += k, sum[bl[i]] += k;
}
int query(int ll, int rr){
    int ans = 0;
    if(bl[ll] == bl[rr]){
        for(int i=ll; i<=rr; i++) ans += (a[i] + add[bl[i]]);
        return ans;
    }
    for(int i=ll; i<=r[bl[ll]]; i++) ans += (a[i] + add[bl[i]]);
    for(int i=bl[ll]+1; i<bl[rr]; i++) ans += sum[i] + add[i]*(r[i]-l[i]+1);
    for(int i=l[bl[rr]]; i<=rr; i++) ans += (a[i] + add[bl[i]]);
    return ans;
}
signed main(){
    read(n); read(m);
    for(int i=1; i<=n; i++) read(a[i]);
    build();
    int x, y, k, opt;
    for(int i=1; i<=m; i++){
        read(opt);
        if(opt == 1){
            read(x); read(y); read(k); Add(x, y, k);
        }
        else{
            read(x); read(y); printf("%lld\n", query(x, y));
        }
    }
    return 0;
}
