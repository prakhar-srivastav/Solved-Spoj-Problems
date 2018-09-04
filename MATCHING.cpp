#include <iostream>
using namespace std ;
#include <vector>
#include <stdio.h>
#define ll int
#define inf (1<<28)
#define nil 0
#include <queue>
vector<ll> arr[150007];
ll match[150007];
ll dis[150007];

bool bfs(ll a)
{queue <ll > s ;
    for(ll i=1;i<=a;i++)
    {
        if(match[i]==nil)
        {
            dis[i]=0;
            s.push(i);
        }
        else
        {
            dis[i]=inf;
        }
    }
        dis[nil]=inf;
        while(!s.empty())
        {
            ll a=s.front();
            s.pop();
             if(a!=nil)
             {
                 for(ll i=0;i<arr[a].size();i++)
                 {
                     if (dis[match[arr[a][i]]]==inf)
                     {
                         dis[match[arr[a][i]]]=dis[a]+1;
                         s.push(match[arr[a][i]]);
                     }
                 }
             }
        }

        return (dis[nil]!=inf);
}

bool dfs( ll a)
{
  if(a!=nil)
  {
      ll m;
      for(ll i=0;i<arr[a].size();i++)
      {
          m=arr[a][i];
          if(dis[match[m]]==dis[a]+1)
            if(dfs(match[m])==true)
          {
              match[a]=m;
              match[m]=a;
              return true;
          }
      }
      dis[a]=inf;
      return false;
  }
  return true;
}
int main()
{
    ll a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    for(ll i=1;i<=c;i++)
    {
        ll p,q;
        scanf("%d%d",&p,&q);
        arr[p].push_back(q+a);
        arr[q+a].push_back(p);
    }
    ll match1=0;
        for(ll i=1;i<=a;i++)
        match[i]=nil;
        for(ll i=a+1;i<=a+b;i++)
        match[i]=nil;
    while(bfs(a))
    {

        for(ll i=1;i<=a;i++)
        {
            if(match[i]==nil )
                if(dfs(i)==true)
                match1++;
        }
    }
    printf("%d",match1);
}
