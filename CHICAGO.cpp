#include <iostream>
#include <map>
#define INF 0.0
#include <vector>
#include <utility>
#include <stdio.h>
#include <queue>
#include <string>
#define ll long long

using namespace std;
double graph[1001][1001];
vector <pair < ll,double> > arr[1001];
bool val[1001];
double dis[1001];
int main()
{

    ll a ,b ;
    while(1)

    {
     scanf("%lld",&a);
     if(a==0) break ;
     scanf("%lld",&b);
     for(ll i=1;i<=a;i++)
        for(ll j=1;j<=a;j++)
     {
         graph[i][j]=-1;
     }
      for(ll i=1 ;i<=b;i++)
     {
         ll p,q;
         double r;

         scanf("%lld%lld%lf",&p,&q,&r);
         r=r/100;
         graph[p][q]=r;
         graph[q][p]=r;
         arr[p].push_back(make_pair(q,(r)));
         arr[q].push_back(make_pair(p,(r)));

     }

     for(ll i=1;i<=a;i++)
     {
         dis[i]=INF;
        val[i]=false;
     }
        dis[1]=1;
        priority_queue < pair<double,ll > ,vector < pair < double,ll > >  > pq ;
        pq.push(make_pair(1,1));


        while(1)
        {
            ll n= pq.top().second;
            pq.pop();
            if(n==a)
            {

                break;
            }

            if(val[n])
                continue;

             val[n]=1;

            for(ll i=0;i<arr[n].size();i++)
            {
                if(val[arr[n][i].first]) continue ;
               double  x=dis[arr[n][i].first];
                double y=dis[n];
                double z=arr[n][i].second;
                if(x<y*z)
                {
                    x=y*z;
                    dis[arr[n][i].first]=x;;

                pq.push(make_pair(x,arr[n][i].first));
                }
            }

        }




printf("%0.6lf percent\n",dis[a]*100);
for(int i=1;i<=a;i++) arr[i].clear();
    }

}
