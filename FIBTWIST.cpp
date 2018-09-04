#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std ;


ll m;
void reset(ll arr[2][2])
{
    arr[0][0]=1;
    arr[0][1]=1;


    arr[1][0]=1;
    arr[1][1]=0;


}
void mult( ll a[2][2] , ll b[2][2] , ll c[2][2])
{

    c[0][0]=((a[0][0]%m)*(b[0][0]%m))%m + ((a[0][1]%m)*(b[1][0]%m))%m ;
    c[0][1]=((a[0][0]%m)*(b[0][1]%m))%m + ((a[0][1]%m)*(b[1][1]%m))%m ;
    c[1][0]=((a[1][0]%m)*(b[0][0]%m))%m + ((a[1][1]%m)*(b[1][0]%m))%m ;
    c[1][1]=((a[1][0]%m)*(b[0][1]%m))%m + ((a[1][1]%m)*(b[1][1]%m))%m ;

    c[0][0]=c[0][0]%m;
    c[0][1]=c[0][1]%m;
    c[1][0]=c[1][0]%m;
    c[1][1]=c[1][1]%m;

}
void fun ( ll arr[2][2], ll n )
{
    ll arr1[2][2],arr2[2][2],arr3[2][2];
    reset(arr2);
    reset(arr3);
    reset(arr1);
    if(n==1)
        return ;
    if(n%2==0)
    {
        fun(arr1,n/2);
        mult(arr1,arr1,arr);
    }
    else
    {
        fun(arr1,n/2);
        mult(arr1,arr1,arr2);
        mult(arr2,arr3,arr);


    }
}

int main()
{
    ll n;
    int t ;
    scanf("%d",&t);
    ll arr[2][2];

    while(t--)
    {
reset(arr);
   scanf("%lld%lld",&n,&m);
    if(n==0)
    {
      printf("0\n");
    }
    else if (n==1)
       {
          printf("1\n");
       }
       else
       {
         fun(arr,n+2);
        ll sum =2*(arr[1][0]-1)-n;
        sum=sum%m;
        if(sum<0)
            sum+=m;


         printf("%lld\n",sum);
       }
    }

}
