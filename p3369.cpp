#include<cstdio>
#include<iostream>
#include<cstdlib>
const int maxn = 4e5+10, inf = 1e9+7;
inline void read(int &x){
    x = 0; char c = getchar();
    int w = 1;
    while((c < '0' || c > '9') && c != '-') c = getchar();
    if(c == '-') w = -1, c = getchar();
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    x *= w;
}
int siz[maxn], c[maxn][2], fa[maxn], cnt[maxn], tot, val[maxn], rt;

struct Splay{
    void push_up(int x){
         siz[x] = siz[c[x][0]] + siz[c[x][1]] + cnt[x];
    }
    int get(int x){
        return c[fa[x]][1] == x;
    }
    void rotate(int x){
        int y = fa[x], z = fa[y], w = get(x);
        c[y][w] = c[x][w^1];
        if(c[y][w]) fa[c[y][w]] = y;
        c[x][w^1] = y; fa[y] = x;
        if(z) c[z][c[z][1]==y] = x;
        fa[x] = z; push_up(y); push_up(x);
    }
    void splay(int x, int goal){
        while(fa[x] != goal){
            int f = fa[x];
            if(fa[f] != goal){
                if(get(f) == get(x)) rotate(f);
                else rotate(x);
            }
            rotate(x);
        }
        if(goal == 0) rt = x;
        return;
    }
    void insert(int x){
        int now = rt, f = 0;
        while(now && val[now] != x) siz[now]++, f = now, now = c[now][x>val[now]];
        if(val[now] == x) cnt[now]++, push_up(now);
        else{
            ++tot; cnt[tot] = siz[tot] = 1; val[tot] = x;
            if(f) c[f][x>val[f]] = tot; 
            fa[tot] = f; now = tot;
        }
        splay(now, 0);
    }
    int get_pre(){
        int x = c[rt][0];
        while(c[x][1]) x = c[x][1];
        return x;
    }
    int get_suc(){
        int x = c[rt][1];
        while(c[x][0]) x = c[x][0];
        return x;
    }
    void find(int k){
        int x = rt;
        while(val[x] != k && c[x][val[x]<k]) x = c[x][val[x]<k];
        splay(x, 0);
    }
    void del(int x){
        find(x); int pre = get_pre(), suc = get_suc();
        splay(pre, 0); splay(suc, pre);
        x = c[suc][0];
        if(cnt[x] > 1){cnt[x]--; push_up(suc); splay(x, 0);}
        else {fa[x] = siz[x] = cnt[x] = c[suc][0] = 0; push_up(suc);}
    }
    int kth(int k){
        int x = rt; if(siz[x] < k) return 0;
        while(x){
            if(k > (cnt[x] + siz[c[x][0]])) k -= cnt[x] + siz[c[x][0]], x = c[x][0];
            else if(k > siz[c[x][0]]) return val[x];
            else x = c[x][0];
        }
        return -1;
    }
}tr;
int n;
int main(){
    read(n); int x, opt;
    tr.insert(inf); tr.insert(-inf);
    for(int i=1; i<=n; i++){
        read(opt); read(x);
        if(opt == 1) tr.insert(x);
        if(opt == 2) tr.del(x);
        if(opt == 3) {tr.find(x); printf("%d\n", siz[c[rt][0]]);}
        if(opt == 4) printf("%d\n", tr.kth(x+1));
        if(opt == 5) {tr.insert(x); printf("%d\n", val[tr.get_pre()]); tr.del(x);}
        if(opt == 6) {tr.insert(x); printf("%d\n", val[tr.get_suc()]); tr.del(x);}
    }
    return 0;
}
/*
10
1 1
1 2
1 3
3 2
*/