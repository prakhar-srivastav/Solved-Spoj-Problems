#include <iostream>
#include<string>
using namespace std;
string a,b;

string add()
{
	string c="";int d,carry=0;
	int l=a.size();
	int a1=a.size()-1;
	int b1=b.size()-1;
	while(l--)
	{
		if(b1>=0)
		d=(int)(a[a1--])+(int)(b[b1--])-96+carry;
		else
		d=(int)a[a1--]-48+carry;
		if(d>9)
		{
			c=char(d%10+48)+c;
			carry=1;
		}
		else
		{
			c=char(d+48)+c;
			carry=0;
		}
		
	}
	if(carry==1)
	{
		c='1'+c;
		
	}
	return c;

		
	
	
}

		string div(string num)
{
	int d=((int(num[0])-48))/2;
	
	int l=num.size();
	
	string a="";a+=(char)(d+48);
	if(a=="0")
	a="";
	int i,r=((int(num[0])-48)%2==0)?0:10;
	
	for(i=1;i<l;i++)
	{
		d=((int(num[i])-48));
		d=r+d;
		d=d/2;
		d+=48;
		a+=char(d);
		d=((int(num[i])-48));
		if(d%2!=0)
		r=10;
		else
		r=0;
		
		
	}
	return a ;}
	

string subtract()
{
	string x=a,y=b,c="";
	int temp=a.size()-b.size();
	while(temp--)
	y="0"+y;
	
	int d;
	temp=y.size()-1;
	int i=temp;
	int p=0;
	int j;
	while(i>=0)
	{   if(p==1)
	      {
	      		j=i;
	      		while(j>=0)
	      		{
	      			if(x[j]=='0')
	      		    { x[j]='9';
					  j--;
				}
	      		    else
	      		    {
	      		    	
	      		    	x[j]--;
	      		    	
	      		    	break;
					  }
	      			
	      			
				  }
			  }
		    
		d=int(x[i])-int(y[i]);
		if(d>=0)
		{
			p=0;
		c=char(d+48)+c;
	}
		else
		{
			d=d+10;
		    c=char(d+48)+c;
		    p=1;
			
		}
	
	i--;
}

string c1;
for(i=0;i<c.size();i++)
{
	if(c[i]>'0')
	{
		break;
	}
}


for(i=i;i<c.size();i++)
c1=c1+c[i];
return c1;}



int main()
{
	
	int tt=10;
	while(tt--)
	{
		cin >>a>>b;
		cout<<div(add())<<endl;
		if(a==b)
		cout<< 0<<endl;
		else
		cout<<div(subtract())<<endl;
	}
}