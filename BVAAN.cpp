#include <iostream>
#include <string>


using namespace std;
int min(int a,int b)
{
	return (a<b)?a:b;
}

int max(int a,int b)
{
	return (a>b)?a:b;
}

 void solve()
 {
 	int temp;
 	int a,b,i,j,k,final=0;
 	string a1,b1;
 	cin >> a1 >> b1;
 	a=a1.size();
 	b=b1.size();
 	int n;
 	cin >> n;
 	int lis[a+1][b+1][n+1];
 	for(i=0;i<a+1;i++)
 	{
 		for (k=0;k<n+1;k++)
 		{
 			lis[i][0][k]=0;
		 }
		 
	 }
 	for(j=0;j<b+1;j++)
 	{
 		for (k=0;k<n+1;k++)
 		{
 			lis[0][j][k]=0;
		 }
	 }
 	
 
 	for(i=1;i<a+1;i++)
 	{
 		for(j=1;j<b+1;j++)
 		{
 			if(a1[i-1]==b1[j-1])
 			{
 				 lis[i][j][0]=lis[i-1][j-1][0]+1;
 				 int x= min(n,lis[i][j][0]);
 				  temp=lis[i-1][j-1][0];
 				 lis[i-1][j-1][0]=0;
 				 for(k=1;k<=x;k++)
 				 {
 				 	
 				 	lis[i][j][k]=max(max(lis[i-1][j][k],lis[i][j-1][k]),max(lis[i-1][j-1][k],lis[i-1][j-1][k-1]+int(b1[j-1])));
 				 }
 				 if(x==lis[i][j][0])
 				 {
 				 for(k=x+1;k<=n;k++)
 				 lis[i][j][k]=0;
 			}
 			lis[i-1][j-1][0]=temp;
 				
		}
			 else
			 {
			 	
 				 lis[i][j][0]=max(lis[i-1][j][0],lis[i][j-1][0]);
			 	 temp=lis[i][j][0];
 				 lis[i][j][0]=0;
 				 for(k=1;k<=n;k++)
 				 {
 				 	lis[i][j][k]=max(lis[i-1][j][k],lis[i][j-1][k]);
 				 }
 				lis[i][j][0]=temp;
	 		 }
	 			 final=max(final,lis[i][j][n]);
	 		 
	 }}
 	
 
 	
 final=(final>=97*n)?final:0;
 	cout << final << endl;
 	
 	
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