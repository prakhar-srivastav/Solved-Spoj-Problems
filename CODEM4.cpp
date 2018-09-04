#include <iostream>
using namespace std ;
int arr[100];
int dp[100][100];
int sum[100];
int max1(int a ,int b)
{
    return a>b ?a:b;
}
int dumb(int l,int r, int a)
{
    if(l==r) return arr[l];

    int x =  arr[l]-dumb(l+1,r,1-a)+sum[r]-sum[l];
    int y =  arr[r]-dumb(l,r-1,1-a)+sum[r-1]-sum[l-1];

    int z=x>y?x:y;
    if(a==0) z=x+y-z;

    return z ;

}
int smart(int l,int r)
{
    if(l==r) return arr[l];
    if(dp[l][r]!=-1) return dp[l][r];
    int x =  arr[l]-smart(l+1,r)+sum[r]-sum[l];
    int y =  arr[r]-smart(l,r-1)+sum[r-1]-sum[l-1];

    int z=x>y?x:y;
    dp[l][r]=z;
    return z ;

}

void solve()
{
    int n ;
    cin >> n;

    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) dp[i][j]=-1;

    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin >>arr[i];
        sum[i]=sum[i-1]+arr[i];
    }


        cout <<dumb(1,n,1)<<" "<< smart(1,n) << endl;

}
 int main()
 {
     int t ;
     cin >> t;
     while(t--) solve();
 }

