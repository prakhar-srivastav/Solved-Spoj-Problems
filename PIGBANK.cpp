#include <iostream>
#include <string.h>
#define ll long long
using namespace std;

ll min(ll a,ll b)
{
    ll c=a;
    if(a>b) c=b;
    return c;
}

void solve()
{
    ll a,b;
    cin >> a >> b;
    a=b-a;
    ll dp[a+1];

    for(ll i=0;i<=a;i++)
    dp[i]=50000000;


    cin >> b ;
    ll val[b] ;ll  wt[b];
    dp[0]=0;
    for(ll i=0;i<b;i++)
        cin >> val[i] >> wt[i];

        for (ll i=0; i<=a; i++)
      for (ll j=0; j<b; j++)
         if (wt[j] <= i)
            {
                dp[i] = min(dp[i], (dp[i-wt[j]]+val[j]));
            }


   if(dp[a]>=50000000)
   cout << "This is impossible.\n";
   else
    cout << "The minimum amount of money in the piggy-bank is "<< dp[a]  << ".\n"<< endl;


}


int main()
{

    int t ;
    cin >> t;
    while(t--) solve();
}
