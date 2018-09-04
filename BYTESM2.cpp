#include <iostream>
using namespace std ;
int dp[200][200];
int arr[200][200];
int max1(int a, int b)
{
    return a>b ? a:b;
}
void slv()
{
    int c,r;
    cin >> r >> c ;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
        cin >> arr[i][j];

    for(int i=1;i<=c;i++)
    {
        dp[r][i]=arr[r][i];

    }
    for(int i=r-1;i>=1;i--)
    {

        for(int j=1;j<=c;j++)
        {

            int x,y,z ;
            x=j-1,y=j,z=j+1;
            dp[i][j]=dp[i+1][y];
            if(x>=1)
                dp[i][j]=max1(dp[i][j],dp[i+1][x]);
            if(z<=c)
                dp[i][j]=max1(dp[i][j],dp[i+1][z]);
                dp[i][j]+=arr[i][j];


        }
    }
    int max2=-999;
    for(int i=1 ;i<=c ;i++)
    {
        max2=max1(max2,dp[1][i]);
    }
        cout << max2 << endl;
}
int main()
{
    int t ;
    cin>> t ;
    while(t--)
        slv();

}
