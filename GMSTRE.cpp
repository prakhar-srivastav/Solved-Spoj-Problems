#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

int n ;
struct arr
{
    int a,b,c,d ;

};


struct arr a1[101];
bool comp(struct arr a,struct arr b)
{
    if(a.a <b.a)
    {
        return true;
    }
    else if(a.a==b.a)
    {
        if(a.b>b.b)
            return true ;
        else if(a.b==b.b)
        {
            if(a.c<b.c)
                return true;
            else
                return false ;
        }
        else
            return false ;

    }
    else
        return false ;


}
int main ()
{

    cin >> n ;
    for(int i=1;i<=n;i++)
    {

        int a,b,c ;
        cin >> a >> b >> c ;
        a1[i].a=a;
        a1[i].b=b;
        a1[i].c=c;
        a1[i].d=i;
    }int x1 =n;
    sort(a1+1,a1+n+1,comp);

    if(a1[n].d==a1[1].d)
    {
       cout << "Easiest and Hardest is level " << a1[n].d ;
    }
    else
    {
        cout << "Easiest is level "<< a1[n].d << endl;
        cout << "Hardest is level "<< a1[1].d << endl;
    }
}
