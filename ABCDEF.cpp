#include <vector>
#include <algorithm>
#include <iterator>
#define ll long long
#include <iostream>
#define mx 101
#include <stdio.h>
using namespace std ;
ll arr[mx];
int main()
{

    vector <ll> v1,v2;
    ll n ,ub,lb;
    scanf("%lld",&n );
    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);

    }

    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
        for(ll k=0;k<n;k++)
    {
        v1.push_back(arr[i]*arr[j]+arr[k]);
        if(arr[k]!=0)
            v2.push_back((arr[i]+arr[j])*arr[k]);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    ll res=0;
    for(ll i=0;i<v1.size();i++)
    {
        ub=upper_bound(v2.begin(),v2.end(),v1[i])-v1.begin();
        lb=lower_bound(v2.begin(),v2.end(),v1[i])-v1.begin();
        res=res+ub-lb;
    }
    printf("%lld",res);
}
