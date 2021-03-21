#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    // freopen("data.out","w",stdout);
    int n;
    double H,realH;
    cin>>n;
    while(n--)
    {
        cin>>H>>realH;
        H-=100;
        H=H*1.8;
        if((realH-H)<H*0.1 && 0-(realH-H)<H*0.1)  cout<<"You are wan mei!"<<endl;
        else if(realH-H>0)  cout<<"You are tai pang le!"<<endl;
        else    cout<<"You are tai shou le!"<<endl;
    }
    return 0;
}