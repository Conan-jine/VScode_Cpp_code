#include <iostream>
using namespace std;

unsigned long long k,sum=0;

void Create(int t, unsigned long long num)
{
    if(t==0)
    {
        // cout<<num<<endl;
        if(num%k==0)    sum++;
        return;
    }
    for(int i=1;i<7;i++)
    {
        Create(t-1,num*10+i);
    }
}

int main()
{
    int n;
    cin>>n>>k;
    Create(n,0);
    cout<<sum<<endl;
    return 0;
}