#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n,num,times,ntimes;
    cin>>n;
    while(n--)
    {
        cin>>num;
        times=num/2020;
        ntimes=num%2020;
        if(ntimes>times)    cout<<"NO"<<endl;
        else    cout<<"YES"<<endl;
    }
    return 0;
}