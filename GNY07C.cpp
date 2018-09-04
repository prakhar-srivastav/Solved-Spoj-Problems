#include <iostream>
#include <math.h>
using namespace std ;
 int dp[100][100];
 int dp2[100][100];
 int arr[3000];
 int a,b;
 int dis=1;
 void cord()
 {
     if(dis==1)
     {
         if(dp2[a][b+1]==0)
         {

          dp2[a][b]=1;
          b++;
         }
         else
         {
             dis=2;
             dp2[a][b]=1;
             a++;
         }
     }
     else if(dis==2 )
     {
         if(dp2[a+1][b]==0)
         {

          dp2[a][b]=1;
          a++;
         }
         else
         {
             dis=3;
             dp2[a][b]=1;
             b--;
         }
     }
     else if(dis==3)
     {
      if(dp2[a][b-1]==0)
         {

          dp2[a][b]=1;
           b--;
         }
         else
         {
             dis=4;
             dp2[a][b]=1;
             a--;
         }
     }
     else
     {
         if(dp2[a-1][b]==0)
         {

          dp2[a][b]=1;
          a--;
         }
         else
         {
             dis=1;
             dp2[a][b]=1;
             b++;
         }
     }
 }
 void solve( int m1)
 {
     dis=1;
     a=1,b=0;
     int r,c;
     cin >> r >> c;
     for(int i=1 ;i<=r;i++)
        for(int j=1;j<=c;j++)
        dp2[i][j]=0;
     for(int i=0 ;i<=c+1;i++)
     {
         dp2[0][i]=1,dp2[r+1][i]=1;
     }

     for(int i=0 ;i<=r+1;i++)
     {
         dp2[i][0]=1,dp2[i][c+1]=1;
     }
     dp2[0][0]=0;
     string str1 ;
     getline ( cin , str1 );
		string x ( str1.begin() + 1 , str1.end() );
     int co=1;
     for(int i=0;i<x.size();i++)
     {
         int val = int(x[i]) -64;
         if(!(1<=val<=26)) val=0;
         for(int j=5 ;j>=1;j--)
         {
             arr[co++]= 1 & (val>> (j-1));
         }


     }
      for(int i=co;i<=r*c;i++)
      {
          arr[i]=0;
      }



     for(int i=1 ;i<=r*c ; i++)
     {
         cord();

        dp[a][b]=arr[i];




     }
     cout <<m1 << " ";
     for(int i=1 ;i<=r;i++)
        for(int j=1 ;j<=c;j++)
        cout << dp[i][j];
     cout << endl;
 }
 int main()
 {
     int  t;
     int m=1;
     cin >> t;
     while(t--)
        solve(m++);
 }
