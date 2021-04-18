#include <iostream>
#include <cmath>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int s,v;
    cin>>s>>v;
    double needTime;
    needTime=double(s)/v;
    int H,M;
    H=8,M=0;
    double dM=0;
    dM-=needTime+10;
    while(dM<0)
    {
        H--;
        dM+=60;
    }
    if(H<0)    H+=24;
    M=dM;
    dM-=M;
    // if(dM==0)   M--;
    printf("%02d:%02d",H,M);
    return 0;
}