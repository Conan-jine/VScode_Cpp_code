#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n,m,x,y;
    unsigned long long dp[22][22]={0};
    int arr[22][22]={0};
    int xarr[9]={-1,-2,-2,-1,1,2,2,1};
    int yarr[9]={-2,-1,1,2,2,1,-1,-2};
    cin>>n>>m>>x>>y;
    x++;y++;n++;m++;
    dp[0][1]=1;
    arr[x][y]=1;
    for(int i=0;i<8;i++)    if(x+xarr[i]>0 && y+yarr[i]>0 && x+xarr[i]<=n && y+yarr[i]<=m)  arr[x+xarr[i]][y+yarr[i]]=1;
    for(int i=1;i<=n;i++)   for(int j=1;j<=m;j++)   if(arr[i][j]!=1)    dp[i][j]=dp[i-1][j]+dp[i][j-1];
    cout<<dp[n][m]<<endl;
    return 0;
}