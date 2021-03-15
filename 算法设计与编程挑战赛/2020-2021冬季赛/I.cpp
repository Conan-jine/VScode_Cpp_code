#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    double n,origN;
    int x,y;
    cin>>n>>x>>y;   
    origN=n;
    for(int i=1;i<=y;i++)
    {
        n=n*2/3.0;
        if(i==x)    n+=origN/2.0;
        if(n<origN/32.0)
        {
            printf("N0!\n%d %.6lf",i,n);
            return 0;
        }
    }
    printf("YE5!\n%.6lf",n);
    return 0;
}