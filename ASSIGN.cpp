#include<iostream>
#include <stdio.h>
#define ll long long
using namespace std;
ll arr[20][20];
ll dp[1<<20];


void solve()
{
   ll n ;
   scanf("%lld",&n);
   for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
        scanf("%lld",&arr[i][j]);

   dp[0]=1;


   for( ll i=1;i<(1<<n);i++)
   {
       ll k=0;
       dp[i]=0;
       for(ll j=0;j<n;j++)
       {
           if((i>>j)&1)
            k++;
       }

       for(ll j=0;j<n;j++)
       {
           if(arr[k-1][j]==1 && (i>>(n-1-j))&1) dp[i]=dp[i]+dp[i&(~(1<<(n-1-j)))];
       }

      }
   printf("%lld\n",dp[(1<<n)-1]);
}
int main()
{
int t ;
scanf("%d",&t);
while(t--) solve();



 }
