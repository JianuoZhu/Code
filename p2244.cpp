#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1000010;
int n,num[N];
struct node{int to,next,u;}e[N];int head[N],ecnt;
void add(int u,int v){e[++ecnt].u=u;e[ecnt].to=v;e[ecnt].next=head[u];head[u]=ecnt;}
queue<int> que;
bool win[N];
int tot=0;
int pre[N],ne[N];
void del(int i){int l=pre[i],r=ne[i];ne[l]=r,pre[r]=l;}
void bfs()
{
    while(!que.empty())
    {
        int x=que.front();que.pop();
        int j=head[x];
        for(int i=pre[n+1];i;i=pre[i])
        {
            while(i<e[j].to)
                j=e[j].next;
            if(i!=e[j].to)
            {
                tot++;
                que.push(i);
                win[i]=1;
                del(i);
            }
        }
    }
}
int main()
{
    freopen("ele.in","r",stdin);
    freopen("ele.out","w",stdout);
    cin>>n;
    int maxnum=0;
    for(int i=1;i<=n;++i)
        pre[i]=i-1,ne[i]=i+1;
    pre[n+1]=n;
    ne[0]=1;
    for(int i=1,a=0,b;i<=n;++i)
    {
        scanf("%d",&num[i]);
        if(num[i]>maxnum)
            maxnum=num[i];
        for(int j=1;j<=num[i];++j)
        {
            scanf("%d",&b);
            add(i,b);
        }
    }
    for(int i=1;i<=n;++i)
        if(num[i]==maxnum)
        {
            tot++;
            que.push(i);
            win[i]=1;
            del(i);
        }
    bfs();
    printf("%d ",tot);
    for(int i=1;i<=n;++i)
        if(win[i])
            printf("%d ",i);
    return 0;
}