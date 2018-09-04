#include <string>
#include <iostream>
#define ll long long
using namespace std ;


string add(string a,string b)
{
    string a1,b1;
	if(a.size()>b.size())
    {
        a1=a;
        b1=b;
    }
    else
    {
        a1=b;
        b1=a;

    }
  int len=a1.size()-b1.size();
 for(int i=0;i<len;i++) b1="0"+b1;

	int car=0;
	string c="";

	for(int i=a1.size()-1;i>=0;i--)
    {
        int m,n;
        m=int(a1[i])-48,n=int(b1[i])-48;
        int z=m+n+car;
        z=z%10;

        c=char(48+z)+c;

        car=(m+n+car>=10)?1:0;
    }
    if (car==1) c="1"+c;
     return c;
}
string mult1(string a ,int b)
{
    int n=b;
    string c="";
    int z=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        int m=int(a[i])-48;
      int x=m*n+z;
      int y=x%10;
      c=char(y+48)+c;
      z=x/10;
     }
     if(z!=0) c=char(z+48)+c;
     return c ;
}
string mult(string a , int b)
{
    int temp =b;
    int c=0;
    string str ="0";
    string w="";
    while(temp!=0)
    {
        w=mult1(a,temp%10);
        for(int i=0;i<c;i++) w+="0";
        str=add(str,w);

        c++;
        temp/=10;
    }
    return str;
}
void solve()
{
    int a;
    cin >> a;
    string f="1";
    for(int i=1;i<=a;i++)
    {

        f=mult(f,i);
    }
    if(a!=0) cout << f << endl;
    else cout << "1" << endl;
}
int main()
{
	int tt ;
	cin >> tt;
	while(tt--) solve();
}
