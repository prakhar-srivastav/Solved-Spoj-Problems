#include <iostream>


using namespace std;

void solve(int a,int d)
{
	int min=0;int temp;
	cin >> temp;
	min=temp;
	for(int i=1;i<a;i++)
	{
		cin >> temp;
		if(temp<min)
		min =temp;
	}
	int c=0;
	for(int i=0;i<d;i++)
	{
		cin >> temp;
		if(temp<=min)
		c++;
	}
	if(c>=2)
	cout << "N" << endl;
	else
	cout << "Y" << endl; 
}
int main()
{
	while(1)
	{
		int a,d;
		cin >> a >> d;
		if(a==0 && d==0)
		break;
		else
		{
			solve(a,d);
		}
	}
}