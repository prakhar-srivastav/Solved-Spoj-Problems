#include <stdio.h>
#include <iostream>
#define ll long long
#include <vector>
using namespace std ;
int arr[1000000];
int a[101];
vector <int > v;
int main()
{
    int t ;
     scanf("%d",&t);
     while(t--)
     {
         int n ,s=0;
         scanf("%d",&n);
         for(int i=1;i<=n;i++)
         {
          scanf("%d",&a[i]);
          s+=a[i];
         }
         for(int i=1;i<=s;i++) arr[i]=0;
         arr[a[1]]=1;
         int ans=a[1];
         v.push_back(a[1]);
         int count =1;


         for(int i=2;i<=n;i++)
         {
             int x=0;
             if(arr[a[i]]==0)
             {

                 count++;
                 arr[a[i]]=1;
                 ans+=a[i];

                 v.push_back(a[i]);
                 x--;
             }
                 x +=v.size();
                 for(int j=0;j<x;j++)
                 {
                     int temp=a[i]+v[j];
                     if(arr[temp]==0)
                     {
                         ans+=temp;
                         arr[temp]=1;
                         count++;
                         v.push_back(temp);
                     }
                 }
             }


         printf("%d\n",ans);
         v.clear();
     }

}
