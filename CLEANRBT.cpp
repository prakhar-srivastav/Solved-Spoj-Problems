#include <iostream>
#include <vector>
#include <utility>
#include <queue>



using namespace std ;
int dp1[1<<11][11];
int dp[50][50];
int vis[50][50];
char arr[50][50];
pair<int,int > start ;
vector <pair <int,int > > v ;
vector <pair < int ,int > > g[500];
int r,c,n,base_case;
int bfs(int x, int y)
{
    int counter =0;

    for(int i=0;i<=r+1;i++)
        for(int j=0;j<=c+1;j++)
    {
        dp[i][j]=0;
        vis[i][j]=0;
    }
    queue <pair <int,pair<int,int> > > q ;
    q.push(make_pair(x,make_pair(y,0)));

    while(!q.empty())
    {

        int a=q.front().first;
        int b =q.front().second.first ;
        int c =q.front().second.second;


         dp[a][b]=c;
        q.pop();
        if(vis[a][b]==1) continue ;
        else {
            vis[a][b]=1;
        }
        if(arr[a][b]=='*') counter++;




        if(vis[a+1][b]==0 && arr[a+1][b]!='x') q.push(make_pair(a+1,make_pair(b,c+1)));
        if(vis[a-1][b]==0 && arr[a-1][b]!='x') q.push(make_pair(a-1,make_pair(b,c+1)));
        if(vis[a][b-1]==0 && arr[a][b-1]!='x') q.push(make_pair(a,make_pair(b-1,c+1)));
        if(vis[a][b+1]==0 && arr[a][b+1]!='x') q.push(make_pair(a,make_pair(b+1,c+1)));


    }

    if(counter !=v.size()) return 0 ;
    return 1 ;


}
int min2(int a,int b)
{
    return a<b?a:b;
}
bool check(int mask,int i)
{
    int y =( 1<< i) &mask ;
    if(y==0) return false ;
    return true;
}
int make(int mask ,int i )
{
    return (1<<i) + mask;

}
int dp_1(int mask,int pos)
{

    if(mask==base_case) return 0;
    if(dp1[mask][pos]!=-1)
        return dp1[mask][pos];
    int min1=9999999;
    for(int i=0;i<g[pos].size();i++)
    {
        int x=g[pos][i].first;
        int y=g[pos][i].second ;
        if(check(mask,x-1)) continue ;
        int m=make(mask,x-1);
        min1=min2(y+dp_1(m,x),min1);
    }
    dp1[mask][pos]=min1;
    return min1;
}
void solve()
{


    for(int i=1;i<=r;i++)
    {

        for(int j=1;j<=c;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j]=='o')
            {
                start.first=i,start.second=j;
            }
            else if(arr[i][j]=='*')
                v.push_back(make_pair(i,j));
        }
    }
    for(int i=0;i<=c+1;i++)
        arr[0][i]='x',arr[r+1][i]='x';

    for(int i=0;i<=r+1;i++)
        arr[i][0]='x',arr[i][c+1]='x';



        int val=bfs(start.first,start.second);
          if(val)
          {


        for(int i=0 ; i<v.size();i++){
            g[0].push_back(make_pair(i+1,dp[v[i].first][v[i].second]));
        }
        for(int i=0 ;i<v.size();i++)
        {
           int garbage= bfs(v[i].first,v[i].second);
            for(int j=0;j<v.size();j++)
                if(j!=i)
           g[i+1].push_back(make_pair(j+1,dp[v[j].first][v[j].second]));
        }

        n=v.size();

        base_case= (1<<(n)) -1;


        for(int i=0;i<=(1<<n);i++)
        {
            for(int j=0 ;j<=n;j++)
                dp1[i][j]=-1;
        }

                      cout << dp_1(0,0)  << endl;

          }

     else cout << -1 <<endl ;

}

int main()
{
    while(1)
    {
        cin >> c >> r ;
        if(c==0 && r==0) break;
        solve();
        v.clear();
        for(int i=0;i<=n;i++) g[i].clear();

    }
}
