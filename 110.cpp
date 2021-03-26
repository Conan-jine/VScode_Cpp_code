#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    double res,num;
    string arr;
    cin>>arr;
    string::iterator it=arr.begin();
    while(*it!='.') it++;
    for(it--,num=1;;it--,num*=2)
    {
        res+=(*it-'0')*num;
        if(it==arr.begin()) break;
    }
    while(*it!='.') it++;
    for(it++,num=0.5;it!=arr.end();it++,num*=0.5)
    {
        res+=(*it-'0')*num;
    }
    cout<<res<<endl;
    return 0;
}
