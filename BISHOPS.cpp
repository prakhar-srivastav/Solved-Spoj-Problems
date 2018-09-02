#include <iostream>
#include <stdio.h>
using namespace std ;

string sub( string x)
{
    string y="" ;
    int c=1;
 for( int i=x.size()-1;i>=0;i--)
 {
     int m =x[i]-48;
     if(c==1)
     {

             if(m==0)
            y=char(57) +y;
         else
         {
             y=char(m+47) +y;
             c=0;
         }
       }
         else
            y=x[i] +y ;
     }


     if(y[0]=='0')
     { string z="" ;
         for(int i=1;i<y.size();i++)
         {
             z=y[i]+z;
         }
         return z ;
     }
     return y ;


}

string mult(string x )
{
    string y="";
    int res=0;
    for(int i=x.size()-1;i>0;i--)
    {
        int a =x[i]-48;
        a=a*2+res;
        int r=a%10;
        y= char(r+48)+y;
        res=a/10;

    }
    int a=int(x[0])-48;
    a=a*2+res;
    if(a>=10)
    {
      y=   char(a%10 +48) +y;
      y= char(a/10+48) + y ;
    }
    else
    {
        y=  char(a +48) + y;
    }
    return y;

}
int main()
{
    string x ;


     while(cin >> x )
     {
         if(x=="0")
         cout << 0 << endl;
         else if(x=="1")
            cout << 1 << endl ;
            else
         {
             string y=mult(sub(x));
             cout << y<< endl;
         }

     }
}
