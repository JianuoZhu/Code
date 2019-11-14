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
struct node{
    int l, r, sum;
}tr1[maxn << 2], tr2[maxn << 2];
void build1(int x, int l, int r){
    tr1[x].l = l; tr1[x].r = r;
    if(l == r) return;
    int mid = (l+r)/2;
    build1(ls, l, mid); build1(rs, mid+1, r);
}
void build2(int x, int l, int r){
    tr2[x].l = l; tr2[x].r = r;
    if(l == r) return;
    int mid = (l+r)/2;
    build2(ls, l, mid); build2(rs, mid+1, r);
}
void modify1(int x, int p){
    if(tr1[x].l == tr1[x].r){tr1[x].sum ^= 1; return;}
    int mid = (tr1[x].l + tr1[x].r) / 2;
    if(p <= mid) modify1(ls, p);
    else modify1(rs, p);
    tr1[x].sum = tr1[ls].sum + tr1[rs].sum;
}
void modify2(int x, int p){
    if(tr2[x].l == tr2[x].r){tr2[x].sum ^= 1; return;}
    int mid = (tr2[x].l + tr2[x].r) / 2;
    if(p <= mid) modify2(ls, p);
    else modify2(rs, p);
    tr2[x].sum = tr2[ls].sum + tr2[rs].sum;
}
int query1(int x, int l, int r){
    if(tr1[x].l >= l && tr1[x].r <= r) return tr1[x].sum;
    int mid = (tr1[x].l + tr1[x].r)/2, ans = 0;
    if(l <= mid) ans += query1(ls, l, r);
    if(r >  mid) ans += query1(rs, l ,r);
    return ans;
}
int query2(int x, int l, int r){
    if(tr2[x].l >= l && tr2[x].r <= r) return tr2[x].sum;
    int mid = (tr2[x].l + tr2[x].r)/2, ans = 0;
    if(l <= mid) ans += query2(ls, l, r);
    if(r >  mid) ans += query2(rs, l ,r);
    return ans;
}
int n, m, q;
signed main(){
    read(n); read(m); read(q);
    build1(1, 1, n); build2(1, 1, m);
    int opt, x1, x2, y1, y2;
    for(int i=1; i<=q; i++){
        read(opt);
        if(opt == 1){
            read(x1); read(y1); modify1(1, x1); modify2(1, y1);
        }
        if(opt == 2){
            read(x1); read(y1); read(x2); read(y2);
            int x = query1(1, x1, x2), y = query2(1, y1, y2);
            int ans = x*(y2-y1+1) + y*(x2-x1+1);
            ans -= 2*x*y;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
