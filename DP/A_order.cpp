#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int dp[110][10010];
int arr[110];
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)    cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j==arr[i])   dp[i][j]=dp[i-1][j]+1;
            else if(j>arr[i])   dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i]];
            else    dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}