#include <iostream>
#define ll long long
using namespace std ;
ll arr[10000000];

int main ()
{
ll bit[30]={0};
ll n ;
ll temp,t ;
cin >> n ;
t=n;

if(n==1)
{
    cin >> temp;
    cout << temp;
    return 0;
}
while(t--)
{
    cin >> temp;
    for(int i=0;i<20;i++)
    {
         if((temp>>i) & 1)
        bit[i]++;
    }

}
 ll res=0;
 for(int i=0;i<20;i++)
 {
     res+=bit[i] *(n-bit[i]) *(1<<i);
 }
   cout << res ;
   return 0;
}
