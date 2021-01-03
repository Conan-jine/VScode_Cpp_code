#include <iostream>
using namespace std;

int arr[35][35]={0};
int n;

void dfs(int x, int y)
{
    if(x<0 || y<0 || x>n+1 || y>n+1 || arr[x][y]==3 || arr[x][y]==1)  return;
    else
    {
        arr[x][y]=3;
        dfs(x-1,y);
        dfs(x,y-1);
        dfs(x+1,y);
        dfs(x,y+1);
    }
    
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)   cin>>arr[i][j];
    }
    dfs(0,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j!=1)    cout<<' ';
            if(arr[i][j]==3)    cout<<'0';
            else if(arr[i][j]==1)   cout<<'1';
            else if(arr[i][j]==0)   cout<<'2';
        }
        cout<<endl;
    }
    return 0;
}