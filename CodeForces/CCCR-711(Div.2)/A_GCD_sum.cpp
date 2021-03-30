#include <iostream>

using std::cin;
using std::cout;
using std::endl;

long long int gcd(long long int a, long long int b)
{
    if(b==0)    return a;
    else    return gcd(b,a%b);
}

long long int digitNum(long long int num)
{
    long long int cnt=0;
    while(num>0)
    {
        cnt+=num%10;
        num/=10;
    }
    return cnt;
}

long long int t,n;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        while(gcd(n,digitNum(n))<=1)    n++;
        cout<<n<<endl;
    }
    return 0;
}