#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int red, blue, maxsub;
    int divnum,maxnum,minnum;
    int times;
    cin>>times;
    while(times--)
    {
        cin>>red>>blue>>maxsub;
        maxnum=red>blue?red:blue;
        minnum=red>blue?blue:red;
        divnum = maxnum/minnum;
        if(maxsub==0)
        {
            if(red!=blue)   cout<<"NO"<<endl;
            else    cout<<"YES"<<endl;
        }
        else
        {
            if(maxnum%minnum==0)    divnum--;
            if(divnum>maxsub)   cout<<"NO"<<endl;
            else    cout<<"YES"<<endl;
        }
    }
    return 0;
}