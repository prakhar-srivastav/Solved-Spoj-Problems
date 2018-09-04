#include <cstdio>
#include <iostream>
#define ll long long
#define MAX 100005
using namespace std;

struct seg
{
    ll a ;
    ll flag ;
};
seg tree[MAX*4];
void init( ll n)
{
    ll i;
    for( i=1;i<n;i=i*2)
    {

    }
    i=i*2-1;

    for(ll j =1 ;j<=i;j++)
    {
        tree[j].a=0;
        tree[j].flag=0;
    }


}
ll readint1()
{
    ll n =0;
    char c= getchar();
    while(c>='0' && c<='9')
    {
        n=n*10 + c - '0';
        c=getchar();

    }
    return n ;
}

void refresh(ll node,ll a,ll b)
{

        if ( a != b ) {
            tree[ node * 2 ].flag += tree[ node ].flag;
            tree[ node * 2 + 1 ].flag += tree[ node ].flag;
        }
       tree[node].a+=tree[node].flag*(b-a+1);
       tree[node].flag=0;
        }

void update(ll pos , ll l , ll r , ll i , ll j, ll c)
{
    if(i>r || j<l || i>j)
    {
        refresh(pos,i,j);
        return ;
    }
    if(  j<=r && i>=l && i<= j)
    {
        tree[pos].flag=tree[pos].flag+c ;
        refresh(pos,i,j);
        return;
    }
    refresh(pos,i,j);
    update(pos*2,l,r,i,(i+j)/2,c);
    update(pos*2+1,l,r,(i+j)/2+1,j,c);
     if ( i != j ) {
        tree[pos].a=tree[pos*2].a+tree[pos*2+1].a;
    }

}

ll query(ll pos , ll l ,ll r, ll i, ll j)
{
    refresh(pos,i,j);
 if(l==i && r==j)
 {
     return(tree[pos].a);
 }
  if ( r <= ( i+j ) / 2 ) {
        return query( pos * 2, l,r, i, (i+j)/2 );
    }
    if ( l > ( i+j ) / 2 ) {
        return query( pos * 2 + 1, l, r ,( i+j ) / 2 + 1, j );
    }
    return query(pos*2,l,(i+j)/2,i,(i+j)/2 ) + query( pos * 2 + 1, (i+j )/2+1, r,(i+j)/2+1,j );
}
void solve()
{
    ll n ,q ;
    scanf("%lld%lld",&n,&q);

    init (n);
    while(q--)
    {
        ll x;
        scanf("%lld",&x);

        if(x==0 )
        {
            ll a,b ,c;
            scanf("%lld%lld%lld",&a,&b,&c);
            update(1,a,b,1,n,c);

        }
        else
        {
            ll e,f ;
            scanf("%lld%lld",&e,&f);
            ll y =query(1,e,f,1,n);
            printf("%lld\n",y);

        }
    }
}

int main()
{
   ll t ;
   scanf("%lld",&t);
   while(t--)
   {
       solve();
   }


}
