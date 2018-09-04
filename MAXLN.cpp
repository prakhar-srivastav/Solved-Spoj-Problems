#include <iostream>
#include <math.h>
#include <stdio.h>
#define ll long long
using namespace std;
int main()
{
    int t,t1=1 ;
     scanf("%d",&t);
     while(t--)
     {

         ll a ;
         scanf("%lld",&a);
         double ans = a*a*4+.25;

         printf("Case %d: %.2lf\n",t1++,ans);
     }
}
