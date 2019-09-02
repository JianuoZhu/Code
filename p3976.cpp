#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
const int maxn = 1e6+10, maxch = 1e6+10;
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
    int end, son[30], fail;
}tr[maxch];
using namespace std;
int n, cnt, _max, tot[maxn];
char s[151][100], st[maxn];
queue<int> q;
void clean(int x){
    memset(tr[x].son, 0, sizeof(tr[x].son));
    tr[x].fail = tr[x].end = 0;
}
void build(int idx){
    int len = strlen(s[idx]+1);
    int x = 0;
    for(int i=1; i<=len; i++){
        int c = s[idx][i] - 'a';
        if(!tr[x].son[c]) tr[x].son[c] = ++cnt;
        x = tr[x].son[c];
    }
    tr[x].end = idx;
}
void get_fail(){
    for(int i=0; i<26; i++)
        if(tr[0].son[i]){tr[tr[0].son[i]].fail = 0; q.push(tr[0].son[i]);}
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i=0; i<26; i++){
            if(tr[u].son[i]){
                tr[tr[u].son[i]].fail = tr[tr[u].fail].son[i]; 
                q.push(tr[u].son[i]);
            }
            else tr[u].son[i] = tr[tr[u].fail].son[i];
        }
    }
}
void get_tot(){
    int len = strlen(st+1);
    int x = 0, ans = 0;
    for(int i=1; i<=len; i++){
        x = tr[x].son[st[i]-'a'];
        for(int u=x; u; u=tr[u].fail){
            if(tr[u].end) tot[tr[x].end]++;
        }
    }
}
signed main(){
    while(19260817){
        read(n);
        clean(0);
        for(int i=1; i<=n; i++){
            scanf("%s", s[i]+1);
            build(i);
        }
        tr[0].fail = 0;
        get_fail();
        scanf("%s", st+1);
        get_tot();
        for(int i=1; i<=n; i++) _max = mmax(_max, tot[i]);
        
    }
    return 0;
}