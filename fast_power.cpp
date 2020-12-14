#include <iostream>
#include <cmath>
using namespace std;

unsigned long long n,m,k,sum;

unsigned long long fast_power(unsigned long long a,unsigned long long b)
{
    if(b==1)    return a;
    else if(b==0)   return 1;
    else if(b%2==0)
    {
        //cout<<((a%k)*(a%k))%k<<endl;
        return fast_power(((a%k)*(a%k))%k,b/2);
    }
    else
    {
        //cout<<((a%k)*(a%k))%k<<endl;
        return (fast_power(((a%k)*(a%k))%k,b/2)*(a%k))%k;
    }
}

int main()
{
    cin>>n>>m>>k;
    cout<<n<<'^'<<m<<" mod "<<k<<'='<<fast_power(n,m)%k<<endl;
    return 0;
}