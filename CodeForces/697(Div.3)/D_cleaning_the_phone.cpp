#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

int w[200002],val[200002];
int dp[200002];

int main()
{
    int n;
    int t,m,res=-1,realT,sumw=0;
    cin>>n;
    while(n--)
    {
        sumw=0;
        scanf("%d%d",&m,&t);
        for(int i=1;i<=m;i++)   
        {   
            scanf("%d",&w[i]);
            sumw+=w[i];
        }
        for(int i=1;i<=m;i++)   scanf("%d",&val[i]);
        realT=sumw-t;
        if(realT<0)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=realT;j>=0;j--)
            {
                if(j>=w[i]) dp[j]=dp[j-w[i]]+val[i] > dp[j] ? dp[j-w[i]]+val[i] : dp[j];
            }
        }
        cout<<dp[realT]<<endl;
    }
}