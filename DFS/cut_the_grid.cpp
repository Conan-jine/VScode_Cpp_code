#include <iostream>
using namespace std;

int n,m,sum=0,steps=0;
int arr[10][10]={0};
bool visit[10][10]={0};

void dfs(int x, int y, int num, int t)
{
    if(x<0 || y<0 || x>=n || y>=m || visit[x][y] || num>sum/2)  return;
    if(num==sum/2)
    {
        if(t>steps) steps=t;
        return;
    }
    visit[x][y]=true;
    dfs(x,y+1,num+arr[x][y],t+1);
    dfs(x+1,y,num+arr[x][y],t+1);
    dfs(x-1,y,num+arr[x][y],t+1);
    dfs(x,y-1,num+arr[x][y],t+1);
    visit[x][y]=false;
}

int main()
{
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            sum+=arr[i][j];
        }
    }
    dfs(0,0,0,0);
    cout<<steps<<endl;
    return 0;
}