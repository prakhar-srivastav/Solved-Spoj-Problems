#include <iostream>
#include <string>
using namespace std ;
string a1,b1;
int dp[2001][2001];
int min(int a,int b,int c)
{
    if(a<b)
        b=a;
    if(b<c)
        c=b;
    return c ;
}
int solve(int a , int b )
{
    if(a<0 || b<0) {
        if(a<0) return b+1;
        else return a+1;
    }
    if(dp[a][b]!=-1) return dp[a][b];
 if(a1[a]==b1[b])
 {
    dp[a][b]=solve(a-1,b-1);
    return dp[a][b];
 }
 else
 {
     dp[a][b]=min(solve(a-1,b)+1,solve(a,b-1)+1,solve(a-1,b-1)+1);
     return dp[a][b];

 }

}

int main()
{

    int x ;
    cin >> x ;
    while(x--)
    {
        cin >> a1 >> b1 ;
        for(int i=0;i<a1.size();i++)
            for(int j=0;j<b1.size();j++) dp[i][j]=-1;

        cout << solve(a1.size()-1,b1.size()-1) << endl;

    }
}
