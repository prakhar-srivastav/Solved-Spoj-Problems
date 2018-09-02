#include <iostream>
using namespace std ;
int arr[5000];
int arr1[5000];
int dp[5000];

int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        string x ;
        cin  >>  x ;
        string temp="";
        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='K'|| x[i]=='E') temp=temp+x[i];

        }
        string temp2="";
        int f=0;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]=='E' && f==0)
                continue;
            else
            {
                f=1;
                temp2=temp2+temp[i];
            }
        }
        string temp3="";f=0;
        for(int i=temp2.size()-1;i>=0;i--)
        {
            if(temp2[i]=='E' && f==0)
                continue ;
            else
            {
                f=1;
                temp3= temp2[i]+ temp3;
            }
        }
        int x1=1;
        char ch2='K';
        int m1=0;
        for(int i=1;i<=temp3.size();i++)
        {
             char ch=temp3[i-1];
            if(i==temp3.size())
            {
                if(ch==ch2) arr[x1]=m1+1;
                else {
                        arr[x1++]=m1;
                    arr[x1]=1;
                }

                break;
            }

            if(ch==ch2)
            {
                m1++;
            }
            else
            {
                arr[x1++]=m1;
                if(ch=='K') ch2='K';
                else ch2='E';
                m1=1;
            }
        }

     int sum=0;
     int fin=0;
     int s1= arr[1];
     for(int i=3 ;i<=x1;i=i+2)
     {


         sum= (sum*arr[i])/arr[i-2];
         sum= sum+s1*arr[i]*arr[i-1];
         s1=s1+arr[i];
         fin+=sum;


     }
    cout << fin << endl  ;
    }
}
