#include <iostream>
using namespace std;
#include <vector>
#include <stdio.h>
#define ll long long
vector <ll> b[21007];
int arr[21007];

bool dfs(ll u)
{
    bool res=true;

for( ll i=0;i<b[u].size();i++)
{
    ll v=b[u][i];
    if(arr[u]==arr[v])
    {
     return false ;
    }
    if(arr[v]==0)
       {
            arr[v]=3-arr[u];
    res=res and dfs(v);
       }
}
return res ;

}
void solve()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    for(ll i=1 ;i<=k;i++)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        b[x].push_back(y);
        b[y].push_back(x);
    }
    for(ll i=1;i<=n;i++) arr[i]=0;

    

    bool res=true ;
        for( ll i=1;i<=n;i++)
            {
                if(arr[i]==0)
                    arr[i]=1;
                res=res and dfs(i);
            }
    if(res) printf("No suspicious bugs found!\n");
    else
        printf("Suspicious bugs found!\n");


    for(ll i=1;i<=n;i++) b[i].clear();
}
int main()
{
    ll t ;
    ll i=1;
    scanf("%lld",&t);
    while(t--) {
          printf("Scenario #%lld:\n",i++);
        solve();
    }
}
