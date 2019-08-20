#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define DEBUG printf("PassedLine:%d\n", __LINE__)
#define inf 1e9+7
#define int long long
const int maxn = 1e5+10, maxch = ;
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
    int end, son[30];
}tr[maxch];
using namespace std;
int n, cnt;
char s[maxn];
queue<int> q;
void build(){
    int len = strlen(s+1);
    int x = 0;
    for(int i=1; i<=len; i++){
        int c = s[i] - 'a';
        if(!tr[x].son[c]) tr[x].son[c] = ++cnt;
        x =tr[x].son[c];
    }
    tr[x].end++;
}
void get_fail(){
    for(int i=0; i<26; i++)
        if(tr[0].son[i]){tr[tr[0].son[i]].fail = 0; q.push(tr[0].son[i])}
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
signed main(){
    read(n);
    for(int i=1; i<=n; i++){
        scanf("%s", s+1);
        build();
    }
    tr[0].fail = 0;
    get_fail();

    return 0;
}
