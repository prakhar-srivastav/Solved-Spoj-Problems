#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std ;

const int inf = 0x7f7f7f7f;
int max(int a, int b)
{
    if(a>b) return a;
    return b ;
}
struct  node
{

    int size ,maxs , pref,suff, key ,sum ,prior ;

    struct node *l,*r ;
    void update()
    {

        size = 1+l->size+ r->size ;
        sum=key+l->sum+r->sum;

        pref= max(l->pref, l->sum+key+ max(0,r->pref));
        suff= max(r->suff, r->sum+key+ max(0,l->suff));
        maxs= max(max(l->maxs,r->maxs) , key+ max(0,r->pref)+ max(0,l->suff));
    }
};

 struct node *root, * nil;
 void init()
 {

     srand(time(NULL));
     nil= new struct node ;
     nil->l=nil->r=nil;
     nil->sum=0;
     nil->prior=-1;
     nil->key=0;
     nil->pref=0,nil->suff=0;
     nil->maxs=-inf;
     root = nil ;
 }
 void split(struct node *t, struct node *&l, struct node *&r, int pos) {
	if (t==nil){
		l = r = nil;
		return;
	}
	else if (pos <= t->l->size)
		split(t->l, l, t->l, pos), r = t;
	else
		split(t->r, t->r, r, pos-t->l->size - 1), l = t;

	t->update();
}
void merge(struct node *&t,struct  node *l, struct node *r) {
	if (l == nil)
		t = r;
	else if (r== nil)
		t = l;
	else if (l->prior > r->prior)
		merge(l->r, l->r, r), t = l;
	else
		merge(r->l, l, r->l), t = r;
	t->update();
}
 void insert(struct node *&temp, int key , int pos)
 {
     struct node *it = new struct node ;
     it->size=1;
     it->prior=rand();
     it->l=it->r=nil;
     it->key=key;
     struct node *t1=nil;
	 struct node *t2=nil;
	split(temp,t1,t2,pos);
	merge(temp,t1,it);
	merge(temp,temp,t2);
 }

  void remove( struct node *&temp, int pos)
  {
      struct node *t1=nil;
	 struct node *t2=nil;
	 struct node *t3=nil;
      split(temp,t1,t2,pos);
      split(t2,t2,t3,1);
      merge(temp,t1,t3);
  }
  void replace ( struct node *&temp, int key,int pos)
  {
      insert(temp,key,pos);
      remove(temp,pos+1);
  }
  void query(struct node *&temp , int i , int j)
  {
      struct node *t1=nil;
	 struct node *t2=nil;
	 struct node *t3=nil;
	 struct node *t4=nil;
	 split(temp,t1,t2,i);
	 split(t2,t4,t3,j+1-i);
	 printf("%d\n",t4->maxs);
	 struct node *x=nil;
	 merge(x,t4,t3);
	 merge(temp,t1,t2);
  }
 int main()
  {
      init();
      int n ;
      scanf("%d",&n);
      for(int i=1;i<=n;i++)
      {
          int a ;
          scanf("%d",&a);
          insert(root , a,i-1);
      }
      int ch;
      int x,y ;
      scanf("%d",&n);
      while(n--)
{


              scanf("%d%d",&x,&y);
              query(root,x-1,y-1);

      }


  }
