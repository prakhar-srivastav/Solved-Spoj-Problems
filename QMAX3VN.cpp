#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std ;
const int inf = 0x7f7f7f7f;

int max(int a , int b )
{
    if(a>b) return a;
    return b ;
}
struct node
{
    struct node *l,*r;
    int key,best,size,priority;
    void update()
    {
        size=1+l->size+r->size;
        best=max(l->best,r->best);
        best=max(key,best);
    }
};

struct node *nil ,*ptr;
void init()
{
    srand(time(NULL));
    nil= new struct node ;
    nil->r=nil;
    nil->l=nil;
    nil->size=0;
    nil->key=nil->best=-inf;
    nil->priority=-1;
    ptr=nil;

}


int query(struct node *temp , int l, int r , int i , int j)
{

    if(temp == nil || l>=j || r <=i ) return -inf ;
    if( l>=i &&r<=j) return temp->best;
    int ref =-inf;
    ref=max(query(temp->r,l+temp->l->size+1,r,i,j),query(temp->l,l,l+temp->l->size,i,j));
    if(l + temp->l->size >= i && l +temp->l->size < j) ref=max(ref,temp->key);
    return ref ;
}
struct node *rotate(struct node *p, struct node *q)
{
    if(p->l == q)
    {

        p->l=q->r;
        q->r =p;
    }
    else
    {
        p->r=q->l;
        q->l=p;
    }
    p->update();
    q->update();
        return q;
}
struct node *insert(struct node *temp, int key, int pos)
{
    if(temp==nil)
    {
        struct node *arr=new struct node ;
        temp=arr;
        temp->l=nil,temp->r=nil;
        temp->size=1;
        temp->key=temp->best=key;
        temp->priority=rand();
        return temp;
    }
    if(pos <= temp->l->size)
    {
        temp->l=insert(temp->l,key,pos);
        if(temp->l->priority > temp->priority)
            temp=rotate(temp,temp->l);

    }
    else
    {
        temp->r=insert(temp->r,key,pos-temp->l->size-1);
        if(temp->r->priority > temp->priority)
            temp=rotate(temp,temp->r);
    }
    temp->update();
    return temp;
}
int main()
{
    init();
    int n;
    scanf("%d",&n);

    while(n--)
    {

        int x,y;
        char ch[2] ;
        scanf("%s%d%d",ch,&x,&y);
        if(*ch=='Q')
            printf("%d\n",query(ptr,0,ptr->size,x-1,y));
            else
            ptr=insert(ptr,x,y-1);
    }
}


