#include <iostream>
#include <string>
#include <stdio.h>
using namespace std ;
string str ;
struct node {
int l,r;}
;
 int arr[300][300];
 struct node dp[300][300];

 int max(int a,int b)

 {
     if(a>b) return a ;
     return b;
 }
 int bu(int i, int j, int c)
 {

     if(c==1)
     {
         if(dp[i][j].r!=-1) return dp[i][j].r;
     }
     else
     {
        if(dp[i][j].l!=-1) return dp[i][j].l;
     }
     if(arr[i][j]==2) return 0 ;
     if(arr[i][j]==1)
     {
         if(c==1)
         dp[i][j].r=1;
         else
            dp[i][j].l=1;
     }
     else
     {
      if(c==1)
         dp[i][j].r=0;
         else
            dp[i][j].l=0;
     }
     if(c==1)
     {
         dp[i][j].r+=max(bu(i,j+1,1),bu(i+1,j,-1));
     }
     else
     {
         dp[i][j].l+=max(bu(i,j-1,-1),bu(i+1,j,1));
     }
     if(c==1) return dp[i][j].r;
     else return dp[i][j].l ;


 }

 void solve()

 {

     int m , n ;
     scanf("%d%d",&m,&n);
     for(int i=0;i<=m+1;i++)
        for(int j=0;j<=n+1;j++){
             dp[i][j].l=-1;
             dp[i][j].r=-1;
        }

     for(int i=0;i<=m+1;i++)
     {
         arr[i][0]=2;
     }

     for(int i=0;i<=n+1;i++)
     {
         arr[0][i]=2;
     }

     for(int i=0;i<=n+1;i++)
     {
         arr[m+1][i]=2;
     }

     for(int i=0;i<=m+1;i++)
     {
         arr[i][n+1]=2;
     }
     for(int i=1;i<=m;i++)
        {
            cin >> str ;

            for(int j=0;j<n;j++)
            {
                if(str[j]=='#')
                {
                    arr[i][j+1]=2;
                }
                else if (str[j]=='T')
                {
                    arr[i][j+1]=1;
                }
                else
                {
                    arr[i][j+1]=0;
                }
            }
        }

    

         cout << bu(1,1,1)<< endl;



 }
 int main()
 {
     int t ;
     scanf("%d",&t);
     while(t--)
     {
         solve();
     }

 }
