#include <vector>
#include <iostream>
#include <stdio.h>
#include <utility>
#include <stack>
using namespace std;

char temp[1002];
 char arr[1002][1002];
 int val[1002][1002];
 int m,n;

 int compute()
 {
     stack < pair<int,pair<int,int> > > s;
     s.push(make_pair(m,make_pair(n,0)));
     int max=0;
     while(!s.empty())
     {
         int a=s.top().first,b=s.top().second.first;

         if(val[a][b]==0 && arr[a][b] !='#')
        {
            int x=s.top().second.second;
           val[a][b]++;
           if(x>max)
           {
               m=a,n=b;
               max=x;
           }

        s.push(make_pair(a-1,make_pair(b,x+1)));
        s.push(make_pair(a+1,make_pair(b,x+1)));
        s.push(make_pair(a,make_pair(b-1,x+1)));
        s.push(make_pair(a,make_pair(b+1,x+1)));
        }
        else{
            s.pop();
        }
     }


     return max;

 }

void solve()
{

vector <pair<int,int> > v;
    int c,r;
    scanf("%d%d",&c,&r);


   for(int i=0;i<=c+1;i++)
   {
       arr[0][i]='#';
   }

   for(int i=0;i<=r+1;i++)
   {
      arr[i][c+1]='#' ;
   }

   for(int i=0;i<=c+1;i++)
   {
       arr[r+1][i]='#';
   }

   for(int i=0;i<=r+1;i++)
   {
       arr[i][0]='#';
   }

    for(int i=1;i<=r;i++)
        {
            scanf("%s",temp);
            for(int j=1;j<=c;j++)
        {


            arr[i][j]=temp[j-1];
            if(temp[j-1]=='.') v.push_back(make_pair(i,j));
        }
        }


        int max=0;

         for(int j=0;j<v.size();j++)
        val[v[j].first][v[j].second]=0;



        for(int i=0;i<v.size();i++)
        {

            int a=v[i].first,b=v[i].second;
                int x=0;
                if(arr[a-1][b]=='.') x++;
                if(arr[a][b-1]=='.') x++;
                if(arr[a+1][b]=='.') x++;
                if(arr[a][b+1]=='.') x++;

                if(x==1)
                {m=a,n=b;
              max=compute();
                    break;
                }

            }


            for(int j=0;j<v.size();j++)
        val[v[j].first][v[j].second]=0;




        printf("Maximum rope length is %d.\n",compute());


}

int main()
{


        int tt;
        scanf("%d",&tt);
        while(tt--)solve();

}
