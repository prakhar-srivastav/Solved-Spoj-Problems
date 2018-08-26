#include <iostream>
using namespace std ;
int arr[2000];
int dp[2000][3];
int min2(int a, int b)
{
    return a>b?b:a;
}
void solve()
{
    int n,k;
    cin >> n >> k;
    for (int i=1 ; i<=k;i++) cin >> arr[i];
    for(int i=0;i<=k;i++)
    {
       dp[i][1]=999999;
       dp[i][2]=0;
    }
    dp[0][1]=0;
    dp[0][2]=0;

    for(int i=1;i<=k;i++)
    {
       if(arr[i]!=-1)
        for(int j=i;j<=k;j++)
       {
           int x=dp[j][1];
           int y=dp[j][2];



               if(dp[j-i][1]+arr[i] < dp[j][1])
               {
                   dp[j][1]=dp[j-i][1]+arr[i];
                   dp[j][2]=dp[j-i][2]+1;

               }
               if(dp[j][2]==n&& j!=k)
               {
                   dp[j][1]=x;
                   dp[j][2]=y;
               }
           }




       }

    if(dp[k][1]!=999999)
    cout << dp[k][1] << endl;
    else
        cout << -1 << endl;

}
 int main()
 {
     int t;
     cin >> t ;
     while(t--)
        solve();
 }
