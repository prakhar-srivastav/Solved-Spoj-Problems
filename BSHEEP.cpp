#include <iostream>
using namespace std ;
#include <algorithm>
#include <stack>
#include <stdio.h>
#include <math.h>
#include <utility>

int arr[100007];

struct points
{
 double first ,second;
 int pos;
};
stack < struct points > q ;

struct points point[100007];
int n ;
struct points pref ;
double dis(struct points p , struct points p1)
{
    int x0,x1,y0,y1;
    x0=p.first;
    y0=p.second;
    x1=p1.first;
    y1=p1.second;
    return ((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));

}
int orientation( struct points p0, struct points p1, struct points p2)
{
    int x0,x1,x2,y0,y1,y2;
    x0=p0.first;
    y0=p0.second;
    x1=p1.first;
    y1=p1.second;
    x2=p2.first;
    y2=p2.second;

    int val = (x2-x0)*(y2-y1)-(y2-y0)*(x2-x1);
    if(val==0)
    {
       return 0;
    }
    else if(val>0)
    {
        return 1;
    }
    else
    {
        return -1;
    }


}
bool compare(struct points p1, struct points p2)
{

if (p1.first==p2.first && p2.second==p1.second)
    return p1.pos>p2.pos;
else
{

        int val = orientation(pref,p1,p2);
    if(val==1)
        return 1 ;
    else if(val==-1)
        return 0 ;
    else
    {
        if(dis(pref,p2)>dis(pref,p1))
            return 1;
        return 0;
    }
}

}
struct points nex( )
{
    struct points p1= q.top();
    q.pop();
    struct points res=q.top();
    q.push(p1);
    return res;

}

void solve()
{


    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        double p,q;
        scanf("%lf%lf",&p,&q);
        point[i].first=p;
        point[i].second=q;
        point[i].pos=i;
    }
    int temp1=1;
    for(int i=1;i<=n;i++)
    {

        if(point[i].second< point[temp1].second || (point[i].second== point[temp1].second && point[i].first<point[temp1].first) )
        {
            temp1=i;
        }

    }
    int gear2;
    int gear=1;
    for(int i=1;i<=n;i++)
    {
        if(i!=temp1 && point[i].first==point[temp1].first && point[i].second==point[temp1].second)
        {


        }
        else
        {
            if(i==temp1) gear2=temp1;
            point[gear++]=point[i];
        }
    }
    n=gear-1;
    temp1=gear2;

    struct points p1=point[temp1];
    point[temp1]=point[1];
    point[1]=p1;
    pref=point[1];


    sort(point+1,point+n+1,compare);

    int temp=n;
    n=2;

   if(temp >2)
   {
        for(int i=2;i<temp;i++)
    {
        if(orientation(pref,point[i],point[i+1])==0)
        {

        }
        else
        {
            point[n++]=point[i];
        }

    }
   }
   else
   {
       if(temp==1) n=1;
   }

   point[n]=point[temp];

   if(n==1)
    {
        printf("0.00\n");
        printf("1");
    }
    if(n==2)
    {
        printf("%.2lf\n",2*sqrt(dis(point[1],point[2])));
        printf("%d %d",point[1].pos,point[2].pos);
    }
    if(n>=3)
    {


        q.push(point[1]);
        q.push(point[2]);
        q.push(point[3]);
        for(int i=4;i<=n;i++)
        {
            while(orientation(nex(),q.top(),point[i])!=1)
            {
                q.pop();

            }
            q.push(point[i]);
        }

        double cir=0;
        struct points a1=q.top();
        q.pop();
        int xa=1;
        arr[xa++]=a1.pos;
        cir+=sqrt(dis(pref,a1));
        while(1)
        {
            if(q.empty()) break ;
            struct points a2 = q.top();
            q.pop();
            cir+=sqrt(dis(a2,a1));
            a1=a2;
            arr[xa++]=a2.pos;
        }
        printf("%0.2lf\n",cir);
        for(int i=xa-1;i>=1;i--)
        {
            printf("%d ",arr[i]);
        }


    }
 printf("\n");
}

int main()
{

    int t ;
    scanf("%d",&t);
    while(t--)
    solve();
}
