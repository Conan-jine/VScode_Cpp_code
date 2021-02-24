#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;

int v[30],w[30],dp[30000];

int main()
{
    int space,n;
    cin>>space>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
        w[i]*=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=space;j>=0;j--)
        {
            if(j>=v[i]) dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[space]<<endl;
    return 0;
}