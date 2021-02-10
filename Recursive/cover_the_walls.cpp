#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int dp[1000010];

int main()
{
    dp[0]=dp[1]=1;
    dp[2]=2;
    dp[3]=5;
    int num;
    cin>>num;
    for(int i=4;i<=num;i++)
    {
        dp[i]=2*dp[i-1]+dp[i-3];
        dp[i]%=10000;
    }
    cout<<dp[num]<<endl;
    return 0;
}