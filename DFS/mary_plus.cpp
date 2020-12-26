#include <iostream>
using namespace std;

int n,sum=0;
bool trap[1000]={0};

void dfs(int loc)
{
    // cout<<"loc="<<loc<<endl;
    if(loc>n)   return;
    else if(loc==n)
    {
        sum++;
        return;
    }
    else if(trap[loc])  return;
    else
    {
        dfs(loc+1);
        dfs(loc+2);
        return;
    }
}

int main()
{   
    int m,num;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>num;
        trap[num]=true;
    }
    dfs(1);
    cout<<sum<<endl;
    return 0;
}