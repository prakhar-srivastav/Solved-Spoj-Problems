#include <iostream>
#include <vector>
#include <map>

using namespace std ;
int n ;
map <int,int > m1 ;
vector <int > v;
int main()
{
    cin >> n ;
    for(int i=1 ;i<=n;i++)
    {
        int x ;
        cin >> x ;
        m1[x]=1;
        int m ;
        cin >> m;
        for(int i=1;i<=m;i++)
        {
            cin >> x;
            v.push_back(x);
        }
    }
    int c=0;
    for(int i=0;i<v.size();i++)
    {
        if(m1[v[i]]==0) {
            c++;
            m1[v[i]]=1;
        }
    }
    cout << c << endl;
}
