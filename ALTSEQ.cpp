#include <iostream>
#define ll long long
using namespace std ;
ll n;
ll arr[10000];
ll dp[10000];
ll x ;

bool s(ll a, ll b)
{
    if((a>0 && b>0) || (a<0 && b<0)) return 1 ;
    return 0;
}

ll mod( ll x)
{
    if(x>0) return x ;
    else return (-1*x);
}
ll find1(ll val , ll x)
{
    ll l=1;
    ll u =x ;
    ll flag=0;
    ll m ;
    while(l<u)
    {
         m=(l+u)/2;
        if(mod(arr[dp[m]]) < val)
            l=m+1;
        else if(mod(arr[dp[m]]) > val)
            u=m;
        else
        {
            flag=1;
            break;
        }
    }
    if(flag==1) return m;
    return l;
}
void solve()
{
    for( ll i =2; i<=n;i++)
     {
         if(!s(arr[i],arr[dp[x]]) && mod(arr[i])> mod(arr[dp[x]]))
            dp[++x]= i;
         else if(s(arr[dp[1]],arr[i]) && mod(arr[i])<mod(arr[dp[1]]))
            dp[1]=i;
         else
         {
             if(mod(arr[i])>mod(arr[dp[x]]) ) continue ;
             if(mod(arr[i]) < mod(arr[dp[1]])) continue ;
             ll r= find1(mod(arr[i]),x);

             if(s(arr[i],arr[dp[r]]) && mod(arr[i])!=mod(arr[dp[x]]) )
             dp[r]=i;

         }


     }
}
 int main()
 {
     cin >> n ;
     for(ll i=1 ;i<=n;i++)
        {
            cin >> arr[i];
        }
        if(arr[1]<0)
            for(ll  i=1 ;i<=n;i++)
            arr[i]=arr[i]*(-1);
        dp[1]=1 ;
      x= 1 ;
      solve();
      int m=1 ;
      for(ll i=1 ;i<=n;i++)
      {
          if(arr[i]<0)
            break;
          m++;
      }
      for(ll i=m;i<=n;i++)
      {
          arr[i-m+1]=arr[i];
          arr[i-m+1]=arr[i-m+1]*(-1);

      }
      n=n-m+1;
      ll x1 = x;
      x=1;
      dp[1]=1;


      if(n!=0)
      solve();
      if(x >x1 ) x1=x;

    cout << x1 << endl;

 }
