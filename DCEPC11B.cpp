#include <iostream>
using namespace std ;
#define ll long long

ll solve1(ll a, ll b , ll p)
{

    ll x=1,y=a;
    while(b>0)
    {
        if(b%2!=0)
        x=(x*y)%p;
        y=(y*y)%p;
        b=b/2;
    }
    return x%p;
}

void solve()
{
    ll n,p ;
    cin >>n >> p ;
    if(n>=p)
        cout << 0 << endl;
    else
    {
        ll temp ,result =-1;
      for( ll i=n+1;i<p;i++)
      {
          temp =solve1(i,p-2,p);
          result =(result*temp)%p;
      }
        cout << result+p << endl;
    }



}
int main()
{

    ll t ;
    cin >> t ;
    while(t--) solve();
}
