#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned long long n,x,sum=0;
unsigned long long begin,end;

int main()
{
    cin>>n>>x;
    cin>>begin;
    if(begin>x)
    {
        sum+=begin-x;
        begin=x;
    }
    for(int i=1;i<n;i++)
    {
        cin>>end;
        if(begin+end>x)
        {
            sum+=begin+end-x;
            end-=(begin+end-x);
        }
        begin=end;
    }
    cout<<sum<<endl;
    return 0;
}