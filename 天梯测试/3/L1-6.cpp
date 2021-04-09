#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string ans;

void judge(string str)
{
    if(str[0]=='A' && str[2]=='T')  ans+='1';
    else if(str[0]=='B' && str[2]=='T') ans+='2';
    else if(str[0]=='C' && str[2]=='T') ans+='3';
    else if(str[0]=='D' && str[2]=='T') ans+='4';
}

int main()
{
    string title[4];
    int n;
    cin>>n;
    while(n--)
    {
        cin>>title[0]>>title[1]>>title[2]>>title[3];
        for(int i=0;i<4;i++)    judge(title[i]);
    }
    cout<<ans<<endl;
    return 0;
}