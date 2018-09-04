#include <iostream>
#include <utility>
#include <queue>
using namespace std ;
int f,s,g,u,d;
int arr[10000001];


void solve()
{
    cin >> f >> s >> g >> u >> d;
    for(int i=1;i<=f;i++)
    arr[i]=0;
    queue < pair<int,int> > pq ;
    pq.push(make_pair(s,0));
    while(!pq.empty())
    {
        pair<int,int> p=pq.front();
        pq.pop();
        if(p.first==g)
        {
            cout << p.second << endl;
            return ;
        }
        if(arr[p.first]==1)
            continue ;
        arr[p.first]=1;
        int x=p.first ;
        int u1=u+x;

        if(arr[u1]==0 && 1 <= u1 && u1 <=f )
        {
         pq.push(make_pair(u1,p.second+1));
        }
        u1=x-d;
        if(arr[u1]==0 && 1 <= u1 && u1 <=f )
        {
         pq.push(make_pair(u1,p.second+1));
        }
    }
    cout << "use the stairs" ;


}
int main()
{
    solve();
}
