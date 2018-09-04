#include<bits/stdc++.h>
#define ll long long
using namespace std ;
map<int,ll> dp;
ll solve(int x)
{
   if(x<12)  return x ;
    if(dp.count(x))
    {

    return dp[x];
    }

   ll y= solve(x/2) +solve(x/3) +solve(x/4);


   dp[x]=y;
   return y;
}
int main()
{
     int x ;

     

    while(scanf("%d",&x)!=EOF)
    {
     printf("%lld\n",solve(x));

    }

}
