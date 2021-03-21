#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::ios;

int main()
{
    double H;
    cin>>H;
    H-=100;
    H=H*1.8;
    cout<<setiosflags(ios::fixed)<<std::setprecision(1)<<H<<endl;
    return 0;
}