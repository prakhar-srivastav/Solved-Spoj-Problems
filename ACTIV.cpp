#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std ;

struct r
{
    ll a , b;
};
struct r ran[1000000];
ll dp[1000000];
bool comp(struct r r1 , struct r r2)
{
    return r1.a<r2.a?true:false;
}

 ll search1 ( ll val , ll l, ll u)
 {
     ll flag=0;ll m;
     while(l<u)
     {
          m=l+u ;
         m=m/2;
                if(ran[m].a==val)
                    u=m;
          else if(ran[m].a < val)
            l=m+1 ;
           else
            u=m;

     }
     return l ;
 }
 void zero(ll x)
 {
     ll r ;
     ll c=0;
     while(1)
     {
         if(x<=0) break;
         x=x/10;
         c++;
     }
        for(ll i=1 ;i<=8-c;i++ ) cout << 0;
 }

 int main()
 {
  while(1)
  {
      ll n ;
  cin >> n ;
  if(n==-1) break ;
  for(ll i=1;i<=n;i++)
  {
      cin >> ran[i].a >> ran[i].b ;
  }

  dp[n+1]=0;
  sort(ran+1,ran+n+1,comp);
  for(ll i=n;i>=1;i--)
  {

      if(ran[i].b >ran[n].a)
        dp[i]=1+dp[i+1];
        else
        {
            ll x =search1(ran[i].b,i,n);

         dp[i]=dp[x]+1+dp[i+1];
        }
        dp[i]=dp[i]%100000000;
  }
  dp[1]=dp[1]%100000000;
  zero(dp[1]);
  cout << dp[1] << endl;
  }

 }
