#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf (1e9+7)
#define ls 0
#define rs 1
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
int tot, c[maxn][2], fa[maxn], cnt[maxn], siz[maxn], v[maxn], rt;
int get(int x){return c[fa[x]][1] == x;}
void push_up(int x){siz[x] = cnt[x] + siz[c[x][0]] + siz[c[x][1]];}
void rotate(int x){
	int y = fa[x], z = fa[y], gx = get(x);
	c[y][gx] = c[x][gx^1]; if(c[x][gx^1]) fa[c[x][gx^1]] = y;
	c[x][gx] = y; fa[y] = x;
	if(z) c[z][c[z][1]==y] = x;
	fa[x] = z;
	push_up(y); push_up(x);
}
void splay(int x, int goal){
	while(fa[x] != goal){
		int y = fa[x], z = fa[y];
		if(z != goal){
			if(get(x) == get(y)) rotate(y);
			else rotate(x);
		}
		rotate(x);
	}
	if(goal == 0) rt = x;
}
void ins(int x){
	int t = rt, f = 0;
	while(t && v[t] != x){siz[t]++; f = t; t = c[t][x>v[t]];}
	if(t && v[t] == x){
		cnt[t]++; siz[t]++; splay(t, 0);
	}
	else{
		v[++tot] = x; siz[tot] = cnt[tot] = 1; t = tot;
		if(f) c[f][x>v[f]] = t;
		fa[t] = f; splay(t, 0);
	}
}
int pre(){ int x = c[rt][0] ; while(c[x][1]) x = c[x][1]; return x; }
int nxt(){ int x = c[rt][1] ; while(c[x][0]) x = c[x][0]; return x; }
int find(int val){
	int x = rt;
	while(v[x] != val) x = c[x][val>v[x]];
	splay(x, 0);
}
void del(int x){
	find(x); int y = pre(), z = nxt();
	splay(z, 0); splay(y, z);
	int t = c[y][0];
	if(cnt[t]) {cnt[t]--; siz[t]--; push_up(y); return;}
	else fa[t] = siz[t] = cnt[t] = c[y][0] = 0 , push_up(y);

}

signed main(){
	int n, opt, x;
	read(n);
	ins(-inf); ins(inf);
	for(int i=1; i<=n; i++) {
		read(opt); read(x);
		if(opt == 1) ins(x);
		if(opt == 2) del(x);
		if(opt == 3) 
		if(opt == 4)
		if(opt == 5){
		}
		if(opt == 6){
		}
		//tr.print(tr.rt);
	}
    return 0;
}
/*10
1 3
1 4
1 5
1 6
1 1
*/
//https://www.luogu.org/paste/xqyo4eio?tdsourcetag=s_pctim_aiomsg