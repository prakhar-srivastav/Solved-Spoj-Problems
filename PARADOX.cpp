#include <iostream>
using namespace std ;

int n ;
int arr[101][5];

void renew()
{
     for(int i=1 ;i<=n ;i++)
     {

     arr[i][4]=0;
     }
}

 void solve()
 {
     int x ; string y="";


     for(int i=1 ;i<=n ;i++)
     {
          cin >> x;
     cin >> y ;
     arr[i][1]=i ;

     if(y == "false") arr[i][3]=1;
     else arr[i][3]=2;
         arr[i][2]=x ;
         arr[i][4]=0 ;

     }

    int flag =0 ;

     for (int i=1 ; i<=n;i++)
     {

         renew();
        int a= i;
         while(1)
         {
             int b =arr[a][2];
         if(arr[b][4]==0)
         {
             if(arr[a][4]==2)
             {
                 arr[b][4]=arr[a][3];


             }
             else if (arr[a][4]==1)
             {
                  arr[b][4]=3-arr[a][3];
             }
             else {
                arr[b][4]= arr[a][3];
             }
         }
         else
         {
            int x ;
              if(arr[a][4]==2)
             {
                 x=arr[a][3];


             }
             else if (arr[a][4]==1)
             {
                  x=3-arr[a][3];
             }
             else {
                x= arr[a][3];
             }

             if(x!= arr[b][4])
                flag=1 ;
             break;
         }
        a=b;
         }
       if(flag==1 ) break;

     }
     if(flag ==0 ) cout << "NOT PARADOX\n" ;
     else cout << "PARADOX\n";


 }
 int main()
 {

      while (1)
      {

          cin >>n ;
          if(n==0) break ;
          solve();
      }
 }
