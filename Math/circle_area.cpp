#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    double n;
    while(cin>>n)
    {
        printf("%.3lf\n",n*n*n*3.1415927*4/3.0);
    }
    return 0;
}