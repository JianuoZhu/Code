#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
#define il inline
#define re register
#define debug printf("Now is Line : %d\n",__LINE__)
#define file(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
//#define int long long
#define D double
#define inf 123456789
#define mod 1000000007
il int read() {
    re int x = 0, f = 1; re char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
    return x * f;
}
#define rep(i, s, t) for(re int i = s; i <= t; ++ i)
#define drep(i, s, t) for(re int i = t; i >= s; -- i)
#define Next(i, u) for(re int i = head[u]; i; i = e[i].next)
#define mem(k, p) memset(k, p, sizeof(k))
#define lb(x) (x)&(-(x))
#define ls k * 2
#define rs k * 2 + 1
#define maxn 1005
#define ID(x, y) ((x) - 1) * (m + 1) + (y)
int n, m, q, ans, fa[maxn * maxn], a[maxn][maxn], fa1[maxn][maxn];
char c[maxn];
il int find(int x) {
	while(x != fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}
il void merge(int a, int b) {
	int l = find(a), r = find(b);
	if(l != r) -- ans, fa[l] = r;
}
il int find1(int k, int x) {
	while(x != fa1[k][x]) x = fa1[k][x] = fa1[k][fa1[k][x]];
	return x;
}
il void merge1(int k, int a, int b) {
	int l = find1(k, a), r = find1(k, b);
	if(l != r) fa1[k][l] = r;
}
int fx[4] = {-1, 0, 0, 1}, fy[4] = {0, -1, 1, 0};
il void solve(int k, int l, int b) {
	for(re int now = l; now <= b; now = find1(k, now)) {
		a[k][now] = 1, merge1(k, now, now + 1), ++ ans;
		rep(i, 0, 3) {
			int vx = k + fx[i], vy = now + fy[i];
			if(a[vx][vy]) merge(ID(vx, vy), ID(k, now));
		}
	}
}
il void print(int x) {
	if(!x) return;
	print(x / 10), putchar(x % 10 + '0');
}
signed main() {
    //file(grid);
    n = read(), m = read();
    rep(i, 1, n * (m + 1)) fa[i] = i;
    rep(i, 1, n) {
    	scanf("%s", c + 1);
    	rep(j, 1, m) a[i][j] = c[j] - '0';
	}
	rep(i, 1, n) {
		int now = m + 1;
		fa1[i][m + 1] = now;
		drep(j, 1, m) {
			if(a[i][j] == 0) now = j;
			fa1[i][j] = now;
		}
	}
	rep(i, 1, n) {
		rep(j, 1, m) {
			if(!a[i][j]) continue;
			++ ans;
			if(a[i - 1][j]) merge(ID(i - 1, j), ID(i, j));
			if(a[i][j - 1]) merge(ID(i, j - 1), ID(i, j));
		}
	}
	q = read();
	while(q --) {
		int x1 = read(), y1 = read(), x2 = read(), y2 = read();
		rep(i, x1, x2) solve(i, find1(i, y1), y2);
		print(ans), putchar('\n');
	} 
    return 0;
}
