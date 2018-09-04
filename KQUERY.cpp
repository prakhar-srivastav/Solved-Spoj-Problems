#include <iostream>
#include <utility>
#include <stdio.h>
#include<algorithm>
#define ll long long
using namespace std ;
pair<pair <ll,ll>, pair<ll ,ll> > arr[300000];
ll ans[200001];
ll segt[1000000];


bool comp(pair <pair <ll,ll> ,pair <ll,ll> > p1, pair <pair <ll,ll> ,pair <ll,ll> >p2)
 {

     ll a,b;
     a=p1.first.first;
     b=p2.first.first;
     if(a>b) return 1 ;
     else if(a==b)
     {
         ll c,d;
         c=p1.second.second;
         d=p2.second.second;
         if(c!=-1) return 1;
         return 0;
     }

     return 0;
 }
void update(ll pos, ll i,  ll l , ll r )
{
    if(l<=i && i<=r)
        {
            segt[pos]+=1;
            if(l==r) return;
            update(pos*2,i,l,(l+r)/2);
            update(pos*2+1,i,(l+r)/2+1,r);
        }

}
ll range(ll pos, ll i , ll j ,ll l ,ll r )
{
    if(i==l && j==r)
    {
        return segt[pos];
    }
    ll m=(l+r)/2;
    if(j<=m )
    {
        return range(pos*2,i,j,l,m);
    }
    else if(i>m)
    {
        return range(pos*2+1,i,j,m+1,r);
    }
    else
    {
        return range(pos*2,i,m,l,m)+range(pos*2+1,m+1,j,m+1,r);
    }

}
int main()
{
    ll n,k;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        ll x;
        scanf("%lld",&x);
        arr[i]=make_pair(make_pair(x,-1),make_pair(i,-1));
    }
    scanf("%lld",&k);
    for(ll i=n+1;i<=n+k;i++)
    {
        ll x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        arr[i]=make_pair(make_pair(z,i-n),make_pair(x,y));
    }

    sort(&arr[1],&arr[n+k+1],comp);
    ll count=1;
    ll m;

    for( m=1;m<n+k;m=m*2)
        m=m*2-1;
    for(ll i=1;i<=m;i++) segt[i]=0;
    for(ll i=1;i<=n+k;i++)
    {
        ll x,y,z,d;
        x=arr[i].first.first;
        d=arr[i].first.second;
        y=arr[i].second.first;
        z=arr[i].second.second;
        if(z==-1)
        {
            update(1,y,1,n);
        }
        else
        {
                  count++;
            ans[d]=range(1,y,z,1,n);
        }
    }

    for(int i=1;i<count;i++)
        printf("%lld\n",ans[i]);
}
