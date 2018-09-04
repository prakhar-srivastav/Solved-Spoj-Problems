#include <iostream>
#include <algorithm>
#define ll long long
using namespace std ;


void solve()
{
    int n ;
    cin >> n ;
    int a[n] , b[n] ;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    int sum=0;
    for(int i=0;i<n;i++) sum+=a[i]*b[i];
    cout << sum << endl;
}

int main()
{
int t;
cin >> t ;
    while(t--)
    {
        solve();
    }
}
