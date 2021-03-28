#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int D;
    cin>>D;
    D+=2;
    if(D>7) D-=7;
    cout<<D<<endl;
    return 0;
}