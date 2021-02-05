#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

int dp[110][1010];
int arr[110][2];
int all,n;

int main()
{
    cin>>all>>n;
    // 0表示时间，1表示价值
    for(int i=1;i<=n;i++)   cin>>arr[i][0]>>arr[i][1];
    // 对于物品1-n,如果在时间j的时候能放入，比较放入好还是不好
    for(int i=1;i<=n;i++)
    {
        for(int j=all;j>=0;j--)
        {
            if(j>=arr[i][0])    dp[i][j]=std::max(dp[i-1][j-arr[i][0]]+arr[i][1],dp[i-1][j]);
            else    dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][all]<<endl;
    return 0;
}