#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int EXGCD(long long A, long long B, long long &X, long long &Y)
{
    if(!B)
    {
        X=1;
        Y=0;
        return A;
    }
    int D=EXGCD(B,A%B,Y,X);
    Y-=A/B*X;
    return D;
}

int main()
{
    long long X,Y,A,B,D;
    while(cin>>A>>B)
    {
        D=EXGCD(A,B,X,Y);
        cout<<X<<' '<<Y<<' '<<D<<endl;
    }
    return 0;
}