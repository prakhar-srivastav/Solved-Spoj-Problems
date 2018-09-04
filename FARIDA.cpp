#include <iostream>
#define ll long long int
using namespace std;
int c=1;
ll arr[10001];
ll lis[10001];
void solve(){
    ll n;
    cin >> n;
    for(ll i=1;i<=n;i++)
        cin >> arr[i];
        arr[0]=0;
      lis[0]=0;
      lis[1]=arr[1];
    for(ll i=2;i<=n;i++)
    {
        lis[i]=(lis[i-2]+arr[i]>lis[i-1])? lis[i-2]+arr[i]: lis[i-1];  }
        cout << "Case " << c <<": "<< lis[n]<<endl;
        c++;
}
int main()
{

    int t;
    cin >> t;
    while(t--)
        solve();
}
