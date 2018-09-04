#include <iostream>
using namespace std ;
 int arr[2000];
 int dp[2000];
 int dis [2000];
 int dis2 [2000];
 int max2(int a,int b)
 {
     return a>b?a:b;
 }

 int find1(int val,int x, int dp[])
 {
     int l=1;
     int u=x;
     int flag=0;
     int m;
     while(l<u)
     {

         m=l+u;
         m=m/2;
         if(arr[dp[m]] <val)
        {
            l=m+1;
         }
         else if(arr[dp[m]]>val)
         {
             u=m;
         }
         else
         {
             flag=1;
             break;
         }
     }
     if(flag==1) return m ;
     else return l;
  }
 int main()
 {

     int t;
     cin >> t;
     while(t--)
     {
         int  n;
         cin >> n ;
         for(int i=1;i<=n;i++) cin >> arr[i];
         dp[1]=1;
         int x=1;
         dis[1]=1;

         for(int i=2;i<=n;i++)
         {
             int m;
             if(arr[i]>arr[dp[x]])
             {
                 dp[++x]=i;
                 m=x;
             }
             else if(arr[i]<arr[dp[1]])
             {
                 dp[1]=i;
                 m=1;


             }
             else
             {
                 int r=find1(arr[i],x,dp);
                 m=dis[dp[r]];
                 if(arr[i]!=arr[dp[r]])
                 dp[r]=i;
             }
             dis[i]=m;
         }

             for(int i=1;i<=n/2;i++)
             {
                 int tem1;
                 tem1=arr[n-i+1];
                 arr[n-i+1]=arr[i];
                 arr[i]=tem1;
                 tem1=dis[n-i+1];
                 dis[n-i+1]=dis[i];
                 dis[i]=tem1;



             }
             x=1;
             dp[1]=1;
              int max1=dis[1];
              dis2[1]=1;
             for(int i=2;i<=n;i++)
             {
                 int n1;

             if(arr[i]>arr[dp[x]])
             {
                 dp[++x]=i;
                 n1=x;
                 dis2[i]=x;

             }
             else if(arr[i]<arr[dp[1]])
             {
                 dp[1]=i;
                 n1=1;
                 dis2[i]=1;

             }
             else
             {
                 int r=find1(arr[i],x,dp);
                 n1=dis2[dp[r]];
                 dis2[i]=n1;
                if(arr[i]!=arr[dp[r]])
                 dp[r]=i;
             }


             max1 =max2(max1,n1-1+dis[i]);

             }

             cout << max1<<endl;
         }
     }
