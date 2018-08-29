#include <iostream>
#include <utility>
#include <vector>
#include <stdio.h>

using namespace std ;
vector <pair <int, int> > v;
int dp[150][150][2];

 string sub(string x ,int l , int r)
 {
     string m="";
     if(l>r)
     {

         return m;
     }
     for(int i=l;i<=r;i++)
     {
         m=m+x[i];
     }
     return m ;
 }

void solve(string a , string  b )
{

 for(int i=0 ;i<=a.size();i++)
    {
        dp[i][0][0]=0;
        dp[i][0][1]=-1;
    }

 for(int i=0 ;i<=b.size();i++)
    {
        dp[0][i][0]=0;
        dp[0][i][1]=-1;
    }

    for(int i=1;i<=a.size();i++)
    {
        for(int j=1;j<=b.size();j++)
        {
            if(dp[i][j-1][0]<dp[i-1][j][0])
            {
             dp[i][j][0]=dp[i-1][j][0];
             dp[i][j][1]=0;
            }
            else
            {
                dp[i][j][0]=dp[i][j-1][0];
                dp[i][j][1]=1;
            }
            if(a[i-1]==b[j-1])
            {

                if(dp[i-1][j-1][0]+1 >dp[i][j][0])
                {
                    dp[i][j][0]=dp[i-1][j-1][0]+1;
                    dp[i][j][1]=2;
                }
            }
        }
    }
    int x=a.size();
    int y=b.size();
    string temp="";
    while(1)
    {
        int d=dp[x][y][1];
        if(d==-1) break;

        if(d==0) x--;
        else if(d==1) y--;
        else {
            v.push_back(make_pair(x-1,y-1));

            x--,y--;



        }

    }
   string ans="";
   int l1=0,l2=0;
   for(int i=v.size()-1;i>=0;i--)
   {
       int p =v[i].first;
       int q=v[i].second;
        ans=ans+ sub(a,l1,p-1) + sub(b,l2,q-1) + a[p];
        l1=p+1;
        l2=q+1;

   }
   ans=ans+sub(a,l1,a.size()-1)+sub(b,l2,b.size()-1);
   cout << ans << endl;
}
int main(void)
{
        char a[150],b[150];

        while(scanf("%130s",a) == 1)
           {
               scanf("%130s",b);
               string x=a;
               string y=b ;

               solve( x ,y);
               v.clear();
               x="";
               y="";


           }

        return 0;
}
