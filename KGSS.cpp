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
int min(int a,int b)
{

    if(a<b) return a ;
    return b;
}
struct  node
{

    int size, key,best,best2,prior ;

    struct node *l,*r ;
    void update()
    {

        size = 1+l->size+ r->size ;
        best=max(key,max(l->best,r->best));
        int n= min(key,min(l->best,r->best));
        best2=key+l->best+r->best-n-best;
        best2=max(best2,max(l->best2,r->best2));

    }
};

 struct node *root, * nil;
 void init()
 {

    srand(time(NULL));
     nil= new struct node ;
     nil->l=nil->r=nil;

     nil->prior=-1;
     nil->size=0;
     nil->key=-inf;
     nil->best=nil->best2=-inf;
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


  void query(struct node *&temp , int i , int j)
  {
      struct node *t1=nil;
	 struct node *t2=nil;
	 struct node *t3=nil;
	 struct node *t4=nil;
	 split(temp,t1,t2,i);
	 split(t2,t4,t3,j+1-i);
	 printf("%d\n",t4->best+t4->best2);
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
      char ch[2];
      int x,y ;
      scanf("%d",&n);
      while(n--)
      {

          scanf("%s",ch);
          if(*ch == 'U')
          {
              scanf("%d%d",&x,&y);
              replace(root,y,x-1);
          }
          else
          {

              scanf("%d%d",&x,&y);
              query(root,x-1,y-1);


      }


  }
  }
