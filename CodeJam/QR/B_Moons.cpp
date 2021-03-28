#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int n,x,y;
    int cost=0;
    int len;
    string str;
    string::iterator it;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cost=0;
        cin>>x>>y>>str;
        for(it=str.begin();it!=str.end();it++)
        {
            if(*it=='?')
            {
                str.erase(it);
                it=str.begin()-1;
            }
        }
        len=str.size();
        for(int j=0;j<len-1;j++)
        {
            if(str[j]=='C' && str[j+1]=='J')  cost+=x;
            else if(str[j]=='J' && str[j+1]=='C')   cost+=y;
        }
        cout<<"Case #"<<i+1<<": "<<cost<<endl;
    }
    return 0;
}