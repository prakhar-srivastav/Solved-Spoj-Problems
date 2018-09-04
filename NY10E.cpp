#include <iostream>
#define ll unsigned long long int
#include <stdio.h>
using namespace std ;
ll dp[100][100];
 int max(int a,int b)

 {
     if(a>b) return a ;
     return b;
 }
ll n;
ll t1=1;
ll ans(ll i,ll d)
{
    ll x=0 ;

    if(d ==0 ) return 1 ;

    if(dp[i][d]!=-1) return dp[i][d];
    for(int j=i;j<=10;j++)
    {

        x=x+ans(j,d-1);

    }
    dp[i][d]=x;
    return x ;

}
 void solve()
{

    ll w;
    cin >> w >> n ;
    for(ll i=1;i<=10;i++)
        for(ll j=1;j<=n;j++)
    {
        dp[i][j]=-1;
    }

    cout << t1++ << " "<< ans(1,n) << endl;
}
 int main()
 {
     int t ;
     scanf("%d",&t);
     while(t--)
     {
         solve();
     }

 }
