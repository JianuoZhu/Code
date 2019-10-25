#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
#define int long long
#define ls (x*2)
#define rs (x*2+1)
const int maxn = 1e5+10, maxnn = 1e4+10;
inline int mmax(int a, int b){return a>b?a:b;}
inline int mmin(int a, int b){return a<b?a:b;}
inline int aabs(int a){return a>0?a:-a;}
inline void read(int &x){
     x = 0; char c = getchar(); int w = 1;
     while(c < '0' || c > '9'){if(c == '-') w = -1; c = getchar();}
     while(c >= '0' && c <= '9') x = x*10+c-'0', c = getchar();
     x *= w;
}
struct node{
    int sum, l, r;
}tr1[maxnn << 2], tr2[maxnn << 2];
using namespace std;
int n, a[maxn], b[maxn];
void build(int x, int l, int r){
    tr1[x].l = l; tr1[x].r = r; tr1[x].sum = 0;
    tr2[x].l = l; tr2[x].r = r; tr2[x].sum = 0;
    if(l == r) return;
    int mid = (l+r)/2;
    build(ls, l, mid); build(rs, mid+1, r);
}
void add1(int x, int val){
    if(tr1[x].l == tr1[x].r){tr1[x].sum++; return;}
    int mid = (tr1[x].l + tr1[x].r) / 2;
    if(val <= mid) add1(ls, val);
    else add1(rs, val);
    tr1[x].sum = tr1[ls].sum + tr1[rs].sum;
}
void add2(int x, int val){
    if(tr2[x].l == tr2[x].r){tr2[x].sum++; return;}
    int mid = (tr2[x].l + tr2[x].r) / 2;
    if(val <= mid) add2(ls, val);
    else add2(rs, val);
    tr2[x].sum = tr2[ls].sum + tr2[rs].sum;
}
int query1(int x, int val){
    if(tr1[x].l == tr1[x].r){return tr1[x].sum;}
    int mid = (tr1[x].l + tr1[x].r) / 2;
    if(val <= mid) return query1(ls, val);
    else return tr1[ls].sum + query1(rs, val);
}
int query2(int x, int val){
    if(tr2[x].l == tr2[x].r){return tr2[x].sum;}
    int mid = (tr2[x].l + tr2[x].r) / 2;
    if(val <= mid) return query2(ls, val);
    else return tr2[ls].sum + query2(rs, val);
}
signed main(){
    int t;
    read(t);
    while(t--){
        read(n);
        build(1, 1, 10001);
        int ans1 = 0, ans2 = 0;
        for(int i=1; i<=n; i++) read(a[i]), add1(1, a[i]);
        for(int i=1; i<=n; i++) read(b[i]), add2(1, b[i]);
        for(int i=1; i<=n; i++) ans1 += query2(1, a[i]);
        for(int i=1; i<=n; i++) ans2 += query1(1, b[i]);
        if(ans1 == ans2) printf("Tie\n");
        if(ans1 >  ans2) printf("Alice\n");
        if(ans1 <  ans2) printf("Bob\n");
    }
    return 0;
}