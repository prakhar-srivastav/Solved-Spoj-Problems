#include <stdio.h>
#define ll long long
#include <string.h>


int main()
{
	ll n;
	scanf("%lld",&n);
    ll a=0;
    ll m;
    for(ll i =0 ;i<n;i++)
 {
 	   scanf("%lld",&m);
       a=a^m;
	 }    
	 printf("%lld",a);
}