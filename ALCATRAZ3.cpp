#include <string>
#include <iostream>
#include <utility>
#include <stack>
#include <stdio.h>

using namespace std ;
int r,c;
 int main()
 {
     scanf("%d%d",&r,&c);
     int k;
     scanf("%d",&k);
     int a,b;
     scanf("%d%d",&a,&b);
     int arr[r+2][c+2];
     for(int i=0;i<=r+1;i++)
     {
         arr[i][0]=0;
         arr[i][c+1]=0;
     }

     for(int i=0;i<=c+1;i++)
     {
         arr[0][i]=0;
         arr[r+1][i]=0;
     }
     char ch;
     for(int i=1;i<=r;i++)
        {

            for(int j=1;j<=c;j++)
     {
         cin >> ch;
         if(ch=='.')
            arr[i][j]=1;
         else
            arr[i][j]=0;
     }

        }
     int vis[r+1][c+1];
     for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
        vis[i][j]=0;



     stack <pair <int,pair<int,int> > > s;

     if(arr[a-1][b]==1) s.push(make_pair(1,make_pair(a-1,b)));
     if(arr[a+1][b]==1) s.push(make_pair(1,make_pair(a+1,b)));
     if(arr[a][b-1]==1) s.push(make_pair(1,make_pair(a,b-1)));
     if(arr[a][b+1]==1) s.push(make_pair(1,make_pair(a,b+1)));
     while(!s.empty())
     {
         int x,y,z;
         x=s.top().first;
         y=s.top().second.first;
         z=s.top().second.second;
         if(y==a&& z==b )
         {
             if(x>=k)
             {
                 printf("YES");
                 break;
             }
             else
             {
                 s.pop();
                 continue;
             }
         }

         if(vis[y][z]==1)
         {
             vis[y][z]=0;
             s.pop();
             continue;
         }
         if(x==1)
         {
             int s1,s2;
             s1=y-1;
             s2=z;
             if(arr[s1][s2]==1 && vis[s1][s2]==0 && s1!=a && s2!=b)
                s.push(make_pair(x+1,make_pair(s1,s2)));

             s1=y;
             s2=z-1;
             if(arr[s1][s2]==1 && vis[s1][s2]==0 && s1!=a && s2!=b)
                s.push(make_pair(x+1,make_pair(s1,s2)));

             s1=y+1;
             s2=z;
             if(arr[s1][s2]==1 && vis[s1][s2]==0 && s1!=a && s2!=b)
                s.push(make_pair(x+1,make_pair(s1,s2)));

             s1=y;
             s2=z+1;
             if(arr[s1][s2]==1 && vis[s1][s2]==0 && s1!=a && s2!=b)
                s.push(make_pair(x+1,make_pair(s1,s2)));

         }
         else
         {
             int s1,s2;
             s1=y-1;
             s2=z;
             if(arr[s1][s2]==1 && vis[s1][s2]==0)
                s.push(make_pair(x+1,make_pair(s1,s2)));

             s1=y;
             s2=z-1;
             if(arr[s1][s2]==1 && vis[s1][s2]==0)
                s.push(make_pair(x+1,make_pair(s1,s2)));

             s1=y+1;
             s2=z;
             if(arr[s1][s2]==1 && vis[s1][s2]==0)
                s.push(make_pair(x+1,make_pair(s1,s2)));

             s1=y;
             s2=z+1;
             if(arr[s1][s2]==1 && vis[s1][s2]==0)
                s.push(make_pair(x+1,make_pair(s1,s2)));
         }
         vis[y][z]=1;
     }
     if(s.empty()) printf("NO");


 }
