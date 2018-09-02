#include <vector>
#include <iostream>
using namespace std ;
#define ll long long
#include <algorithm>

ll n;

struct a
{
    ll w,l,b,h;
};
vector <struct a > arr;
void make (ll a, ll b ,ll c)
{
    struct a arr1 ;
    arr1.l=a,arr1.b=b,arr1.h=c;
    arr1.w=a*b;
    arr.push_back(arr1);
}
bool comp (struct a a1 ,struct a a2)
{
    bool x =a2.w<a1.w;
    return  x ;
}


void solve()
{

    ll l,b,h;
     ll pos=0;
    for(ll i=0;i<n;i++)
    {
       cin >> l >> b >> h;
      if( l== b && b==h) make(l,b,h);
        else if( l!=b && b!=h && l!=h)
        {
            make(l,b,h);
            make(l,h,b);
            make(h,b,l);


        }
        else if(l==b)
        {
            make(h,l,b);
            make(l,b,h);

        }
        else if (b==h)
        {
            make(l,b,h);
            make(h,b,l);
        }
        else{
            make(l,b,h);
            make(l,h,b);

        }

          }

          n=arr.size();

sort(arr.begin(),arr.end(),comp);

cout << endl ;

    ll max =arr[0].h;
int a[n];

for(int i=0;i<n;i++) a[i]=arr[i].h;


for(ll i=1;i<n;i++){

    for(ll j=0;j<i;j++)
    {
        if((arr[i].l<arr[j].l && arr[i].b<arr[j].b ) || (arr[i].l<arr[j].b && arr[i].b<arr[j].l ) )
        {
            if(a[i]<arr[i].h+a[j])
            a[i]=arr[i].h+a[j];
        }

    }

    if(a[i]>max) max=a[i];
}


cout << max  << endl;


}
int main()
{

    while(1)
    {
        cin >> n ;
        if(n==0) break ;
        {
            solve();
            arr.clear();

        }
    }
}
