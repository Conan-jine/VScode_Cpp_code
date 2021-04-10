#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int all,times;
    cin>>all>>times;
    if(times%2) cout<<1;
    else    cout<<0;
    while(times)
    {
        if(times%2==0)  all=all<<1;
        times--;
    }
    cout<<' '<<all<<endl;
    return 0;
}