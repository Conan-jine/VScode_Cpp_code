#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;

int dp[32][20010];
int arr[32];

int main()
{
    int n,space;
    cin>>space>>n;
    for(int i=1;i<=n;i++)    cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=space;j>=0;j--)
        {
            if(j>=arr[i])    dp[i][j]=max(dp[i-1][j-arr[i]]+arr[i],dp[i-1][j]);
            else    dp[i][j]=dp[i-1][j];
        }
    }
    cout<<space-dp[n][space]<<endl;
    return 0;
}