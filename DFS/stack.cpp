#include <iostream>

using std::cin;
using std::cout;
using std::endl;
// i表示当前未进栈数，j表示栈内所有数
long long dp[20][20]={0};

long long search(int now, int out)
{
    if(dp[now][out]!=0) return dp[now][out];
    if(now==0)    return 1;
    else
    {
        if(out==0)  dp[now][out]=search(now-1,out+1);
        else    dp[now][out]=search(now,out-1)+search(now-1,out+1);
        return dp[now][out];
    }
}

int main()
{
    
    int n;
    cin>>n;
    cout<<search(n,0)<<endl;
    return 0;
}