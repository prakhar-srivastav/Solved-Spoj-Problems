#include <iostream>
#include <string>
#include <vector>
using namespace std ;

void solve()
{

vector <int > v;
    string a,b;
    cin >> a >> b ;
    int n[b.size()];
    if (b.size()==1)
    {
        n[0]=0;
    }
    else
    {
        int j =0;
        n[0]=0;
        for(int i=1 ; i<b.size();i++)
        {
            if(b[i]!=b[j])
            {
                if(j==0)
                {
                    n[i]=0;
                }
                else
                {
                  while(j!=0)
                  {
                      j=n[j-1];
                      if(b[i]==b[j])
                      {
                          n[i]=j+1;
                          j++;
                          break;
                      }
                      if(j==0)
                        n[i]=0;
                  }
                }

            }
            else
            {
                n[i]=j+1; j++ ;

            }
        }
    }

    int x=0;
    for(int i=0;i<a.size();i++)
    {

        if(a[i]==b[x])
        {
            x++;
            if(x==b.size())
            {
                v.push_back(i-b.size()+2);
                x=0;
            }

        }
        else{
           if(x!=0){
             x=n[x-1];
            i--;
           }

        }
    }

    if(v.size()==0)
        cout << "Not Found\n\n";
    else
    {
        cout << v.size() << endl;
        for(int i=0 ;i<v.size();i++)
        cout << v[i] << " ";
    cout << endl << endl;
    }
}
int main()
{

    int t;
    cin >> t;
    while(t--) solve ();
}
