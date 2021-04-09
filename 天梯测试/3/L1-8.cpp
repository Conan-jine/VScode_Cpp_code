#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int n;
    char c;
    string str;
    cin>>n>>c;
    getchar();
    getline(cin,str);
    int len=str.size();
    if(len>n)   for(int i=len-n;i<len;i++)  cout<<str[i];
    else if(len==n) cout<<str<<endl;
    else
    {
        for(int i=0;i<n-len;i++)    cout<<c;
        cout<<str<<endl;
    }
    return 0;
}