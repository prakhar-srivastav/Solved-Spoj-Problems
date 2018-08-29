#include <iostream>
using namespace std;

int reverse(int n)
{
	int r=0;
	while(n!=0)
	{
		r=r*10+n%10;
		n=n/10;
	}
	return r;
}
 int main()
 {
 	int tt,a,b;
 	cin >> tt;
 	while(tt--)
 	{
 		cin >> a >> b;
 		cout << reverse(reverse(a)+reverse(b))<< endl;
	 }
 	
 }