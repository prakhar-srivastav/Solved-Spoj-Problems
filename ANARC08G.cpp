#include <iostream>
using namespace std ;
int arr[100001];
int sum ;
 int main()
 {
     int t ;
     int counter =1;
    while(1)
     {
         sum=0;
         cin >> t ;
          if(t==0) break;
          int n=t;
          for(int i=1;i<=n;i++) arr[i]=0;
          for(int i=1;i<=n;i++)
          {
              for(int j=1;j<=n;j++)
              {
                   int x ;
               cin >> x;
               sum+=x ;
               arr[i]-=x;
               arr[j]+=x;
              }

          }
          int s2=0;
          for(int i=1;i<=n;i++)
          {
              if(arr[i]>=0) s2+=arr[i];
          }
          cout << counter++ << ". " << sum << " " << s2 << endl;
     }


 }
