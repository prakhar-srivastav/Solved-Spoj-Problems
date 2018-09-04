#include <iostream>
using namespace std ;

int arr[11];
int p=0;
int c=0;
 int main()
 {
     for(int i=1 ;i<=10;i++)
       {

           int n ;
           cin >> n ;
           c=c+n;
           if(c<=100)
           {
               p=c;
           }
           else
           {

               if(c-100 <=100-p)
               {
                   p=c;
               }
               else
               {
                   p=p;
               }
               break;
           }
       }
       cout << p << endl;
 }
