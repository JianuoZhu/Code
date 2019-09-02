#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int fa[100005], n, m;
int get_fa(int x){
    return fa[x]==x?x:fa[x]=get_fa(fa[x]);
}
bool check(int x,int y){return get_fa(x)==get_fa(y);}
void merge(int x,int y){
    int la1=get_fa(x),la2=get_fa(y);
    if(la1 == la2) return;
    else fa[la1]=la2;
}
int main(){
    cin >> n >> m;
    int opt, x, y;
    for(int i=1; i<=n; i++) fa[i]=i;
    for(int i=1; i<=m; i++){
        cin >> opt >> x >> y;
        if(opt == 1) merge(x, y);
        else{if(check(x,y)) cout<<"Y";else cout<<"N";cout<<endl;}
    }
    return 0;
}