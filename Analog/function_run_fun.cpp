#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

unsigned long long dp[25][25][25]={0};

unsigned long long w(int a, int b, int c)
{
    if(a<=0 || b<=0 || c<=0)    return 1;
    if(a>20 || b>20 || c>20)    return w(20,20,20);
    if(dp[a][b][c]==0)
    {
        if(a<b && b<c)  dp[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);  
        else    dp[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    }
    return dp[a][b][c];
}

int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        if(a==b && b==c && a==-1)   break;
        printf("w(%d, %d, %d) = %lld\n",a,b,c,w(a,b,c));
    }
    return 0;
}