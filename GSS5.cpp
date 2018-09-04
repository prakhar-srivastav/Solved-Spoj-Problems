#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std ;

const int inf = 100000000;
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


     nil= new struct node ;
     nil->l=nil->r=nil;
     nil->sum=0;
     nil->prior=-1;
     nil->size=0;
     nil->key=0;
     nil->pref=-inf,nil->suff=-inf;
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
     it->update();
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
 int pref(struct node *&temp , int i , int j)
  {
      struct node *t1=nil;
	 struct node *t2=nil;
	 struct node *t3=nil;
	 struct node *t4=nil;
	 split(temp,t1,t2,i);
	 split(t2,t4,t3,j+1-i);
	 int a= t4->pref;
	 struct node *x=nil;
	 merge(x,t4,t3);
	 merge(temp,t1,t2);
	 return a;
  }
   int maxs(struct node *&temp , int i , int j)
  {
      struct node *t1=nil;
	 struct node *t2=nil;
	 struct node *t3=nil;
	 struct node *t4=nil;
	 split(temp,t1,t2,i);
	 split(t2,t4,t3,j+1-i);
	 int a= t4->maxs;
	 struct node *x=nil;
	 merge(x,t4,t3);
	 merge(temp,t1,t2);
	 return a;
  }
  int sum(struct node *&temp , int i , int j)
  {
      struct node *t1=nil;
	 struct node *t2=nil;
	 struct node *t3=nil;
	 struct node *t4=nil;
	 split(temp,t1,t2,i);
	 split(t2,t4,t3,j+1-i);
	 int a= t4->sum;
	 struct node *x=nil;
	 merge(x,t4,t3);
	 merge(temp,t1,t2);
	 return a;
  }
   int suff(struct node *&temp , int i , int j)
  {
      struct node *t1=nil;
	 struct node *t2=nil;
	 struct node *t3=nil;
	 struct node *t4=nil;
	 split(temp,t1,t2,i);
	 split(t2,t4,t3,j+1-i);
	 int a= t4->suff;
	 struct node *x=nil;
	 merge(x,t4,t3);
	 merge(temp,t1,t2);
	 return a;
  }
  void query(struct node *&temp, int x1, int y1 , int x2 , int y2)
  {
      int res;

      if(x1==x2 && y1==y2)
      {
        res= maxs(temp,x1,y2);
      }
      else
      {

      if(x2>y1)
      {
         res= suff(temp,x1,y1)+pref(temp,x2,y2) ;
         if(y1 <=x2-2 ) res+=sum(temp,y1+1,x2-1);

      }
      else if ( x2 == y1 )
      {
          res=   sum(temp,y1,x2)  ;
          if(x1<=y1-1) res+= max(0,suff(temp,x1,y1-1));
          if( x2 <= y2-1) res+=max(0,pref(temp,x2+1,y2));

      }
      else
      {
          if(x1==x2)
          {
              res= max(maxs(temp,x1,y1), max(0,suff(temp,x1,y1-1)) + sum(temp,y1,y1) + max(0,pref(temp,y1+1,y2)) );
          }
          else if(y1==y2)
          {

              res= max(maxs(temp,x2,y2), max(0,pref(temp,x2+1,y2)) + sum(temp,x2,x2) + max(0,suff(temp,x1,x2-1)) );
          }
          else
          {
              int mm,nn;
              mm=max(0,pref(temp,x2+1,y2)) + sum(temp,x2,x2) + max(0,suff(temp,x1,x2-1));
              nn=max(0,suff(temp,x1,y1-1)) + sum(temp,y1,y1) + max(0,pref(temp,y1+1,y2));
              res=max(mm,nn);
              res=max(res,maxs(root,x2,y1));
          }
      }
      }
      cout << res << endl;
  }
 void solve()
 {


  init();
      int n ;
      cin >> n;
      for(int i=1;i<=n;i++)
      {
          int a ;
          cin >> a;
          insert(root , a,i-1);
      }

      int x1,y1,x2,y2 ;
      cin >> n;
      while(n--)
      {
          cin >> x1 >> y1 >> x2 >> y2;
     query(root,x1-1,y1-1,x2-1,y2-1);

  }
 }

 int main()
 {

 srand(time(NULL));
     int t;
     cin >> t;
     while(t--)
     {
         solve();
     }
 }
