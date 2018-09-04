#include <iostream>
using namespace std;
int main()
{
	unsigned long long int n ;
	cin >> n;
	int l=1;
	 while(n!=1)
	 {
	 	if(n%2==0)
	 {
	 	l=1;
	 		n/=2;
	 	}
	 	else
	 	{
	 		l=0;
	 		break;
		 }
		 
	 }
	 if(l==0)
	 cout << "NIE";
	 else
	 cout << "TAK";
	 
}