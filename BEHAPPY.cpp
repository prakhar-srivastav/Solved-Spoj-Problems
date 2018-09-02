#include <iostream>
using namespace std ;

 int arr[200];
 int dp1[200][200];
 int x,y ;
 int dp(int pos ,int sum)
 {
     if(sum<0 ) return 0;
     if(pos == x  )
     {
         if(sum<= arr[pos]) return 1 ;
         return 0;
     }
     int s=0;
     for(int i=0;i<=arr[pos];i++)
     {
         s=s+dp(pos+1,sum-i);


     }
     return s;
 }
 int main()
 {


     while(1)
     {

         cin >> x >> y ;
         if(x==0 && y==0) break ;
         for(int i=1;i<=x;i++)
         {
             int a,b ;
             cin >> a >> b ;
             y=y-a ;
             arr[i]=b -a;
         }
         for(int i=1 ;i<=x;i++)
            for(int j=1 ;j<=y ;j++)
            dp1[i][j]=-1;
         cout << dp(1,y)  << endl;
     }

 }
