#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    double num;
    cin>>num;
    if(num>=90) printf("4.0\n");
    else if(num>=60)    printf("%.1lf\n",4.0-(90-num)*0.1);//cout<<4.0-(90-num)*0.1<<endl;
    else if(num<60)
    {
        num=int(sqrt(num)*10);
        if(num>=60) printf("%.1lf\n",4.0-(90-num)*0.1);//cout<<4.0-(90-num)*0.1<<endl;
        else    cout<<"0.0"<<endl;
    }
    return 0;
}