#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

int main()
{
    int t,n,k1,k2,w,b;
    int spaceW,spaceB;
    cin>>t;
    while(t--)
    {
        cin>>n>>k1>>k2;
        cin>>w>>b;
        if(k1>k2)   swap(k1,k2);
        spaceW=k1+(k2-k1)/2;
        spaceB=n-k2+(k2-k1)/2;
        if(spaceW>=w && spaceB>=b)  cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
    }
    return 0;
}