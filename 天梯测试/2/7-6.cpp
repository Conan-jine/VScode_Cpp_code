#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n,even=0,temp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        if(temp%2==0)   even++;
    }
    cout<<n-even<<' '<<even<<endl;
    return 0;
}