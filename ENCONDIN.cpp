#include <iostream>
#include <stdio.h>
#include  <cstdio>
#include <string>
using namespace std ;
void print(char ch)
{

    if(ch=='1') printf("11");
    else printf("%c",ch);
}
 int main()
 {

     string x ;
     while(getline(cin,x))
     {
       if (x=="")
      printf("\n");
       else
       {



             int count1=0;
             int pos=-1 ;
            for(int i=0;i<x.size();i++)
            {

                if (i<x.size()-1 && (x[i]==x[i+1]) )
               {

                   count1=0;
                   while(x[i]==x[i+1] )
                   {
                       count1++,i++;
                       if(count1==8) break;
                   }




                  printf("%d" ,count1+1);
                  printf("%c",x[i]);


               }
               else
               {

                  printf("1");


                   while(1)
                   {
                       if(x.size() == i+1)
                       {
                           print(x[i]);i++;  break;
                       }
                       if(x[i]==x[i+1]) break;
                       else print(x[i]),i++;

                   }i--;

                   printf("1");
               }
            }
            printf("\n");
       }
     }
 }

