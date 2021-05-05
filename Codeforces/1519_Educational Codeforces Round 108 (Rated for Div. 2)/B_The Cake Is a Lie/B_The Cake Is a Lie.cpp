#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int times;
    int a,b,c;
    cin>>times;
    while(times--)
    {
        cin>>a>>b>>c;
        if(c!=a*b-1)    cout<<"NO"<<endl;
        else    cout<<"YES"<<endl;
    }
    return 0;
}