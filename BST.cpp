#include <iostream>
#include <map>
#include<stdio.h>
#define ll long long
const int mx=300001;
using namespace std;

ll l[mx+1],r[mx+1],d[mx+1];

int main() {
    map<int,int> m ;
    map<int,int> :: iterator it ;
    m[0]=0;
    m[mx]=mx;
    d[0]=d[mx]=-1;
    l[0]=l[mx]=r[0]=r[mx]=1;
    int n;
    scanf("%d",&n);
    ll c=0;
    while(n--)
    {

        int x ;
        scanf("%d",&x);
        m[x]=x ;
        it=m.find(x);
        it--;
        int value =it->first;
        if(r[value]==0)
        {
            r[value]=1;
            d[x]=d[value]+1;
        }
        else{
                it++;it++;
        value=it->first ;
            l[value]=1;
            d[x]=d[value]+ 1;
        }
        c+=d[x];
        printf("%lld\n",c);
    }


}
