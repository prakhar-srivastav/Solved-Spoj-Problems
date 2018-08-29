#include <iostream>
#include <stdio.h>
#define ll int
using namespace std;
double dp[545][1908];

void solve()

{


    ll n,k;
    scanf("%d%d",&n,&k);
    if(n>545 || k>1908)
    {

        printf("0\n");

    }
    else
    {

        for(int i=0;i<=n;i++) dp[i][0]=0.0;
        for(int i=0;i<=k;i++) dp[0][i]=0.0;
        dp[0][0]=1.0;
double m=1;
m=m/6;
     for(int i=1;i<=k;i++)
     {
         dp[1][i]=0;
         if(i<=6) dp[1][i]=m;
     }

        for(int i=2;i<=n;i++)
        {
                for(int j=1;j<=k;j++)
        {
            dp[i][j]=0;
           for(int k=1;k<=6;k++)
           {
               if(j-k>=0)dp[i][j]+=dp[i-1][j-k];
           }
           dp[i][j]=dp[i][j]/6;

        }

        }
printf("%d\n",int(dp[n][k]*100));

        }

}


int main()
{
int x ;
scanf("%d",&x);
while(x--) solve();

}



