#include <iostream>
#define ll long long
#include <stdio.h>
#include <algorithm>
#include <vector>
#define ll long long
#include <utility>
using namespace std ;

ll arr[301][301];

ll min(ll a,ll b)
{
    return a>b?b:a;
}
int main()
{
    ll n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        scanf("%lld",&arr[i][j]);


        for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {


        if(arr[i][j]>arr[i][k]+arr[k][j])
           arr[i][j]=arr[i][k]+arr[k][j] ;
    }

    ll x;
    scanf("%lld",&x);
    while(x--)
    {


        ll sum=0;
        ll p,q,r;
        scanf("%lld%lld%lld",&p,&q,&r);
        if(arr[p][q]>r)
        {
            arr[p][q]=r;
            arr[q][p]=r;
        }

         for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {

    arr[i][j] = min(min(arr[i][j],arr[i][p]+ arr[p][q]+arr[q][j]),arr[i][q]+ arr[q][p]+arr[p][j]);

    }


        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            sum+=arr[i][j];
        printf("%lld\n",sum);
    }

}
