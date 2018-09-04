#include <iostream>
#include <math.h>
#define ll long long

using namespace std;
int check( ll n)
{
	ll s=sqrt(n);
	for(ll i=2;i<=s;i++)
	{
		if(n%i==0)
		return 0 ;
	}
	return 1;
}
void solve()
{
	ll m,n;
    cin >> m >> n;	
	for( ll i=m;i<=n;i++)
	{if(i!=1)
	{
		
		if(check(i))
		cout << i << endl;
	}
	}
	
}


int main()
{
 int tt;
 cin >> tt;
 while(tt--)
 {
 	solve();
	 }	
}