#include <iostream>
#define ll long long
using namespace std ;

void solve()
{
     ll a , b;
     cin >> a >> b;
     if(b==0)
     {
         cout << 1 << endl;
         return;
     }
     a=a%10 ;

     int arr[1000];
     arr[1]=a;
     int r=a;
     int x=2;
     while(1)
     {
         r=a*r;
         r=r%10;
         if(a==r) break;
         arr[x++]=r;
     }

     x--;
     arr[0]=arr[x];
     ll val = b % x ;

     cout << arr[val] << endl;
}
 int  main()
 {
     int t ;
     cin >> t ;
     while(t--)
     {
         solve();
     }

 }
