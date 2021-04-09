#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int n,a,b;
    string name;
    cin>>n;
    while(n--)
    {
        cin>>name>>a>>b;
        if( !(a>=15 && a<=20 && b>=50 && b<=70) )   cout<<name<<endl;
    }
    return 0;
}