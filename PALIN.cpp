#include <iostream>
#include <string>
#include <math.h>

using namespace std;
int a1 , b1 ;
string increment(string num)
{
		
	int a=a1,b=b1;
	int l = num.size();
	if(l%2==0)
	{
		a=a+b;a=a/2;b=a+1;
		while(b<l){
			if(num[a]=='9')
			{
				num[a]='0';
				num[b]='0';
				a--;
				b++;
			}
			else
			{
				
				num[b]=char(int(num[b])+1);
				num[a]=char(int(num[a])+1);
			    break;
			}
		}
		
	}
	else
	{
	a=a+b;a/=2;b=a;
		while(b<l){
			if((num[a])=='9')
			{
				num[a]='0';
				num[b]='0';
				a--;
				b++;
			}
			else
			{
				if(a!=b)
				num[b]=char(int(num[b]+1));
				num[a]=char(int(num[a]+1));
			    break;
			}
		}
		
	}
	
	return num;
}

string mirror(string num)
{
	int a=a1;
	int b=b1;
	int l=num.size();
	while(b<l){
	
	num[b]=num[a];
	a--;b++;
}
return num;
}
void call()
{
	string num;
	cin >> num;
	int a,b;
   int l=num.size();
   if (l%2==0)
   {
   	a=l/2-1;a1=a;
   	b=a+1,b1=b;
   }
   else
   {
   	a=l/2-1;a1=a;
   	b=a+2;b1=b;
   }
   while(1)
   {
   	if(b==l)
   	break;
   	if(int(num[b])==int(num[a]))
   	{a--;b++;}
   	else{
   		break;
	   }
   }
   
   
   int i =0,c=0;
   for(i=0;i<l;i++)
   {
   	if(num[i]=='9')
   	c++;
   }
   
   if(c==l)
   {
   	string word="1";
   	while(c!=1)
   	{
   		c--;
   		word+="0";
	   }
	   word+="1";
   	
   	cout <<word << endl;
   	
   }
   
   else if ( b == l)
   {
   	cout << increment(num) << endl;
   }
	else
	{
		
		for(i=b;i<l;i++)
		{
			if(int(num[i])<int(num[a--]))
			break;
			else if(int(num[i])==int(num[a--]))
			continue;
			else
			{
				i=l;
				break;
			}
			
			
		}
		if(i==l)
		cout <<  increment(mirror(num)) << endl;
		else
		cout << mirror (num) << endl;
		
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		call();
	}
}