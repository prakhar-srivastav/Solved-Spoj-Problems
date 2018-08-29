#include <iostream>
#define ll long long
using namespace std ;
int main()
{
    ll n;
    cin >> n;
    ll x=1;
    ll c=0;
    while(1)
    {
      


        if((n/x)<=(x-1)) break;
        c=c+(n/x)-x+1;
        x++;

    }
    cout << c ;

}
