#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n,sum,front,back;
    cin>>n;
    front=0;
    while(n--)
    {
        cin>>back;
        if(back>front)  sum+=back-front;
        front=back;
    }
    cout<<sum<<endl;
    return 0;
}