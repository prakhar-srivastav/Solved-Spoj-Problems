#include <iostream>
#define ll long long
using namespace std ;

ll dp[65][65];
 ll N,K;
 ll end1 ;
ll solve(ll pos , ll k)
{
    if(k==0 && pos==end1) return 1;
    if(k<=0) return 0;
    if(dp[pos][k]!=-1) return dp[pos][k];

    ll a,b;
    a=pos+1;
    b=pos-1;

    if(a==N+1) a=1 ;
    if(b==0) b=N;

    dp[pos][k]=solve(a,k-1) + solve(b,k-1) ;
    return dp[pos][k];
}


int main()
{


    while(1)
    {

        cin >> N >> K;
        if(N==-1 && K==-1 ) break ;

  ll a,b;
        cin >> a >> b ;

        for(int i=1;i<=N;i++)
            for(int j=1;j<=K;j++)
                dp[i][j]=-1;
              end1=b;
        cout << solve(a,K) << endl;

    }
}
