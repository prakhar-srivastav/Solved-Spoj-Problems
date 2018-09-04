#include <stdio.h>
#include <iostream>
#define ll long long

using namespace std ;

 ll iden[2][2];
ll mod=1000000007;

 void equal( ll a[2][2] ,  ll b[2][2])
 {
     b[0][0]=a[0][0];
     b[0][1]=a[0][1];
     b[1][0]=a[1][0];
     b[1][1]=a[1][1];
 }
 void mult( ll a[2][2], ll b[2][2] , ll c[2][2])
 {

     c[0][0]= (a[0][0]*b[0][0] + a[0][1]*b[1][0])%mod;
     c[0][1]= (a[0][0]*b[0][1] + a[0][1]*b[1][1])%mod;
     c[1][0]= (a[1][0]*b[0][0] + a[1][1]*b[1][0])%mod;
     c[1][1]= (a[1][0]*b[0][1] + a[1][1]*b[1][1])%mod;
 }
void exp( ll arr[2][2], ll x)
 {
     ll arr1[2][2];
     ll arr2[2][2];
     ll arr3[2][2];
     if(x==1)
        return ;

     if(x%2==0)
        {
           exp(arr,x/2);
           mult(arr,arr,arr1);
           equal(arr1,arr);

        }
        else
        {
            mult(arr,iden,arr3);
            exp(arr,x/2);
            mult(arr3,arr,arr2);
            mult(arr2,arr,arr1);
            equal(arr1,arr);

        }
        return;

 }

ll fib(ll x)
{
    if (x==0) return 0;
   ll arr[2][2]={{1,1},{1,0}};
   exp(arr,x);
   return arr[1][0];

}
void solve()
{

   ll a,b ;
   scanf("%lld%lld",&a,&b);
   ll b1= (fib(b+2)-fib(a+1)+mod)%mod;
  
  printf("%lld\n",b1);

}
 int main()
 {

    iden[0][0]=1;
    iden[0][1]=0;
    iden[1][0]=0;
    iden[1][1]=1;
    ll t ;
    scanf("%lld",&t);
    while(t--) solve();

 }
