#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n,cnt=0;
    int temp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        cnt+=temp%2;
    }
    cout<<cnt<<' '<<n-cnt<<endl;
    return 0;
}