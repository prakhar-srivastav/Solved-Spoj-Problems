#include <iostream>
#define  ll long long
using namespace std;
ll element[20000001];

void solve()
{
	for(ll xx=0;xx<20000001;xx++)
	{
		element[xx]=0;
	}
	ll n;
	cin >> n;
	ll arr[n],sum[n+1];
	sum[0]=0;
	ll x;
	for(x=0;x<n;x++){
		cin >> arr[x];
		sum[x+1]=sum[x]+arr[x];
	}
	
	ll j;
	ll c=0;
	for(ll j=0;j<n+1;j++)
	{
		element[sum[j]+10000000]++;
		c+=element[sum[j]+10000000]-1;
	}
	cout << c << endl;
}


int main()
{
	int tt ;
	cin >> tt;
	while(tt--)
	{
		solve();
	}
}