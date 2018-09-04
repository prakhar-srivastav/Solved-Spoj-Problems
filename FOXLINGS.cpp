#include <iostream>
using namespace std ;
#include <vector>
#include <utility>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#define ll long long
map <int,int> Arr ;
ll root (ll i )
{
    while(Arr[ i ] != i)
    {
Arr[i]=Arr[Arr[i]];
i = Arr[ i ];
    }
return i;
}
void wu(ll a,ll b)
{
Arr[b]=Arr[a];
}

int main ()
{

    ll a, b ;
    scanf("%lld%lld",&a,&b);
    ll ans=a ;
    ll p,q;
    for(ll i=0;i<b;i++)
    {
        scanf("%lld%lld",&p,&q);
        if(Arr[p]==0)
        {
            Arr[p]=p;

        }
        if(Arr[q]==0) Arr[q]=q ;
        if(root(Arr[p])!=root(Arr[q]))
        {
            ans -- ;
            wu(root(Arr[p]),root(Arr[q]));
        }



    }
    printf("%lld",ans);
}
