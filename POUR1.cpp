
#include <iostream>
using namespace std;

int a,b,c;
int max(int a,int b)
{
    int x=(a>b)?a:b;
    return x;
}
int gcd(int a,int b)
{


    for(int i=b;i>=1;i--){
      if(b%i==0 && a%i==0)
            return i;
    }
}
int com()
{

    int a1=0,b1=0;
        int c1=0;
        while(1)
        {

                        if(a1==0)
            {
                a1=a;
            }
            else if(b1==b)
            {
                b1=0;
            }
            else
            {
                if(b-b1<=a1) a1=a1-b+b1,b1=b;
                else b1=b1+a1,a1=0;
            }
            c1++;
            if(a1==c || b1==c) break;
}

return c1;
}
void solve()
{


    cin >> a >> b >> c;

    if(c%gcd(a,b)==0 && max(a,b)>=c)
    {
        int x1,x2;
        x1=com();
        a=a+b,b=a-b,a=a-b;
        x2=com();
        x2=(x1>x2)?x2:x1;
        cout << x2 << endl;

        }

        else
            cout << "-1" << endl;


    }

int main()
{

    int t;

    cin >> t;
    while(t--) solve();
}
