#include <iostream>
#include <cstdlib>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

struct point
{
    double x,y;
};

int main()
{
    point a,b,c,d,e;
    while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y)
    {
        if(a.x==c.x && a.y==c.y)    std::swap(a,b);
        if(a.x==d.x && a.y==d.y)
        {
            std::swap(a,b);
            std::swap(c,d);
        }
        if(b.x==d.x && b.y==d.y)    std::swap(c,d);
        e.x=d.x+a.x-c.x;
        e.y=d.y+a.y-c.y;
        printf("%.3lf %.3lf\n",e.x,e.y);
    }
    return 0;
}