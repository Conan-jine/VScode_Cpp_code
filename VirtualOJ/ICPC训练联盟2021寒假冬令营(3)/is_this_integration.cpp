#include <iostream>
#include <iomanip>
#include <cmath>

#define PI 3.141592653589793

using std::cin;
using std::cout;
using std::endl;

int main()
{
    double a,x,y,z;
    while(cin>>a)
    {
        x=(1+PI/3.0-sqrt(3.0))*a*a;
        y=4*(PI/12.0+sqrt(3.0)/2-1)*a*a;
        z=4*(-PI/6.0+1-sqrt(3.0)/4)*a*a;
        cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(3)<<x<<' '<<y<<' '<<z<<endl;
    }
    return 0;
}