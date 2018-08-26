#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

    void solve()
    {

        string  x ,y ;
        cin >> x;
        y=x;
       reverse(x.begin(),x.end());
        if(x==y ) cout << "YES\n";
        else cout << "NO\n";
    }
    int main()
    {
     int t ;
     cin >> t;
     while(t--)
         solve();
    }

