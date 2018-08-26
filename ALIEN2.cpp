#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std ;
ll dp[3][100000];
ll arr[3][100000];
ll st;

ll min(ll a,ll b)
{
    if(a<b) return a ;
    return b;
}


 int main()
 {
    ll n,k;
    scanf("%lld%lld",&n,&k);

    for(ll i=1;i<=n;i++) scanf("%lld",&arr[1][i]);
    for(ll i=1;i<=n;i++) scanf("%lld",&arr[2][i]);

    if(n==1)
        printf("1 %lld",min(arr[1][1],arr[2][1]));
    else
    {
       dp[1][1]=arr[1][1],dp[2][1]=arr[2][1];
       int flag=0;
       for(int i=2;i<=n;i++)
       {
           dp[1][i]=min(dp[1][i-1],dp[2][i-1]+arr[2][i]);
           dp[1][i]+=arr[1][i];
           dp[2][i]=min(dp[2][i-1],dp[1][i-1]+arr[1][i]);
           dp[2][i]+=arr[2][i];
           if(dp[1][i] >k && dp[2][i] > k)
           {
               flag=1;
               printf("%lld %lld\n",i-1,min(dp[1][i-1],dp[2][i-1]));
               break;
           }
       }
       if(flag==0)
       {
           printf("%lld %lld\n",n,min(dp[1][n],dp[2][n]));
       }
    }


 }
