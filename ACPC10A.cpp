#include <iostream>
#define ll long long
using namespace std ;

 int a,b,c ;
void solve()
{
    if(c-b==b-a) cout << "AP " << c+c-b;
    else cout << "GP " << c*(b/a);

cout << endl;
}

int main()
{

    while(1)
    {
        cin >> a>>b>>c;
        if(a==0 && b==0 && c==0) break;
        solve();
    }
}
