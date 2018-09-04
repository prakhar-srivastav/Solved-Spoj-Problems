#include <iostream>
#define ll long long
using namespace std ;

 int t ;
void solve()
{
    ll s=0;
    for(ll i=1;i<=t;i++) s+= i*i ;
    cout << s << endl;


}

int main()
{

    while(1)
    {
        cin >> t;
        if(t==0) break;
        solve();
    }
}
