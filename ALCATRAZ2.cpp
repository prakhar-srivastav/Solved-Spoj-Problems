#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
#define ll long long

using namespace std ;

vector < ll > v[9];
ll arr[9];
ll dp[ 1 << 8];
ll make( ll x)
{
    ll ans=0;
    for(ll i=0; i<v[x].size();i++)
    {
       ll  a = v[x][i];
        ans += (1 << (a-1));
    }
    return ans ;
}
int main()
{

 ll n ;

 for(ll i=1;i<=8;i++) cin >> arr[i];

 cin >> n ;
 for( ll i=1;i<=n;i++)
    {
        ll a,b ;
        cin >> a >> b ;
        if(a>b)
        {
            a=a+b;
            b=a-b;
            a=a-b;
        }
        v[b].push_back(a);
    }
    dp[0]=0;
    dp[1]=arr[1];
    ll max1=0;
    for(ll i=2 ;i<=8;i++)
    {
      ll m = make(i);
        for( ll j=0;j<=pow(2,i-1)-1;j++)
        {
           ll r= m&j;


            if(r == 0)
            {

                 ll y=(1 << i-1);
                y=y |j;



                dp[y]=dp[j]+arr[i];
                if(max1 <=dp[y])
                {
                    max1=dp[y];
                }
            }
        }
    }
    cout << max1 << endl;


}
