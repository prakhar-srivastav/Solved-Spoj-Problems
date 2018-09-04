#include <iostream>
using namespace std; 


void solve()
{
	int x,y,i;
	cin >> x >> y;

	if(x==y)
	{
		cout << y+(y/2)*2 << endl;
	}
	else if(y==x-2)
	{
		cout << y+(y/2)*2 +2<< endl;
	}
	else
	{
		cout << "No Number\n";
	}
	
}



int main()
{
	
	int n ;
	cin >> n;
	while(n--)
	{
		solve();
	}
}