#include <iostream>
#include <string>
using namespace std;


void solve()
{
	string exp;
	cin >> exp;
	string arr[exp.size()];
	
	int x=0;
	for(int i=0;i<exp.size();i++)
	{
		arr[x]=exp[i];
	   
	   if(arr[x]=="(")
	   {
	   	
	   }
	   else if(arr[x]==")")
	   {
	   while(arr[x-2]!="(")
	   {
	   		arr[x-3]=arr[x-3]+arr[x-1]+arr[x-2];
			x=x-2;
			arr[x]=")";
			
	   }
	   	arr[x-2]=arr[x-1];
	   	x-=2;
	   }
	   else	if(arr[ x-1]=="+" || arr[x-1]=="-" ||arr[x-1]=="*" ||arr[x-1]=="/" ||arr[x-1]=="^"  )
		{
			arr[x-2]=arr[x-2]+arr[x]+arr[x-1];
			x=x-2;
		}
	x++;
			
}
cout <<arr[x-1]<<endl;
}

int main()
{
	int tt;
	cin >> tt;
	while(tt--)
	{
		solve();
	}
}