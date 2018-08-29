#include <iostream>
using namespace std ;
int counter;
const int max1=1025 ;
int arr[max1];
int dp[max1][max1];
int m1[max1];
int mod =100000007;
void solve()
{
  int n , m ;
  cin >> n >> m ;
  for(int i=1 ; i<= n;i++)
  {
      cin >> m1[i];
  }
  for(int i=1 ;i<=m;i++)
  {
      int x ;
      cin >> x;
      arr[x]=1 ;
  }
  dp[0][0]=1 ;
  for(int i=1;i<=n;i++)
  {
      for(int j=0;j<max1 ;j++)
      {
          dp[i][j]=(dp[i-1][j]+ dp[i-1][j^m1[i]])% mod;
      }

  }
  int b=0;
  for(int i=0 ;i<max1;i++)
  {
      if(arr[i]) b=(b+dp[n][i])%mod;
  }
  int all=1 ;
  for(int i=1;i<=n;i++)
  {
      all= (all<<1 )% mod ;
  }
  cout << "Case " << counter << ": " << (all-b+mod)%mod << endl;

}
int main()
{
int t;
cin >>t ;
while (t--)
   {
       for(int i=0;i<max1;i++) arr[i]=0;

       counter++;
        solve();
   }
}
