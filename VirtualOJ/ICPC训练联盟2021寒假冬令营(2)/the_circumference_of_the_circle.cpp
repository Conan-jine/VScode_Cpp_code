#include <iostream>
#include <iomanip>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

struct point
{
    double x,y;
};

int main()
{
    point a,b,c;
    double x1,x2,x3,d,p,s;
    while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y)
    {
        x1=sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
        x2=sqrt(pow(b.x-c.x,2) + pow(b.y-c.y,2));
        x3=sqrt(pow(a.x-c.x,2) + pow(a.y-c.y,2));
        p=(x1+x2+x3)/2;
        s=sqrt(p*(p-x1)*(p-x2)*(p-x3));
        d=x1*x2/(s/x3/0.5);
        cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(2)<<3.141592653589793*d<<endl;
    }
    return 0;
}