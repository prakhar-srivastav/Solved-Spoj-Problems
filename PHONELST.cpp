#include <stdio.h>
#include <iostream>
#include <string>
using namespace std ;
struct node
{
    struct node *ch[10];
    bool eow;

};
struct node * root ;

struct node *make()
{
    struct node *p= new node;
    p->eow=false ;
    for(int i=0;i<10;i++)
        p->ch[i]=NULL;
    return p;
}
bool insert ( string x )
{
    struct node *temp= root ;
    for(int i=0;i<x.size()-1;i++)
    {

        int n= int(x[i])-48;

        if ( temp->ch[n]!=NULL)
        {
            temp = temp->ch[n];


        }
        else
        {
            struct node *a = make();
            temp->ch[n]=a;
            temp=temp->ch[n];

        }
        if(temp->eow==true) return false ;
    }
   int n= int(x[x.size()-1])-48;
    if(temp->ch[n]==NULL)
    {
        struct node *a = make();
            temp->ch[n]=a;
            temp=temp->ch[n];
             temp->eow=true;
            return true ;
    }
    else
    {


        return false;
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    cin >> t;



    while(t--)
    {
        root = make();
        int n ;

    cin >> n;
    int temp=n;

    int count=0;

    while(n--)
    {


        string x ;
    cin >> x;

     bool val =insert( x ) ;
     if(val==false )

     {

         cout << "NO\n";
         break;
     }
     else
        count++;

    }
    string waste;
for(int i=1 ;i<=temp-count-1;i++) cin >> waste;
    if(count==temp)
    {
        cout << "YES\n";
    }


    }

}
