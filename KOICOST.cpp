#include <iostream>
using namespace std ;
#include <vector>
#include <utility>

#include <stdio.h>
#include <algorithm>
const int MOD = 1000000000;
typedef long long ll ;
ll Arr[100009] ,size1[100009] , sum[100009];
ll root (ll i)
{
    while(Arr[ i ] != i)
    {

i = Arr[ i ];
    }
return i;
}
void initialize(  ll N)
{
    for(ll i = 1;i<=N;i++)
    {
Arr[ i ] = i ;
size1[ i ] = 1;
}
}
void wu(ll A,ll B)
{
    ll root_A = root(A);
    ll root_B = root(B);
    if(size1[root_A] < size1[root_B ])
    {
Arr[ root_A ] = Arr[root_B];
size1[root_B] += size1[root_A];
}
    else
    {
Arr[ root_B ] = Arr[root_A];
size1[root_A] += size1[root_B];
}

}

vector <pair< ll , pair<ll ,ll > > > v ;
int main()
{
    ll m ,n ,o ;
    ll a, b;
    ll p,q,r ;
   scanf("%lld%lld",&a,&b);
      for(ll i=0;i<b;i++)
      {


          scanf("%lld%lld%lld",&p,&q,&r);
          v.push_back(make_pair(r,make_pair(p,q)));
      }
      sort(v.begin(),v.end());

      initialize(a) ;
      ll cc=0 ;
      ll sum1=0;
      for(ll i = 0; i < b; i++) sum[i] = v[i].first + (i > 0 ? sum[i-1] : 0);
      for(ll i=v.size()-1;i>=0;i--)
      {

          m=v[i].first,n=root(v[i].second.first),o=root(v[i].second.second) ;

           if(n!=o) {
                ll x=size1[root(n)], y=size1[root(o)];
            sum1 =  sum1 + x*y*sum[i] ;


            wu(n,o);
           }



      }


    printf("%lld",sum1%MOD);


}
