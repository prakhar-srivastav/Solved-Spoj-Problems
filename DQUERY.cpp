#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
#define ll long long


using namespace std ;


ll v[10000001];
ll b;
struct q1
{
    ll a ; ll b; ll c;
};

struct q1 que[10000001];
ll f[10000001];
ll p[10000001];
ll arr[10000001];

bool com(struct q1 a ,struct q1 b1 )
{
     if (a.a/b != b1.a/b)
        return a.a/b < b1.a/b;

    return a.b < b1.b;
}
 int main()
 {
     ll n ,q ;
     scanf("%lld",&n);
     b=sqrt(n);
     for( ll i=1 ;i<=n;i++) scanf("%lld",&arr[i]);
     scanf("%lld",&q);;
     for( ll i=1 ;i<=q;i++)
     {
         scanf("%lld",&que[i].a);
         scanf("%lld",&que[i].b);



        que[i].c=i;
     }

     for (ll i=1 ;i<=n;i++)
     {
         f[i]=0,p[i]=0;
     }
     sort(que+1,que+q+1,com);

     ll l=0,r=0;
     ll l1=0,r1=0 ;
     ll ans =0;
     p[0]=n;
     ans=0 ;
     for( ll i=1 ;i<=q;i++)
     {
         l1=que[i].a;
         ll x;
         r1=que[i].b;
         while(r < r1)
         {
             r++;
             x=arr[r];

             f[x]++;


             if(f[x]==1) ans++;

         }


         while(r > r1)
         {
              x=arr[r];


             f[x]--;
             if(f[x]==0) ans--;

             r--;

         }

         while(l <l1)
         {
             x=arr[l];

             f[x]--;
            if(f[x]==0) ans--;
             l++;


         }

         while(l>l1)
         {
             l--;
             x=arr[l];

             f[x]++;


             if(f[x]==1) ans++;

         }

         v[que[i].c]=ans;
           }
   for( ll i=1;i<=q;i++) printf("%lld\n",v[i]);
 }
