#include <iostream>
#include <math.h>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll x;
		cin >> x;
		ll y=pow(2,x-1);
		ll z=y+(y/2)*(x-1);
		cout << y << " " << z << endl;
	}
}