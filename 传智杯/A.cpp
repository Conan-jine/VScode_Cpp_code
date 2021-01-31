#include <iostream>
using namespace std;

int main()
{
    unsigned long long n,v,m,a;
    cin>>n>>v>>m>>a;
    unsigned long long N=n/m,A=a,sum=0;
    sum=(v*N+(N-1)*N/2*A)*m;
    sum+=n%m*(v+N*a);
    cout<<sum<<endl;
}