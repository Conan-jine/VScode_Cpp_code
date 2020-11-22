#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
    int MAX=0,MIN=110;
    double sum=0;
    int n,num;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num);
        sum+=num;
        if(num>MAX) MAX=num;
        if(num<MIN) MIN=num;
        if(i>1) printf("%.2lf\n",double((sum-MAX-MIN)/double(i-1)));
    }
}