#include <iostream>
#include <math.h>
using namespace std ;
 int dp[100][100];
 int dp2[100][100];

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
     string x ;
     cin >>x ;
   int a1=0;
     for(int i=1; i<=r ;i++)
     {
       for(int j=1 ;j<=c;j++)
       {
           dp[i][j] = int(x[(a1)])- 48;

         a1++;
       }

     }

     int d=1;

     int res=0;
     string r1= "";
     int x1=4;
     for(int i=1 ;i<=r*c ; i++)
     {
         cord();

        res+= dp[a][b]* int(pow(2,x1--)) ;

        if(i%5==0)
        {x1=4;
        char ch= char(res+64);
      if(ch >='A' && ch<='Z')
            r1=r1+ch;
            else
                r1 =r1+" ";
             res=0;
        }


     }
     cout <<m1 << " " << r1 << endl;
 }
 int main()
 {
     int  t;
     int m=1;
     cin >> t;
     while(t--)
        solve(m++);
 }
