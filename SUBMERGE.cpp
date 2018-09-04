#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std ;
int low[10001];
int disc[10001];
int vis[10001];
int p[10001];
vector <int> g[10001] ;
int aps [10001];
int min(int a,int b)
{

    if(a>b) return b ;
    return a;
}
void ap(int u , int time)
{
    vis[u]=1;
    disc[u]= low[u]=time++;
   int c1=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v= g[u][i];
        if(!vis[v])
        {
            c1++;
            p[v]=u;
            ap(v,time);
            low[u]=min(low[v],low[u]);
            if(disc[u]<=low[v])
                aps[u]=1;
        }
     else if(v!=p[u])
     {
        low[u]=min(disc[v],low[u]);
     }
    }
    if(p[u]==0)
    {
        if(c1>=2)
            aps[u]=1;
        else
            aps[u]=0;
    }

}

void solve(int n, int v)
{
for( int i=1 ; i<=v;i++)
    {
        int a ,b ;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);

    }

    for(int i=1;i<=n;i++)
    {
        low[i]=10000000;
        disc[i]=0;
        aps[i]=0;
        vis[i]=0;
        p[i]=0;
    }

    ap(1,0);

    int count =0;
    for(int i=1;i<=n;i++)
        if(aps[i]) count++ ;
    printf("%d\n",count);

    for(int i=1;i<=n;i++)
        g[i].clear();
}
int main()
{
    int n , v ;
    while(1)
    {


        scanf("%d%d",&n,&v);
        if(n==0 && v==0) break ;
        solve(n,v);

    }
}
