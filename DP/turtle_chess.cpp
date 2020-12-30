#include <iostream>
#include <string>
using namespace std;

int n,m;
int arr[400]={0};
int steps[5]={0};
int dp[400]={0};
int sum=0;

void dfs(int loc, int num)
{
    
    num+=arr[loc];
    if(num<=dp[loc])    return;
    else    dp[loc]=num;
    cout<<num<<endl;
    if(loc==n-1)
    {
        if(num>sum) sum=num;
        return;
    }
    for(int i=0;i<m;i++)
    {
        if(steps[1]>0)
        {
            steps[1]--;
            dfs(loc+1,num);
            steps[1]++;
        }
        if(steps[2]>0)
        {
            steps[2]--;
            dfs(loc+2,num);
            steps[2]++;
        }
        if(steps[3]>0)
        {
            steps[3]--;
            dfs(loc+3,num);
            steps[3]++;
        }
        if(steps[4]>0)
        {
            steps[4]--;
            dfs(loc+4,num);
            steps[4]++;
        }
    }
    return;
}

int main()
{
    int num;
    cin>>n>>m;
    for(int i=0;i<n;i++)    cin>>arr[i];
    for(int i=0;i<m;i++)
    {
        cin>>num;
        steps[num]++;
    }
    dfs(0,0);
    cout<<sum<<endl;
    return 0;
}