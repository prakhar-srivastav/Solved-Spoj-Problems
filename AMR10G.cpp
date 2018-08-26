#include <iostream>
#define ll long long
#include <bits/stdc++.h>

using namespace std ;
int min1(int a , int b)
{
    return a<b? a:b;
}

int arr[20001 ];
void solve()
{

    ll n, k ;
    cin >> n >> k ;
    for(ll i=1 ;i<=n;i++)
    {
    cin >> arr[i];
    }
    sort(arr+1,arr+n+1);

    ll m=arr[k]-arr[1];
    for(ll i=1 ;i+k<=n+1;i++)
    {
        m=min1(arr[k+i-1]-arr[i],m);

    }

    cout << m << endl;
}

 int main()
 {

      ll t ;
      cin >>t ;
      while(t--) solve();
 }
