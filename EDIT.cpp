#include <iostream>

#include <string>
using namespace std ;
string str;
int min(int a,int b)
{
    if(a>b) return b ;
    return a ;
}

int s(int i, int case1)
{
    if(i==str.size()) return 0;
    int val = int(str[i]);
    if(val>=97) val=0;
    else val=1;
    if(val==case1) return s(i+1,1-case1);
    else return 1 + s(i+1,1-case1);
}
int main()
{


    while(cin >> str)
    {
        cout << min(s(0,1),s(0,0)) << endl;
    }
}
