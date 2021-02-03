#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

#define PI 3.141592653589793238
using std::cin;
using std::cout;
using std::endl;

int main()
{
    double distance,angle;
    std::string preci;
    while(cin>>distance>>angle>>preci)
    {
        distance+=6440;
        while(angle>180)    angle=360-angle;
        if(preci=="min")    angle/=60;
        printf("%.6lf %.6lf\n",distance*PI*angle/180,2*distance*sin(angle*PI/360)); 
    }
    return 0;
}