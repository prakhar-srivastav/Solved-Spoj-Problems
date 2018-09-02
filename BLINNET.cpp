#include <iostream>
#define ll long long
#include <stdio.h>
#include <algorithm>
#include <vector>

#include <utility>
using namespace std;
ll size[10001];
ll arr[10001];
vector <pair<ll,pair<ll,ll> > > v;
vector <int> res ;
ll root(ll x)
{
    while(arr[x]!=x)
    {

    arr[x]=arr[arr[x]];
            x=arr[x];
    }
    return x;
}
void unite(ll a,ll b)
{

    a=root(a);
    b=root(b);
    ll a1=size[a];
    ll b1= size[b];

    if(a1<b1)
    {
    arr[a]=b;
    size[b]=a1+b1;
    }
    else
    {
        arr[b]=a;
        size[a]=a1+b1;
    }

}

void solve()
{

    ll n ;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        char x[21];
        scanf("%s",x);

        ll a;
        scanf("%lld",&a);
        for(int j=1;j<=a;j++)
        {
            ll p,q;
            scanf("%lld%lld",&p,&q);
            if(i<p)
            {
                v.push_back(make_pair(q,make_pair(i,p)));

            }}
    }
    for( ll i=1;i<=n;i++)
        {
            arr[i]=i;
            size[i]=1;
        }
    ll result=0;
    ll counter=0;
           sort(v.begin(),v.end());

           for(ll i=0;i<v.size();i++)
           {
               ll x,y;
               x=v[i].second.first;
               y=v[i].second.second;
               if(root(x)!=root(y))
               {
                   counter++ ;
                   unite(x,y);
                   result+=v[i].first;
               }
               if(counter==n) break;
           }
         res.push_back(result);

    }








int main()
{

int tt ;
scanf("%lld",&tt);
while(tt--)
{
    solve();
    v.clear();
}
for(int i=0;i<res.size();i++) cout << res[i] << endl;
}
