#include <iostream>
#include <vector>
#define ll long long
#include <math.h>
using namespace std ;



int check[32000];
int prime[10000];
void shieve()
{
    for(int i=3;i<=180;i+=2)
    {
        if(!check[i])
        {
            for(int j=i*i;j<=32000;j+=i)
                check[j]=1;
        }
    }
    prime[0] = 2;
    int j=1;
    for(int i=3;i<=32000;i+=2)
    {
        if(!check[i]){
            prime[j++]=i;
        }
    }
}

 int main()
 {
     ll c =0;
 ll a,b,n;
 cin >> a >> b >> n;
 shieve();
  for(ll i =a ;i<=b;i++)
  {

  ll temp=i;
       ll f=1;
      for( ll j=0;prime[j]*prime[j]<=temp;j++)
      {
         ll g=1;

          while(temp>=prime[j])
          {
              if(temp%prime[j]==0)
              {
                  g++;
                  temp=temp/prime[j];
              }
              else
              {
               break;
              }
          }
          f=f*g;
      }
if(temp!=1) f=f*2;
      if(f==n) c++;

  }

cout << c;
 }

