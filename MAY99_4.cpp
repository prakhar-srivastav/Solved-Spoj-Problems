#include <iostream>
using namespace std ;
int dp[1000][1000];
int mod =10000007;
 int muffins(int n , int r)
 {
     if(n==0 || r==1)
        {
        return 1;
        }
        if(dp[n][r]!=-1) return dp[n][r];
        int x=0;
        for(int i=0;i<=n;i++)
        {
         dp[n-i][r-1]= muffins(n-i,r-1)%mod;
         x+=dp[n-i][r-1];
         x=x%mod;
        }
        dp[n][r]=x;

        return x;

 }
 int main()
 {

     int n,r ;
     cin >> n >> r ;
     for(int i=1;i<=n;i++)
        for(int j=1;j<=r;j++) dp[i][j]=-1;
     if(n<r) cout << -1 << endl;
     else
     {



       cout << muffins(n-r,r)%mod << endl;
  }
 }
