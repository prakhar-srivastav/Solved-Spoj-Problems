#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <utility>

#define ll long long
using namespace std ;

ll n,m,k,s,t ;

ll d1[10002];
ll d2[10002];



ll max1=0x3f3f3f3f;
vector < vector<pair <ll ,ll > > > dx1 ;
vector < vector<pair <ll ,ll > > > dx2 ;

void djk1 ( ll x1 ,ll y , ll dis[],vector <vector<pair <ll ,ll > > > graph)
{

    for( ll i=1 ;i<= n; i++)
    {

        dis[i]=max1;
    }
    priority_queue < pair <ll ,ll> ,vector < pair < ll , ll > > , greater <pair <ll , ll > > > pq ;
    pq.push(make_pair(0,x1));
    dis[x1]=0;
    while(!pq.empty())
    {
     ll x = pq.top().second ;
     pq.pop();

     for( ll i=0 ;i<graph[x].size() ;i++)
     {

         ll y =graph[x][i].first;
         ll d= graph[x][i].second;


         if(d+dis[x] <dis[y])
         {
             dis[y]=d+dis[x];
             pq.push(make_pair (dis[y],y));

         }



         }

     }
    }

    ll min1(ll x , ll y)
    {
        return x<y ? x:y;
    }
void solve()
{

    dx1 = vector< vector<pair <ll ,ll > > > (n+1,vector<pair <ll , ll > >());
    dx2 = vector< vector<pair <ll ,ll > > > (n+1,vector<pair <ll , ll > >());

    for( ll i=1 ;i<=m;i++)
    {

        ll a,b,c ;
        scanf("%lld%lld%lld",&a,&b,&c);


        dx1[a].push_back(make_pair(b,c));
        dx2[b].push_back(make_pair(a,c));
    }
     djk1(s,t,d1,dx1);

    djk1(t,s,d2,dx2);
    ll min2=d1[t];
    for( ll i=1 ;i<=k ;i++)
    {
    ll a,b,c ;
        scanf("%lld%lld%lld",&a,&b,&c);


         min2= min1(d1[a]+c+d2[b],min2);
         min2=min1(d1[b]+c+d2[a],min2);


    }

    if(d1[t]>=max1) printf("-1\n");
    else printf("%lld\n",min2);


}


 int main()
 {
     int t1 ;
     scanf("%d",&t1);

     while(t1--)
     {


         scanf("%lld%lld%lld%lld%lld",&n,&m,&k,&s,&t);

         solve();

     }

 }
