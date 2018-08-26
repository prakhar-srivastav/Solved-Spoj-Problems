#include <iostream>
#include <string>
using namespace std;


int count (string n)
{
	
		
		int a=0,b=1;
		int c=a+b;
		int i;
		for(i=0;i<n.size();i++)
		{
			c=a+b;
			a=b;b=c;
		}
		
		return c;
		
	}


int main()
{
string str;
cin >> str;
	string temp="";
int l=str.size(),i;
int c=0;
while(str!="0")
{

for(i=0;i<l;i++)
{
	
	if(str[i]=='0')
	{
		if(temp=="")
		{
			c=0;
			break;
		}
		else
		{
			if(c==0)
			c+=count(temp.substr (0,temp.size()-1));
			else
			c*=count(temp.substr (0,temp.size()-1));
			temp="";
			
		}}
		else if(str[i]=='1')
		{
			if(i==l-1)
			{
				
				temp+=str[i];
				if(c==0)
				c+=count(temp);
			    else
			    c*=count(temp);
				break;
			}
			else
			{
				temp+=str[i];
			}
		
		}
		else if(str[i]=='2')
		{
			if(i==l-1)
			{
				temp+=str[i];
				if(c==0)
				c+=count(temp);
			    else
			    c*=count(temp);
				break;
			}
			else
			{
				temp+=str[i];
			}
		
			
		}
		else if(str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6')
		{
			
				temp+=str[i];
				if(c==0)
				c+=count(temp);
			    else
			    c*=count(temp);
				temp="";
			
		}
		else 
		{
			
			if( i==0 || str[i-1]!='2')
			{
				temp+=str[i];
				if(c==0)
				c+=count(temp);
			    else
			    c*=count(temp);
				temp="";
			}
			else
			{if(c==0)
				c+=count(temp);
			    else
			    c*=count(temp);
				temp="";
				
			}
			
		}
		}
		
	
	cout <<  c <<endl;
	cin >> str;
c=0,l=str.size();
temp="";
	

}
}



